import os
import lief
import shutil

if not os.path.isfile( "/Applications/Spotify.app/Contents/Frameworks/Chromium Embedded Framework.framework/Chromium Embedded Framework" ):
    print( "Invalid Spotify instalation." )
    exit( 0 )

if os.path.isfile( "/Applications/Spotify.app/Contents/Frameworks/Chromium Embedded Framework.framework/Chromium Embedded Framework.orig" ):
    print( "Original file founded." )

    while True:
        proceed = str( input( "Do you wish to proceed? (y/n): " ) ).lower( )
        if proceed == "n":
            exit(0)
        elif proceed == "y":
            break
        
        print( "Invalid option, type y for yes or n for no" )
    
    # check if current CEF is original
    fs = os.stat( "/Applications/Spotify.app/Contents/Frameworks/Chromium Embedded Framework.framework/Chromium Embedded Framework" )
    
    if fs.st_size > 100000000:
        print( "Spotify may have been updated, we are deleting the old .orig file and keeping the new original file." )

        os.remove( "/Applications/Spotify.app/Contents/Frameworks/Chromium Embedded Framework.framework/Chromium Embedded Framework.orig" )
    else:
        print( "Spotify is already patched, let's re-patch it." )

        os.remove( "/Applications/Spotify.app/Contents/Frameworks/Chromium Embedded Framework.framework/Chromium Embedded Framework" )
        os.rename( "/Applications/Spotify.app/Contents/Frameworks/Chromium Embedded Framework.framework/Chromium Embedded Framework.orig", "/Applications/Spotify.app/Contents/Frameworks/Chromium Embedded Framework.framework/Chromium Embedded Framework" )

# swap this for your apple certificate
cert = ""

hooks = [ 
    { 
        "name": "cef_urlrequest_create",
        "symbol_name": "_cef_urlrequest_create",
        "return_type": "void*",
        "arguments": "cef_request_t* req, void* client, void* req_ctx",
        "hook_fun_body": """{
    cef_string_userfree_utf16_t url_utf16 = req->get_url( req );
	char url[ url_utf16->len + 1 ];
	url[ url_utf16->len ] = '\\0';
	
	for( int i = 0; i < url_utf16->len; i++ )
		url[ i ] = *( url_utf16->str + i );
	
	_cef_string_userfree_utf16_free( url_utf16 );

	if ( is_blacklisted(url) )
		return 0;

	return _cef_urlrequest_create( req, client, req_ctx);
}""",
        "dependency_code": """#include <string.h>

static const char *blacklist[] = {
	"https://spclient.wg.spotify.com/ads/",
	"https://spclient.wg.spotify.com/ad-logic/",
	"https://spclient.wg.spotify.com/gabo-receiver-service/",
};

static const int blacklist_len = sizeof(blacklist) / sizeof(blacklist[0]);

static inline int is_blacklisted(const char *url)
{
	for (int i = 0; i < blacklist_len; i++)
		if (strstr(url, blacklist[i]))
			return 1;
	return 0;
}

typedef struct
{
	unsigned short *str;
	size_t len;
	void *p1;
} cef_string_utf16_t;

typedef cef_string_utf16_t *cef_string_userfree_utf16_t;

typedef struct
{
	size_t s1;
	void *p1;
	void *p2;
	void *p3;
	void *p4;
} cef_base_ref_counted_t;

typedef struct
{
	cef_base_ref_counted_t base;
	void *p1;
	cef_string_userfree_utf16_t (*get_url)(void *);
} cef_request_t;"""
    } 
]

# read binary
fat_bin = lief.MachO.parse( "/Applications/Spotify.app/Contents/Frameworks/Chromium Embedded Framework.framework/Chromium Embedded Framework", config = lief.MachO.ParserConfig.deep )
binary = fat_bin.take( lief.MachO.CPU_TYPES.ARM64 )

# prepare updated .c file
file = open( "hookspot.c", "w" )
file.write( '#include <dlfcn.h>\n\n#define PATH "/Applications/Spotify.app/Contents/Frameworks/Chromium Embedded Framework.framework/Chromium Embedded Framework.orig"\n\n' )

# write dependency code
for hook in hooks:
    file.write( "{}\n\n".format( hook[ "dependency_code" ] ) )

# write default original function variables
for exp_fun in binary.exported_functions:
    # ignore custom hook prototype
    if any( hook[ "symbol_name" ] == exp_fun.name for hook in hooks ):
        continue
    
    # default prototype
    file.write( "void ( * {} )( );\n".format( exp_fun.name ) )

# padding
file.write( "\n" )

# custom hook prototypes
for hook in hooks:
    file.write( "{} ( * {} )( {} );\n".format( hook[ "return_type" ], hook[ "symbol_name" ], hook["arguments"] ) )

# write constructor
file.write( """\n__attribute__((constructor)) 
static void init()
{
	void* handle = dlopen( PATH, RTLD_NOW | RTLD_GLOBAL );\n\n""" )

# retrieve original function addresses
for exp_fun in binary.exported_functions:
    file.write( "    {} = dlsym( handle, \"{}\" );\n".format( exp_fun.name, exp_fun.name[1:] ) )

# write constructor ending and a macro to declare all our hooks
file.write( """}

#ifdef __amd64__

#define CREATE_HOOKED_FUN( f ) \\
    __attribute__((naked)) \\
	void f( ) \\
	{ \\
		asm volatile( "jmpq *%0;" \\
			     : \\
			     : "r" (_##f)); \\
	}

#elif __aarch64__

#define CREATE_HOOKED_FUN( f ) \\
	void f( ) { _##f(); }

#elif

#error Unknown architecture

#endif\n\n""" )

# define default hooks
for exp_fun in binary.exported_functions:
    # ignore custom hooks for now
    if any( hook[ "symbol_name" ] == exp_fun.name for hook in hooks ):
        continue
    
    # default hook
    file.write("CREATE_HOOKED_FUN( {} )\n".format( exp_fun.name[1:] ) )

# define custom hooks
for hook in hooks:
    file.write("""\n{} {}( {} )
{}\n""".format( hook[ "return_type" ], hook[ "name" ], hook[ "arguments" ], hook[ "hook_fun_body" ] ) )

# remove last new line
file.seek( file.tell() - 1, os.SEEK_SET )
file.truncate( )

# close file
file.close( )

# we compile our patch
os.system( "gcc -dynamiclib -o out hookspot.c" )

# rename the original file
os.rename( "/Applications/Spotify.app/Contents/Frameworks/Chromium Embedded Framework.framework/Chromium Embedded Framework", "/Applications/Spotify.app/Contents/Frameworks/Chromium Embedded Framework.framework/Chromium Embedded Framework.orig" )

# move our patch
shutil.move( "out", "/Applications/Spotify.app/Contents/Frameworks/Chromium Embedded Framework.framework/Chromium Embedded Framework" )

# now we sign the app
os.system( "codesign --force --deep --sign {} /Applications/Spotify.app".format( cert ) )

print( "Success!" )