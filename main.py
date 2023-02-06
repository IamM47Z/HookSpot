import os
import lief
import json
import shutil

file = open( "config.json" )
config = json.load( file )
file.close( )

if not os.path.isdir( config[ "path" ] ):
    print( "Invalid Spotify instalation." )
    exit( 0 )

if os.path.isfile( "{}.orig".format( config[ "cef_file" ] ) ):
    print( "Original file founded." )

    while True:
        proceed = str( input( "Do you wish to proceed? (y/n): " ) ).lower( )
        if proceed == "n":
            exit(0)
        elif proceed == "y":
            break
        
        print( "Invalid option, type y for yes or n for no" )
    
    # check if current CEF is original
    fs = os.stat( config[ "cef_file" ] )
    
    if fs.st_size > 100000000:
        print( "Spotify may have been updated, we are deleting the old .orig file and keeping the new original file." )

        os.remove( "{}.orig".format( config[ "cef_file" ] ) )
    else:
        print( "Spotify is already patched, let's re-patch it." )

        os.remove( config[ "cef_file" ] )
        os.rename( "{}.orig".format( config[ "cef_file" ] ), config[ "cef_file" ] )

# read binary
fat_bin = lief.MachO.parse( config[ "cef_file" ], config = lief.MachO.ParserConfig.deep )
binary = fat_bin.take( lief.MachO.CPU_TYPES.ARM64 )

# prepare updated .c file
file = open( "hookspot.c", "w" )
file.write( '#include <dlfcn.h>\n\n#define PATH "{}.orig"\n\n'.format( config[ "cef_file" ] ) )

# write dependency code
for hook in config[ "hooks" ]:
    file.write( "{}\n\n".format( hook[ "dependency_code" ] ) )

# write default original function variables
for exp_fun in binary.exported_functions:
    # ignore custom hook prototype
    if any( hook[ "symbol_name" ] == exp_fun.name for hook in config[ "hooks" ] ):
        continue
    
    # default prototype
    file.write( "void ( * {} )( );\n".format( exp_fun.name ) )

# padding
file.write( "\n" )

# custom hook prototypes
for hook in config[ "hooks" ]:
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
    if any( hook[ "symbol_name" ] == exp_fun.name for hook in config[ "hooks" ] ):
        continue
    
    # default hook
    file.write("CREATE_HOOKED_FUN( {} )\n".format( exp_fun.name[1:] ) )

# define custom hooks
for hook in config[ "hooks" ]:
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
os.rename( config[ "cef_file" ], "{}.orig".format( config[ "cef_file" ] ) )

# move our patch
shutil.move( "out", config[ "cef_file" ] )

# now we sign the app
os.system( "codesign --force --deep --sign {} {}".format( config[ "cert" ], config[ "path" ] ) )

print( "Success!" )