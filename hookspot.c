#include <dlfcn.h>

#define PATH "/Applications/Spotify.app/Contents/Frameworks/Chromium Embedded Framework.framework/Chromium Embedded Framework.orig"

#include <string.h>

static const char *blacklist[] = {
	"https://spclient.wg.spotify.com/ads/",
	"https://spclient.wg.spotify.com/ad-logic/",
	"https://spclient.wg.spotify.com/gabo-receiver-service/"
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
} cef_request_t;

void ( * _cef_execute_process )( );
void ( * _cef_initialize )( );
void ( * _cef_shutdown )( );
void ( * _cef_do_message_loop_work )( );
void ( * _cef_run_message_loop )( );
void ( * _cef_quit_message_loop )( );
void ( * _cef_crash_reporting_enabled )( );
void ( * _cef_set_crash_key_value )( );
void ( * _cef_create_directory )( );
void ( * _cef_get_temp_directory )( );
void ( * _cef_create_new_temp_directory )( );
void ( * _cef_create_temp_directory_in_directory )( );
void ( * _cef_directory_exists )( );
void ( * _cef_delete_file )( );
void ( * _cef_zip_directory )( );
void ( * _cef_load_crlsets_file )( );
void ( * _cef_is_rtl )( );
void ( * _cef_add_cross_origin_whitelist_entry )( );
void ( * _cef_remove_cross_origin_whitelist_entry )( );
void ( * _cef_clear_cross_origin_whitelist )( );
void ( * _cef_resolve_url )( );
void ( * _cef_parse_url )( );
void ( * _cef_create_url )( );
void ( * _cef_format_url_for_security_display )( );
void ( * _cef_get_mime_type )( );
void ( * _cef_get_extensions_for_mime_type )( );
void ( * _cef_string_list_clear )( );
void ( * _cef_base64encode )( );
void ( * _cef_base64decode )( );
void ( * _cef_uriencode )( );
void ( * _cef_uridecode )( );
void ( * _cef_parse_json )( );
void ( * _cef_parse_json_buffer )( );
void ( * _cef_parse_jsonand_return_error )( );
void ( * _cef_write_json )( );
void ( * _cef_get_path )( );
void ( * _cef_launch_process )( );
void ( * _cef_register_scheme_handler_factory )( );
void ( * _cef_clear_scheme_handler_factories )( );
void ( * _cef_is_cert_status_error )( );
void ( * _cef_currently_on )( );
void ( * _cef_post_task )( );
void ( * _cef_post_delayed_task )( );
void ( * _cef_begin_tracing )( );
void ( * _cef_end_tracing )( );
void ( * _cef_now_from_system_trace_time )( );
void ( * _cef_register_extension )( );
void ( * _cef_execute_java_script_with_user_gesture_for_tests )( );
void ( * _cef_set_data_directory_for_tests )( );
void ( * _cef_string_utf16_clear )( );
void ( * _cef_string_utf16_set )( );
void ( * _cef_string_userfree_utf16_alloc )( );
void ( * _cef_version_info )( );
void ( * _cef_api_hash )( );
void ( * _cef_string_list_size )( );
void ( * _cef_string_list_value )( );
void ( * _cef_string_list_append )( );
void ( * _cef_string_map_size )( );
void ( * _cef_string_map_key )( );
void ( * _cef_string_map_value )( );
void ( * _cef_string_map_append )( );
void ( * _cef_string_multimap_size )( );
void ( * _cef_string_multimap_key )( );
void ( * _cef_string_multimap_value )( );
void ( * _cef_string_multimap_append )( );
void ( * _cef_string_utf16_cmp )( );
void ( * _cef_binary_value_create )( );
void ( * _cef_browser_host_create_browser )( );
void ( * _cef_browser_host_create_browser_sync )( );
void ( * _cef_browser_view_create )( );
void ( * _cef_browser_view_get_for_browser )( );
void ( * _cef_command_line_create )( );
void ( * _cef_command_line_get_global )( );
void ( * _cef_string_map_clear )( );
void ( * _cef_cookie_manager_get_global_manager )( );
void ( * _cef_string_list_alloc )( );
void ( * _cef_string_list_free )( );
void ( * _cef_dictionary_value_create )( );
void ( * _cef_display_get_primary )( );
void ( * _cef_display_get_nearest_point )( );
void ( * _cef_display_get_matching_bounds )( );
void ( * _cef_display_get_count )( );
void ( * _cef_display_get_alls )( );
void ( * _cef_display_convert_screen_point_to_pixels )( );
void ( * _cef_display_convert_screen_point_from_pixels )( );
void ( * _cef_display_convert_screen_rect_to_pixels )( );
void ( * _cef_display_convert_screen_rect_from_pixels )( );
void ( * _cef_drag_data_create )( );
void ( * _cef_image_create )( );
void ( * _cef_label_button_create )( );
void ( * _cef_list_value_create )( );
void ( * _cef_media_router_get_global )( );
void ( * _cef_menu_button_create )( );
void ( * _cef_menu_model_create )( );
void ( * _cef_panel_create )( );
void ( * _cef_post_data_create )( );
void ( * _cef_post_data_element_create )( );
void ( * _cef_preference_manager_get_global )( );
void ( * _cef_print_settings_create )( );
void ( * _cef_process_message_create )( );
void ( * _cef_request_create )( );
void ( * _cef_string_multimap_clear )( );
void ( * _cef_request_context_get_global_context )( );
void ( * _cef_request_context_create_context )( );
void ( * _cef_create_context_shared )( );
void ( * _cef_resource_bundle_get_global )( );
void ( * _cef_response_create )( );
void ( * _cef_scroll_view_create )( );
void ( * _cef_server_create )( );
void ( * _cef_shared_process_message_builder_create )( );
void ( * _cef_stream_reader_create_for_file )( );
void ( * _cef_stream_reader_create_for_data )( );
void ( * _cef_stream_reader_create_for_handler )( );
void ( * _cef_stream_writer_create_for_file )( );
void ( * _cef_stream_writer_create_for_handler )( );
void ( * _cef_task_runner_get_for_current_thread )( );
void ( * _cef_task_runner_get_for_thread )( );
void ( * _cef_test_server_create_and_start )( );
void ( * _cef_textfield_create )( );
void ( * _cef_thread_create )( );
void ( * _cef_translator_test_create )( );
void ( * _cef_translator_test_ref_ptr_library_create )( );
void ( * _cef_translator_test_ref_ptr_library_child_create )( );
void ( * _cef_translator_test_ref_ptr_library_child_child_create )( );
void ( * _cef_translator_test_scoped_library_create )( );
void ( * _cef_translator_test_scoped_library_child_create )( );
void ( * _cef_translator_test_scoped_library_child_child_create )( );
void ( * _cef_v8context_get_current_context )( );
void ( * _cef_v8context_get_entered_context )( );
void ( * _cef_v8context_in_context )( );
void ( * _cef_v8stack_trace_get_current )( );
void ( * _cef_v8value_create_undefined )( );
void ( * _cef_v8value_create_null )( );
void ( * _cef_v8value_create_bool )( );
void ( * _cef_v8value_create_int )( );
void ( * _cef_v8value_create_uint )( );
void ( * _cef_v8value_create_double )( );
void ( * _cef_v8value_create_date )( );
void ( * _cef_v8value_create_string )( );
void ( * _cef_v8value_create_object )( );
void ( * _cef_v8value_create_array )( );
void ( * _cef_v8value_create_array_buffer )( );
void ( * _cef_v8value_create_function )( );
void ( * _cef_v8value_create_promise )( );
void ( * _cef_value_create )( );
void ( * _cef_waitable_event_create )( );
void ( * _cef_window_create_top_level )( );
void ( * _cef_xml_reader_create )( );
void ( * _cef_zip_reader_create )( );
void ( * _cef_string_utf16_to_utf8 )( );
void ( * _cef_string_utf8_clear )( );
void ( * _cef_string_utf8_to_utf16 )( );
void ( * _cef_trace_event_instant )( );
void ( * _cef_trace_event_begin )( );
void ( * _cef_trace_event_end )( );
void ( * _cef_trace_counter )( );
void ( * _cef_trace_counter_id )( );
void ( * _cef_trace_event_async_begin )( );
void ( * _cef_trace_event_async_step_into )( );
void ( * _cef_trace_event_async_step_past )( );
void ( * _cef_trace_event_async_end )( );
void ( * _cef_get_min_log_level )( );
void ( * _cef_get_vlog_level )( );
void ( * _cef_log )( );
void ( * _cef_get_current_platform_thread_id )( );
void ( * _cef_get_current_platform_thread_handle )( );
void ( * _cef_string_list_copy )( );
void ( * _cef_string_map_alloc )( );
void ( * _cef_string_map_find )( );
void ( * _cef_string_map_free )( );
void ( * _cef_string_multimap_alloc )( );
void ( * _cef_string_multimap_find_count )( );
void ( * _cef_string_multimap_enumerate )( );
void ( * _cef_string_multimap_free )( );
void ( * _cef_string_wide_set )( );
void ( * _cef_string_wide_clear )( );
void ( * _cef_string_utf8_set )( );
void ( * _cef_string_wide_cmp )( );
void ( * _cef_string_utf8_cmp )( );
void ( * _cef_string_wide_to_utf8 )( );
void ( * _cef_string_utf8_to_wide )( );
void ( * _cef_string_wide_to_utf16 )( );
void ( * _cef_string_utf16_to_wide )( );
void ( * _cef_string_ascii_to_wide )( );
void ( * _cef_string_ascii_to_utf16 )( );
void ( * _cef_string_userfree_wide_alloc )( );
void ( * _cef_string_userfree_utf8_alloc )( );
void ( * _cef_string_userfree_wide_free )( );
void ( * _cef_string_userfree_utf8_free )( );
void ( * _cef_string_userfree_utf16_free )( );
void ( * _cef_string_utf16_to_lower )( );
void ( * _cef_string_utf16_to_upper )( );
void ( * _cef_time_to_timet )( );
void ( * _cef_time_from_timet )( );
void ( * _cef_time_to_doublet )( );
void ( * _cef_time_from_doublet )( );
void ( * _cef_time_now )( );
void ( * _cef_basetime_now )( );
void ( * _cef_time_delta )( );
void ( * _cef_time_to_basetime )( );
void ( * _cef_time_from_basetime )( );
void ( * _OBJC_CLASS_$_UnderlayOpenGLHostingWindow )( );
void ( * _ChromeAppModeStart_v7 )( );
void ( * _OBJC_METACLASS_$_UnderlayOpenGLHostingWindow )( );

