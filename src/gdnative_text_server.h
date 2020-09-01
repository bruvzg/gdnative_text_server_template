/*************************************************************************/
/*  gdnative_text_server.h                                               */
/*************************************************************************/

#ifndef GDNATIVE_TEXT_SERVER
#define GDNATIVE_TEXT_SERVER

#include <cstdio>
#include <cstdint>
#include <map>

#include "gdnative_api_struct.gen.h"

const godot_gdnative_core_api_struct *core_api = nullptr;
const godot_gdnative_ext_text_api_struct *text_api = nullptr;

struct font_data {
	// TODO
};

struct text_buffer {
	// TODO
};

struct godot_text_server_data_struct {
	godot_object *sever;

	uint64_t last_id = 0;

	std::map<uint64_t, font_data> fonts;
	std::map<uint64_t, text_buffer> buffers;
};

#ifdef __cplusplus
extern "C" {
#endif

void GDN_EXPORT godot_text_server_gdnative_init(godot_gdnative_init_options *p_options);
void GDN_EXPORT godot_text_server_gdnative_terminate(godot_gdnative_terminate_options *p_options);

void GDN_EXPORT godot_text_server_gdnative_singleton();

void GDN_EXPORT godot_text_server_nativescript_init(void *p_handle);
void GDN_EXPORT godot_text_server_nativescript_terminate(void *p_handle);

#ifdef __cplusplus
}
#endif

#endif //GDNATIVE_TEXT_SERVER