void* ( * _cef_urlrequest_create )( cef_request_t* req, void* client, void* req_ctx );

__attribute__((constructor)) 
static void init()
{
	void* handle = dlopen( PATH, RTLD_NOW | RTLD_GLOBAL );

    _cef_execute_process = dlsym( handle, "cef_execute_process" );
    _cef_initialize = dlsym( handle, "cef_initialize" );
    _cef_shutdown = dlsym( handle, "cef_shutdown" );
    _cef_do_message_loop_work = dlsym( handle, "cef_do_message_loop_work" );
    _cef_run_message_loop = dlsym( handle, "cef_run_message_loop" );
    _cef_quit_message_loop = dlsym( handle, "cef_quit_message_loop" );
    _cef_crash_reporting_enabled = dlsym( handle, "cef_crash_reporting_enabled" );
    _cef_set_crash_key_value = dlsym( handle, "cef_set_crash_key_value" );
    _cef_create_directory = dlsym( handle, "cef_create_directory" );
    _cef_get_temp_directory = dlsym( handle, "cef_get_temp_directory" );
    _cef_create_new_temp_directory = dlsym( handle, "cef_create_new_temp_directory" );
    _cef_create_temp_directory_in_directory = dlsym( handle, "cef_create_temp_directory_in_directory" );
    _cef_directory_exists = dlsym( handle, "cef_directory_exists" );
    _cef_delete_file = dlsym( handle, "cef_delete_file" );
    _cef_zip_directory = dlsym( handle, "cef_zip_directory" );
    _cef_load_crlsets_file = dlsym( handle, "cef_load_crlsets_file" );
    _cef_is_rtl = dlsym( handle, "cef_is_rtl" );
    _cef_add_cross_origin_whitelist_entry = dlsym( handle, "cef_add_cross_origin_whitelist_entry" );
    _cef_remove_cross_origin_whitelist_entry = dlsym( handle, "cef_remove_cross_origin_whitelist_entry" );
    _cef_clear_cross_origin_whitelist = dlsym( handle, "cef_clear_cross_origin_whitelist" );
    _cef_resolve_url = dlsym( handle, "cef_resolve_url" );
    _cef_parse_url = dlsym( handle, "cef_parse_url" );
    _cef_create_url = dlsym( handle, "cef_create_url" );
    _cef_format_url_for_security_display = dlsym( handle, "cef_format_url_for_security_display" );
    _cef_get_mime_type = dlsym( handle, "cef_get_mime_type" );
    _cef_get_extensions_for_mime_type = dlsym( handle, "cef_get_extensions_for_mime_type" );
    _cef_string_list_clear = dlsym( handle, "cef_string_list_clear" );
    _cef_base64encode = dlsym( handle, "cef_base64encode" );
    _cef_base64decode = dlsym( handle, "cef_base64decode" );
    _cef_uriencode = dlsym( handle, "cef_uriencode" );
    _cef_uridecode = dlsym( handle, "cef_uridecode" );
    _cef_parse_json = dlsym( handle, "cef_parse_json" );
    _cef_parse_json_buffer = dlsym( handle, "cef_parse_json_buffer" );
    _cef_parse_jsonand_return_error = dlsym( handle, "cef_parse_jsonand_return_error" );
    _cef_write_json = dlsym( handle, "cef_write_json" );
    _cef_get_path = dlsym( handle, "cef_get_path" );
    _cef_launch_process = dlsym( handle, "cef_launch_process" );
    _cef_register_scheme_handler_factory = dlsym( handle, "cef_register_scheme_handler_factory" );
    _cef_clear_scheme_handler_factories = dlsym( handle, "cef_clear_scheme_handler_factories" );
    _cef_is_cert_status_error = dlsym( handle, "cef_is_cert_status_error" );
    _cef_currently_on = dlsym( handle, "cef_currently_on" );
    _cef_post_task = dlsym( handle, "cef_post_task" );
    _cef_post_delayed_task = dlsym( handle, "cef_post_delayed_task" );
    _cef_begin_tracing = dlsym( handle, "cef_begin_tracing" );
    _cef_end_tracing = dlsym( handle, "cef_end_tracing" );
    _cef_now_from_system_trace_time = dlsym( handle, "cef_now_from_system_trace_time" );
    _cef_register_extension = dlsym( handle, "cef_register_extension" );
    _cef_execute_java_script_with_user_gesture_for_tests = dlsym( handle, "cef_execute_java_script_with_user_gesture_for_tests" );
    _cef_set_data_directory_for_tests = dlsym( handle, "cef_set_data_directory_for_tests" );
    _cef_string_utf16_clear = dlsym( handle, "cef_string_utf16_clear" );
    _cef_string_utf16_set = dlsym( handle, "cef_string_utf16_set" );
    _cef_string_userfree_utf16_alloc = dlsym( handle, "cef_string_userfree_utf16_alloc" );
    _cef_version_info = dlsym( handle, "cef_version_info" );
    _cef_api_hash = dlsym( handle, "cef_api_hash" );
    _cef_string_list_size = dlsym( handle, "cef_string_list_size" );
    _cef_string_list_value = dlsym( handle, "cef_string_list_value" );
    _cef_string_list_append = dlsym( handle, "cef_string_list_append" );
    _cef_string_map_size = dlsym( handle, "cef_string_map_size" );
    _cef_string_map_key = dlsym( handle, "cef_string_map_key" );
    _cef_string_map_value = dlsym( handle, "cef_string_map_value" );
    _cef_string_map_append = dlsym( handle, "cef_string_map_append" );
    _cef_string_multimap_size = dlsym( handle, "cef_string_multimap_size" );
    _cef_string_multimap_key = dlsym( handle, "cef_string_multimap_key" );
    _cef_string_multimap_value = dlsym( handle, "cef_string_multimap_value" );
    _cef_string_multimap_append = dlsym( handle, "cef_string_multimap_append" );
    _cef_string_utf16_cmp = dlsym( handle, "cef_string_utf16_cmp" );
    _cef_binary_value_create = dlsym( handle, "cef_binary_value_create" );
    _cef_browser_host_create_browser = dlsym( handle, "cef_browser_host_create_browser" );
    _cef_browser_host_create_browser_sync = dlsym( handle, "cef_browser_host_create_browser_sync" );
    _cef_browser_view_create = dlsym( handle, "cef_browser_view_create" );
    _cef_browser_view_get_for_browser = dlsym( handle, "cef_browser_view_get_for_browser" );
    _cef_command_line_create = dlsym( handle, "cef_command_line_create" );
    _cef_command_line_get_global = dlsym( handle, "cef_command_line_get_global" );
    _cef_string_map_clear = dlsym( handle, "cef_string_map_clear" );
    _cef_cookie_manager_get_global_manager = dlsym( handle, "cef_cookie_manager_get_global_manager" );
    _cef_string_list_alloc = dlsym( handle, "cef_string_list_alloc" );
    _cef_string_list_free = dlsym( handle, "cef_string_list_free" );
    _cef_dictionary_value_create = dlsym( handle, "cef_dictionary_value_create" );
    _cef_display_get_primary = dlsym( handle, "cef_display_get_primary" );
    _cef_display_get_nearest_point = dlsym( handle, "cef_display_get_nearest_point" );
    _cef_display_get_matching_bounds = dlsym( handle, "cef_display_get_matching_bounds" );
    _cef_display_get_count = dlsym( handle, "cef_display_get_count" );
    _cef_display_get_alls = dlsym( handle, "cef_display_get_alls" );
    _cef_display_convert_screen_point_to_pixels = dlsym( handle, "cef_display_convert_screen_point_to_pixels" );
    _cef_display_convert_screen_point_from_pixels = dlsym( handle, "cef_display_convert_screen_point_from_pixels" );
    _cef_display_convert_screen_rect_to_pixels = dlsym( handle, "cef_display_convert_screen_rect_to_pixels" );
    _cef_display_convert_screen_rect_from_pixels = dlsym( handle, "cef_display_convert_screen_rect_from_pixels" );
    _cef_drag_data_create = dlsym( handle, "cef_drag_data_create" );
    _cef_image_create = dlsym( handle, "cef_image_create" );
    _cef_label_button_create = dlsym( handle, "cef_label_button_create" );
    _cef_list_value_create = dlsym( handle, "cef_list_value_create" );
    _cef_media_router_get_global = dlsym( handle, "cef_media_router_get_global" );
    _cef_menu_button_create = dlsym( handle, "cef_menu_button_create" );
    _cef_menu_model_create = dlsym( handle, "cef_menu_model_create" );
    _cef_panel_create = dlsym( handle, "cef_panel_create" );
    _cef_post_data_create = dlsym( handle, "cef_post_data_create" );
    _cef_post_data_element_create = dlsym( handle, "cef_post_data_element_create" );
    _cef_preference_manager_get_global = dlsym( handle, "cef_preference_manager_get_global" );
    _cef_print_settings_create = dlsym( handle, "cef_print_settings_create" );
    _cef_process_message_create = dlsym( handle, "cef_process_message_create" );
    _cef_request_create = dlsym( handle, "cef_request_create" );
    _cef_string_multimap_clear = dlsym( handle, "cef_string_multimap_clear" );
    _cef_request_context_get_global_context = dlsym( handle, "cef_request_context_get_global_context" );
    _cef_request_context_create_context = dlsym( handle, "cef_request_context_create_context" );
    _cef_create_context_shared = dlsym( handle, "cef_create_context_shared" );
    _cef_resource_bundle_get_global = dlsym( handle, "cef_resource_bundle_get_global" );
    _cef_response_create = dlsym( handle, "cef_response_create" );
    _cef_scroll_view_create = dlsym( handle, "cef_scroll_view_create" );
    _cef_server_create = dlsym( handle, "cef_server_create" );
    _cef_shared_process_message_builder_create = dlsym( handle, "cef_shared_process_message_builder_create" );
    _cef_stream_reader_create_for_file = dlsym( handle, "cef_stream_reader_create_for_file" );
    _cef_stream_reader_create_for_data = dlsym( handle, "cef_stream_reader_create_for_data" );
    _cef_stream_reader_create_for_handler = dlsym( handle, "cef_stream_reader_create_for_handler" );
    _cef_stream_writer_create_for_file = dlsym( handle, "cef_stream_writer_create_for_file" );
    _cef_stream_writer_create_for_handler = dlsym( handle, "cef_stream_writer_create_for_handler" );
    _cef_task_runner_get_for_current_thread = dlsym( handle, "cef_task_runner_get_for_current_thread" );
    _cef_task_runner_get_for_thread = dlsym( handle, "cef_task_runner_get_for_thread" );
    _cef_test_server_create_and_start = dlsym( handle, "cef_test_server_create_and_start" );
    _cef_textfield_create = dlsym( handle, "cef_textfield_create" );
    _cef_thread_create = dlsym( handle, "cef_thread_create" );
    _cef_translator_test_create = dlsym( handle, "cef_translator_test_create" );
    _cef_translator_test_ref_ptr_library_create = dlsym( handle, "cef_translator_test_ref_ptr_library_create" );
    _cef_translator_test_ref_ptr_library_child_create = dlsym( handle, "cef_translator_test_ref_ptr_library_child_create" );
    _cef_translator_test_ref_ptr_library_child_child_create = dlsym( handle, "cef_translator_test_ref_ptr_library_child_child_create" );
    _cef_translator_test_scoped_library_create = dlsym( handle, "cef_translator_test_scoped_library_create" );
    _cef_translator_test_scoped_library_child_create = dlsym( handle, "cef_translator_test_scoped_library_child_create" );
    _cef_translator_test_scoped_library_child_child_create = dlsym( handle, "cef_translator_test_scoped_library_child_child_create" );
    _cef_urlrequest_create = dlsym( handle, "cef_urlrequest_create" );
    _cef_v8context_get_current_context = dlsym( handle, "cef_v8context_get_current_context" );
    _cef_v8context_get_entered_context = dlsym( handle, "cef_v8context_get_entered_context" );
    _cef_v8context_in_context = dlsym( handle, "cef_v8context_in_context" );
    _cef_v8stack_trace_get_current = dlsym( handle, "cef_v8stack_trace_get_current" );
    _cef_v8value_create_undefined = dlsym( handle, "cef_v8value_create_undefined" );
    _cef_v8value_create_null = dlsym( handle, "cef_v8value_create_null" );
    _cef_v8value_create_bool = dlsym( handle, "cef_v8value_create_bool" );
    _cef_v8value_create_int = dlsym( handle, "cef_v8value_create_int" );
    _cef_v8value_create_uint = dlsym( handle, "cef_v8value_create_uint" );
    _cef_v8value_create_double = dlsym( handle, "cef_v8value_create_double" );
    _cef_v8value_create_date = dlsym( handle, "cef_v8value_create_date" );
    _cef_v8value_create_string = dlsym( handle, "cef_v8value_create_string" );
    _cef_v8value_create_object = dlsym( handle, "cef_v8value_create_object" );
    _cef_v8value_create_array = dlsym( handle, "cef_v8value_create_array" );
    _cef_v8value_create_array_buffer = dlsym( handle, "cef_v8value_create_array_buffer" );
    _cef_v8value_create_function = dlsym( handle, "cef_v8value_create_function" );
    _cef_v8value_create_promise = dlsym( handle, "cef_v8value_create_promise" );
    _cef_value_create = dlsym( handle, "cef_value_create" );
    _cef_waitable_event_create = dlsym( handle, "cef_waitable_event_create" );
    _cef_window_create_top_level = dlsym( handle, "cef_window_create_top_level" );
    _cef_xml_reader_create = dlsym( handle, "cef_xml_reader_create" );
    _cef_zip_reader_create = dlsym( handle, "cef_zip_reader_create" );
    _cef_string_utf16_to_utf8 = dlsym( handle, "cef_string_utf16_to_utf8" );
    _cef_string_utf8_clear = dlsym( handle, "cef_string_utf8_clear" );
    _cef_string_utf8_to_utf16 = dlsym( handle, "cef_string_utf8_to_utf16" );
    _cef_trace_event_instant = dlsym( handle, "cef_trace_event_instant" );
    _cef_trace_event_begin = dlsym( handle, "cef_trace_event_begin" );
    _cef_trace_event_end = dlsym( handle, "cef_trace_event_end" );
    _cef_trace_counter = dlsym( handle, "cef_trace_counter" );
    _cef_trace_counter_id = dlsym( handle, "cef_trace_counter_id" );
    _cef_trace_event_async_begin = dlsym( handle, "cef_trace_event_async_begin" );
    _cef_trace_event_async_step_into = dlsym( handle, "cef_trace_event_async_step_into" );
    _cef_trace_event_async_step_past = dlsym( handle, "cef_trace_event_async_step_past" );
    _cef_trace_event_async_end = dlsym( handle, "cef_trace_event_async_end" );
    _cef_get_min_log_level = dlsym( handle, "cef_get_min_log_level" );
    _cef_get_vlog_level = dlsym( handle, "cef_get_vlog_level" );
    _cef_log = dlsym( handle, "cef_log" );
    _cef_get_current_platform_thread_id = dlsym( handle, "cef_get_current_platform_thread_id" );
    _cef_get_current_platform_thread_handle = dlsym( handle, "cef_get_current_platform_thread_handle" );
    _cef_string_list_copy = dlsym( handle, "cef_string_list_copy" );
    _cef_string_map_alloc = dlsym( handle, "cef_string_map_alloc" );
    _cef_string_map_find = dlsym( handle, "cef_string_map_find" );
    _cef_string_map_free = dlsym( handle, "cef_string_map_free" );
    _cef_string_multimap_alloc = dlsym( handle, "cef_string_multimap_alloc" );
    _cef_string_multimap_find_count = dlsym( handle, "cef_string_multimap_find_count" );
    _cef_string_multimap_enumerate = dlsym( handle, "cef_string_multimap_enumerate" );
    _cef_string_multimap_free = dlsym( handle, "cef_string_multimap_free" );
    _cef_string_wide_set = dlsym( handle, "cef_string_wide_set" );
    _cef_string_wide_clear = dlsym( handle, "cef_string_wide_clear" );
    _cef_string_utf8_set = dlsym( handle, "cef_string_utf8_set" );
    _cef_string_wide_cmp = dlsym( handle, "cef_string_wide_cmp" );
    _cef_string_utf8_cmp = dlsym( handle, "cef_string_utf8_cmp" );
    _cef_string_wide_to_utf8 = dlsym( handle, "cef_string_wide_to_utf8" );
    _cef_string_utf8_to_wide = dlsym( handle, "cef_string_utf8_to_wide" );
    _cef_string_wide_to_utf16 = dlsym( handle, "cef_string_wide_to_utf16" );
    _cef_string_utf16_to_wide = dlsym( handle, "cef_string_utf16_to_wide" );
    _cef_string_ascii_to_wide = dlsym( handle, "cef_string_ascii_to_wide" );
    _cef_string_ascii_to_utf16 = dlsym( handle, "cef_string_ascii_to_utf16" );
    _cef_string_userfree_wide_alloc = dlsym( handle, "cef_string_userfree_wide_alloc" );
    _cef_string_userfree_utf8_alloc = dlsym( handle, "cef_string_userfree_utf8_alloc" );
    _cef_string_userfree_wide_free = dlsym( handle, "cef_string_userfree_wide_free" );
    _cef_string_userfree_utf8_free = dlsym( handle, "cef_string_userfree_utf8_free" );
    _cef_string_userfree_utf16_free = dlsym( handle, "cef_string_userfree_utf16_free" );
    _cef_string_utf16_to_lower = dlsym( handle, "cef_string_utf16_to_lower" );
    _cef_string_utf16_to_upper = dlsym( handle, "cef_string_utf16_to_upper" );
    _cef_time_to_timet = dlsym( handle, "cef_time_to_timet" );
    _cef_time_from_timet = dlsym( handle, "cef_time_from_timet" );
    _cef_time_to_doublet = dlsym( handle, "cef_time_to_doublet" );
    _cef_time_from_doublet = dlsym( handle, "cef_time_from_doublet" );
    _cef_time_now = dlsym( handle, "cef_time_now" );
    _cef_basetime_now = dlsym( handle, "cef_basetime_now" );
    _cef_time_delta = dlsym( handle, "cef_time_delta" );
    _cef_time_to_basetime = dlsym( handle, "cef_time_to_basetime" );
    _cef_time_from_basetime = dlsym( handle, "cef_time_from_basetime" );
    _OBJC_CLASS_$_UnderlayOpenGLHostingWindow = dlsym( handle, "OBJC_CLASS_$_UnderlayOpenGLHostingWindow" );
    _ChromeAppModeStart_v7 = dlsym( handle, "ChromeAppModeStart_v7" );
    _OBJC_METACLASS_$_UnderlayOpenGLHostingWindow = dlsym( handle, "OBJC_METACLASS_$_UnderlayOpenGLHostingWindow" );
}

#ifdef __amd64__

#define CREATE_HOOKED_FUN( f ) \
    __attribute__((naked)) \
	void f( ) \
	{ \
		asm volatile( "jmpq *%0;" \
			     : \
			     : "r" (_##f)); \
	}

#elif __aarch64__

#define CREATE_HOOKED_FUN( f ) \
	void f( ) { _##f(); }

#elif

#error Unknown architecture

#endif

CREATE_HOOKED_FUN( cef_execute_process )
CREATE_HOOKED_FUN( cef_initialize )
CREATE_HOOKED_FUN( cef_shutdown )
CREATE_HOOKED_FUN( cef_do_message_loop_work )
CREATE_HOOKED_FUN( cef_run_message_loop )
CREATE_HOOKED_FUN( cef_quit_message_loop )
CREATE_HOOKED_FUN( cef_crash_reporting_enabled )
CREATE_HOOKED_FUN( cef_set_crash_key_value )
CREATE_HOOKED_FUN( cef_create_directory )
CREATE_HOOKED_FUN( cef_get_temp_directory )
CREATE_HOOKED_FUN( cef_create_new_temp_directory )
CREATE_HOOKED_FUN( cef_create_temp_directory_in_directory )
CREATE_HOOKED_FUN( cef_directory_exists )
CREATE_HOOKED_FUN( cef_delete_file )
CREATE_HOOKED_FUN( cef_zip_directory )
CREATE_HOOKED_FUN( cef_load_crlsets_file )
CREATE_HOOKED_FUN( cef_is_rtl )
CREATE_HOOKED_FUN( cef_add_cross_origin_whitelist_entry )
CREATE_HOOKED_FUN( cef_remove_cross_origin_whitelist_entry )
CREATE_HOOKED_FUN( cef_clear_cross_origin_whitelist )
CREATE_HOOKED_FUN( cef_resolve_url )
CREATE_HOOKED_FUN( cef_parse_url )
CREATE_HOOKED_FUN( cef_create_url )
CREATE_HOOKED_FUN( cef_format_url_for_security_display )
CREATE_HOOKED_FUN( cef_get_mime_type )
CREATE_HOOKED_FUN( cef_get_extensions_for_mime_type )
CREATE_HOOKED_FUN( cef_string_list_clear )
CREATE_HOOKED_FUN( cef_base64encode )
CREATE_HOOKED_FUN( cef_base64decode )
CREATE_HOOKED_FUN( cef_uriencode )
CREATE_HOOKED_FUN( cef_uridecode )
CREATE_HOOKED_FUN( cef_parse_json )
CREATE_HOOKED_FUN( cef_parse_json_buffer )
CREATE_HOOKED_FUN( cef_parse_jsonand_return_error )
CREATE_HOOKED_FUN( cef_write_json )
CREATE_HOOKED_FUN( cef_get_path )
CREATE_HOOKED_FUN( cef_launch_process )
CREATE_HOOKED_FUN( cef_register_scheme_handler_factory )
CREATE_HOOKED_FUN( cef_clear_scheme_handler_factories )
CREATE_HOOKED_FUN( cef_is_cert_status_error )
CREATE_HOOKED_FUN( cef_currently_on )
CREATE_HOOKED_FUN( cef_post_task )
CREATE_HOOKED_FUN( cef_post_delayed_task )
CREATE_HOOKED_FUN( cef_begin_tracing )
CREATE_HOOKED_FUN( cef_end_tracing )
CREATE_HOOKED_FUN( cef_now_from_system_trace_time )
CREATE_HOOKED_FUN( cef_register_extension )
CREATE_HOOKED_FUN( cef_execute_java_script_with_user_gesture_for_tests )
CREATE_HOOKED_FUN( cef_set_data_directory_for_tests )
CREATE_HOOKED_FUN( cef_string_utf16_clear )
CREATE_HOOKED_FUN( cef_string_utf16_set )
CREATE_HOOKED_FUN( cef_string_userfree_utf16_alloc )
CREATE_HOOKED_FUN( cef_version_info )
CREATE_HOOKED_FUN( cef_api_hash )
CREATE_HOOKED_FUN( cef_string_list_size )
CREATE_HOOKED_FUN( cef_string_list_value )
CREATE_HOOKED_FUN( cef_string_list_append )
CREATE_HOOKED_FUN( cef_string_map_size )
CREATE_HOOKED_FUN( cef_string_map_key )
CREATE_HOOKED_FUN( cef_string_map_value )
CREATE_HOOKED_FUN( cef_string_map_append )
CREATE_HOOKED_FUN( cef_string_multimap_size )
CREATE_HOOKED_FUN( cef_string_multimap_key )
CREATE_HOOKED_FUN( cef_string_multimap_value )
CREATE_HOOKED_FUN( cef_string_multimap_append )
CREATE_HOOKED_FUN( cef_string_utf16_cmp )
CREATE_HOOKED_FUN( cef_binary_value_create )
CREATE_HOOKED_FUN( cef_browser_host_create_browser )
CREATE_HOOKED_FUN( cef_browser_host_create_browser_sync )
CREATE_HOOKED_FUN( cef_browser_view_create )
CREATE_HOOKED_FUN( cef_browser_view_get_for_browser )
CREATE_HOOKED_FUN( cef_command_line_create )
CREATE_HOOKED_FUN( cef_command_line_get_global )
CREATE_HOOKED_FUN( cef_string_map_clear )
CREATE_HOOKED_FUN( cef_cookie_manager_get_global_manager )
CREATE_HOOKED_FUN( cef_string_list_alloc )
CREATE_HOOKED_FUN( cef_string_list_free )
CREATE_HOOKED_FUN( cef_dictionary_value_create )
CREATE_HOOKED_FUN( cef_display_get_primary )
CREATE_HOOKED_FUN( cef_display_get_nearest_point )
CREATE_HOOKED_FUN( cef_display_get_matching_bounds )
CREATE_HOOKED_FUN( cef_display_get_count )
CREATE_HOOKED_FUN( cef_display_get_alls )
CREATE_HOOKED_FUN( cef_display_convert_screen_point_to_pixels )
CREATE_HOOKED_FUN( cef_display_convert_screen_point_from_pixels )
CREATE_HOOKED_FUN( cef_display_convert_screen_rect_to_pixels )
CREATE_HOOKED_FUN( cef_display_convert_screen_rect_from_pixels )
CREATE_HOOKED_FUN( cef_drag_data_create )
CREATE_HOOKED_FUN( cef_image_create )
CREATE_HOOKED_FUN( cef_label_button_create )
CREATE_HOOKED_FUN( cef_list_value_create )
CREATE_HOOKED_FUN( cef_media_router_get_global )
CREATE_HOOKED_FUN( cef_menu_button_create )
CREATE_HOOKED_FUN( cef_menu_model_create )
CREATE_HOOKED_FUN( cef_panel_create )
CREATE_HOOKED_FUN( cef_post_data_create )
CREATE_HOOKED_FUN( cef_post_data_element_create )
CREATE_HOOKED_FUN( cef_preference_manager_get_global )
CREATE_HOOKED_FUN( cef_print_settings_create )
CREATE_HOOKED_FUN( cef_process_message_create )
CREATE_HOOKED_FUN( cef_request_create )
CREATE_HOOKED_FUN( cef_string_multimap_clear )
CREATE_HOOKED_FUN( cef_request_context_get_global_context )
CREATE_HOOKED_FUN( cef_request_context_create_context )
CREATE_HOOKED_FUN( cef_create_context_shared )
CREATE_HOOKED_FUN( cef_resource_bundle_get_global )
CREATE_HOOKED_FUN( cef_response_create )
CREATE_HOOKED_FUN( cef_scroll_view_create )
CREATE_HOOKED_FUN( cef_server_create )
CREATE_HOOKED_FUN( cef_shared_process_message_builder_create )
CREATE_HOOKED_FUN( cef_stream_reader_create_for_file )
CREATE_HOOKED_FUN( cef_stream_reader_create_for_data )
CREATE_HOOKED_FUN( cef_stream_reader_create_for_handler )
CREATE_HOOKED_FUN( cef_stream_writer_create_for_file )
CREATE_HOOKED_FUN( cef_stream_writer_create_for_handler )
CREATE_HOOKED_FUN( cef_task_runner_get_for_current_thread )
CREATE_HOOKED_FUN( cef_task_runner_get_for_thread )
CREATE_HOOKED_FUN( cef_test_server_create_and_start )
CREATE_HOOKED_FUN( cef_textfield_create )
CREATE_HOOKED_FUN( cef_thread_create )
CREATE_HOOKED_FUN( cef_translator_test_create )
CREATE_HOOKED_FUN( cef_translator_test_ref_ptr_library_create )
CREATE_HOOKED_FUN( cef_translator_test_ref_ptr_library_child_create )
CREATE_HOOKED_FUN( cef_translator_test_ref_ptr_library_child_child_create )
CREATE_HOOKED_FUN( cef_translator_test_scoped_library_create )
CREATE_HOOKED_FUN( cef_translator_test_scoped_library_child_create )
CREATE_HOOKED_FUN( cef_translator_test_scoped_library_child_child_create )
CREATE_HOOKED_FUN( cef_v8context_get_current_context )
CREATE_HOOKED_FUN( cef_v8context_get_entered_context )
CREATE_HOOKED_FUN( cef_v8context_in_context )
CREATE_HOOKED_FUN( cef_v8stack_trace_get_current )
CREATE_HOOKED_FUN( cef_v8value_create_undefined )
CREATE_HOOKED_FUN( cef_v8value_create_null )
CREATE_HOOKED_FUN( cef_v8value_create_bool )
CREATE_HOOKED_FUN( cef_v8value_create_int )
CREATE_HOOKED_FUN( cef_v8value_create_uint )
CREATE_HOOKED_FUN( cef_v8value_create_double )
CREATE_HOOKED_FUN( cef_v8value_create_date )
CREATE_HOOKED_FUN( cef_v8value_create_string )
CREATE_HOOKED_FUN( cef_v8value_create_object )
CREATE_HOOKED_FUN( cef_v8value_create_array )
CREATE_HOOKED_FUN( cef_v8value_create_array_buffer )
CREATE_HOOKED_FUN( cef_v8value_create_function )
CREATE_HOOKED_FUN( cef_v8value_create_promise )
CREATE_HOOKED_FUN( cef_value_create )
CREATE_HOOKED_FUN( cef_waitable_event_create )
CREATE_HOOKED_FUN( cef_window_create_top_level )
CREATE_HOOKED_FUN( cef_xml_reader_create )
CREATE_HOOKED_FUN( cef_zip_reader_create )
CREATE_HOOKED_FUN( cef_string_utf16_to_utf8 )
CREATE_HOOKED_FUN( cef_string_utf8_clear )
CREATE_HOOKED_FUN( cef_string_utf8_to_utf16 )
CREATE_HOOKED_FUN( cef_trace_event_instant )
CREATE_HOOKED_FUN( cef_trace_event_begin )
CREATE_HOOKED_FUN( cef_trace_event_end )
CREATE_HOOKED_FUN( cef_trace_counter )
CREATE_HOOKED_FUN( cef_trace_counter_id )
CREATE_HOOKED_FUN( cef_trace_event_async_begin )
CREATE_HOOKED_FUN( cef_trace_event_async_step_into )
CREATE_HOOKED_FUN( cef_trace_event_async_step_past )
CREATE_HOOKED_FUN( cef_trace_event_async_end )
CREATE_HOOKED_FUN( cef_get_min_log_level )
CREATE_HOOKED_FUN( cef_get_vlog_level )
CREATE_HOOKED_FUN( cef_log )
CREATE_HOOKED_FUN( cef_get_current_platform_thread_id )
CREATE_HOOKED_FUN( cef_get_current_platform_thread_handle )
CREATE_HOOKED_FUN( cef_string_list_copy )
CREATE_HOOKED_FUN( cef_string_map_alloc )
CREATE_HOOKED_FUN( cef_string_map_find )
CREATE_HOOKED_FUN( cef_string_map_free )
CREATE_HOOKED_FUN( cef_string_multimap_alloc )
CREATE_HOOKED_FUN( cef_string_multimap_find_count )
CREATE_HOOKED_FUN( cef_string_multimap_enumerate )
CREATE_HOOKED_FUN( cef_string_multimap_free )
CREATE_HOOKED_FUN( cef_string_wide_set )
CREATE_HOOKED_FUN( cef_string_wide_clear )
CREATE_HOOKED_FUN( cef_string_utf8_set )
CREATE_HOOKED_FUN( cef_string_wide_cmp )
CREATE_HOOKED_FUN( cef_string_utf8_cmp )
CREATE_HOOKED_FUN( cef_string_wide_to_utf8 )
CREATE_HOOKED_FUN( cef_string_utf8_to_wide )
CREATE_HOOKED_FUN( cef_string_wide_to_utf16 )
CREATE_HOOKED_FUN( cef_string_utf16_to_wide )
CREATE_HOOKED_FUN( cef_string_ascii_to_wide )
CREATE_HOOKED_FUN( cef_string_ascii_to_utf16 )
CREATE_HOOKED_FUN( cef_string_userfree_wide_alloc )
CREATE_HOOKED_FUN( cef_string_userfree_utf8_alloc )
CREATE_HOOKED_FUN( cef_string_userfree_wide_free )
CREATE_HOOKED_FUN( cef_string_userfree_utf8_free )
CREATE_HOOKED_FUN( cef_string_userfree_utf16_free )
CREATE_HOOKED_FUN( cef_string_utf16_to_lower )
CREATE_HOOKED_FUN( cef_string_utf16_to_upper )
CREATE_HOOKED_FUN( cef_time_to_timet )
CREATE_HOOKED_FUN( cef_time_from_timet )
CREATE_HOOKED_FUN( cef_time_to_doublet )
CREATE_HOOKED_FUN( cef_time_from_doublet )
CREATE_HOOKED_FUN( cef_time_now )
CREATE_HOOKED_FUN( cef_basetime_now )
CREATE_HOOKED_FUN( cef_time_delta )
CREATE_HOOKED_FUN( cef_time_to_basetime )
CREATE_HOOKED_FUN( cef_time_from_basetime )
CREATE_HOOKED_FUN( OBJC_CLASS_$_UnderlayOpenGLHostingWindow )
CREATE_HOOKED_FUN( ChromeAppModeStart_v7 )
CREATE_HOOKED_FUN( OBJC_METACLASS_$_UnderlayOpenGLHostingWindow )

void* cef_urlrequest_create( cef_request_t* req, void* client, void* req_ctx )
{
	cef_string_userfree_utf16_t url_utf16 = req->get_url( req );	char url[ url_utf16->len + 1 ];
	url[ url_utf16->len ] = '\0';

	for( int i = 0; i < url_utf16->len; i++ )
		url[ i ] = *( url_utf16->str + i );

	_cef_string_userfree_utf16_free( url_utf16 );

	if ( is_blacklisted(url) )
		return 0;

	return _cef_urlrequest_create( req, client, req_ctx);
}