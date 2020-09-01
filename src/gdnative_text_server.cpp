/*************************************************************************/
/*  gdnative_text_server.cpp                                             */
/*************************************************************************/

#include "gdnative_text_server.h"

static int features = 0;

void *godot_text_server_constructor(godot_object *p_data) {
	printf("GDN Dummy TS: TS(%p)\n", p_data);
	godot_text_server_data_struct *data = (godot_text_server_data_struct *)core_api->godot_alloc(sizeof(godot_text_server_data_struct));
	data->sever = p_data;
	return data;
}

void godot_text_server_destructor(void *p_data) {
	printf("GDN Dummy TS: ~TS()\n");
	if (p_data != nullptr) {
		core_api->godot_free(p_data);
	}
}

godot_string godot_text_server_get_name(const void *p_data) {
	printf("GDN Dummy TS: get_name()\n");
	godot_string ret;

	core_api->godot_string_new(&ret);
	core_api->godot_string_parse_utf8(&ret, "Dummy");

	return ret;
}

godot_bool godot_text_server_has_feature(const void *p_data, godot_int p_feature) {
	printf("GDN Dummy TS: has_feature(%lld)\n", p_feature);
	return (features & p_feature) == p_feature;
}

bool godot_text_server_load_support_data(void *p_data, const godot_string *p_filename) {
	godot_char_string cs = core_api->godot_string_utf8(p_filename);
	printf("GDN Dummy TS: load_support_data(\"%s\")\n", core_api->godot_char_string_get_data(&cs));
	core_api->godot_char_string_destroy(&cs);
	return true;
}

godot_string godot_text_server_get_support_data_filename(const void *p_data) {
	printf("GDN Dummy TS: get_support_data_filename()\n");
	godot_string ret;

	core_api->godot_string_new(&ret);

	return ret;
}

godot_string godot_text_server_get_support_data_info(const void *p_data) {
	printf("GDN Dummy TS: get_support_data_info()\n");
	godot_string ret;

	core_api->godot_string_new(&ret);
	core_api->godot_string_parse_utf8(&ret, "Not supported.");

	return ret;
}

bool godot_text_server_save_support_data(void *p_data, const godot_string *p_filename) {
	godot_char_string cs = core_api->godot_string_utf8(p_filename);
	printf("GDN Dummy TS: save_support_data(\"%s\")\n", core_api->godot_char_string_get_data(&cs));
	core_api->godot_char_string_destroy(&cs);
	return false;
}

bool godot_text_server_is_locale_right_to_left(void *p_data, const godot_string *p_locale) {
	godot_char_string cs = core_api->godot_string_utf8(p_locale);
	printf("GDN Dummy TS: is_locale_right_to_left(\"%s\")\n", core_api->godot_char_string_get_data(&cs));
	core_api->godot_char_string_destroy(&cs);
	return false;
}

void godot_text_server_free_rid(void *p_data, godot_rid *p_rid) {
	printf("GDN Dummy TS: free(%llu)\n", core_api->godot_rid_get_id(p_rid));

	godot_text_server_data_struct* data = (godot_text_server_data_struct *)p_data;
	uint64_t id = *((uint64_t *)p_rid);
	if (data->fonts.count(id) > 0) {
		data->fonts.erase(id);
	}
	if (data->buffers.count(id) > 0) {
		data->buffers.erase(id);
	}
}

bool godot_text_server_has_rid(void *p_data, godot_rid *p_rid) {
	printf("GDN Dummy TS: has(%llu)\n", core_api->godot_rid_get_id(p_rid));

	godot_text_server_data_struct* data = (godot_text_server_data_struct *)p_data;
	uint64_t id = *((uint64_t *)p_rid);
	return (data->fonts.count(id) > 0) || (data->buffers.count(id) > 0);
}

godot_rid godot_text_server_create_font_system(void *p_data, const godot_string *p_name, int p_base_size) {
	godot_char_string cs = core_api->godot_string_utf8(p_name);
	printf("GDN Dummy TS: create_font_system(\"%s\", %d)\n", core_api->godot_char_string_get_data(&cs), p_base_size);
	core_api->godot_char_string_destroy(&cs);

	godot_text_server_data_struct* data = (godot_text_server_data_struct *)p_data;

	godot_rid r;
	*((uint64_t *)&r) = data->last_id;
	data->fonts[data->last_id] = font_data();
	data->last_id++;
	return r;
}

godot_rid godot_text_server_create_font_resource(void *p_data, const godot_string *p_filename, int p_base_size) {
	godot_char_string cs = core_api->godot_string_utf8(p_filename);
	printf("GDN Dummy TS: create_font_resource(\"%s\", %d)\n", core_api->godot_char_string_get_data(&cs), p_base_size);
	core_api->godot_char_string_destroy(&cs);

	godot_rid r;
	// Return null RID, not implemented.
	core_api->godot_rid_new(&r);
	return r;
}

godot_rid godot_text_server_create_font_memory(void *p_data, const uint8_t *p_membuffer, size_t p_size, godot_string *p_type, int p_base_size) {
	godot_char_string cs = core_api->godot_string_utf8(p_type);
	printf("GDN Dummy TS: create_font_memory(%p[%zu], \"%s\" %d)\n", p_membuffer, p_size, core_api->godot_char_string_get_data(&cs), p_base_size);
	core_api->godot_char_string_destroy(&cs);

	godot_rid r;
	// Return null RID, not implemented.
	core_api->godot_rid_new(&r);
	return r;
}

float godot_text_server_font_get_height(void *p_data, godot_rid *p_font, int p_size) {
	printf("GDN Dummy TS: font_get_height(%lld, %d)\n", core_api->godot_rid_get_id(p_font), p_size);
	return 0.f;
}

float godot_text_server_font_get_ascent(void *p_data, godot_rid *p_font, int p_size) {
	printf("GDN Dummy TS: font_get_ascent(%lld, %d)\n", core_api->godot_rid_get_id(p_font), p_size);
	return 0.f;
}

float godot_text_server_font_get_descent(void *p_data, godot_rid *p_font, int p_size) {
	printf("GDN Dummy TS: font_get_descent(%lld, %d)\n", core_api->godot_rid_get_id(p_font), p_size);
	return 0.f;
}

float godot_text_server_font_get_underline_position(void *p_data, godot_rid *p_font, int p_size) {
	printf("GDN Dummy TS: font_get_underline_position(%lld, %d)\n", core_api->godot_rid_get_id(p_font), p_size);
	return 0.f;
}

float godot_text_server_font_get_underline_thickness(void *p_data, godot_rid *p_font, int p_size) {
	printf("GDN Dummy TS: font_get_underline_thickness(%lld, %d)\n", core_api->godot_rid_get_id(p_font), p_size);
	return 0.f;
}

void godot_text_server_font_set_antialiased(void *p_data, godot_rid *p_font, bool p_enabled) {
	printf("GDN Dummy TS: font_set_antialiased(%lld, %s)\n", core_api->godot_rid_get_id(p_font), p_enabled ? "T" : "F");

}

bool godot_text_server_font_get_antialiased(void *p_data, godot_rid *p_font) {
	printf("GDN Dummy TS: font_get_antialiased(%lld)\n", core_api->godot_rid_get_id(p_font));
	return false;
}

godot_dictionary godot_text_server_font_get_feature_list(void *p_data, godot_rid *p_font) {
	printf("GDN Dummy TS: font_get_feature_list(%lld)\n", core_api->godot_rid_get_id(p_font));
	godot_dictionary ret;

	core_api->godot_dictionary_new(&ret);

	return ret;
}

godot_dictionary godot_text_server_font_get_variation_list(void *p_data, godot_rid *p_font) {
	printf("GDN Dummy TS: font_get_variation_list(%lld)\n", core_api->godot_rid_get_id(p_font));
	godot_dictionary ret;

	core_api->godot_dictionary_new(&ret);

	return ret;
}

void godot_text_server_font_set_variation(void *p_data, godot_rid *p_font, const godot_string *p_variation, double p_value) {
	godot_char_string cs = core_api->godot_string_utf8(p_variation);
	printf("GDN Dummy TS: font_set_variation(%lld, %s, %f)\n", core_api->godot_rid_get_id(p_font), core_api->godot_char_string_get_data(&cs), p_value);
	core_api->godot_char_string_destroy(&cs);
}

double godot_text_server_font_get_variation(void *p_data, godot_rid *p_font, const godot_string *p_variation) {
	godot_char_string cs = core_api->godot_string_utf8(p_variation);
	printf("GDN Dummy TS: font_get_variation(%lld, %s)\n", core_api->godot_rid_get_id(p_font), core_api->godot_char_string_get_data(&cs));
	core_api->godot_char_string_destroy(&cs);

	return 0.f;
}

void godot_text_server_font_set_distance_field_hint(void *p_data, godot_rid *p_font, bool p_enabled) {
	printf("GDN Dummy TS: font_set_distance_field_hint(%lld, %s)\n", core_api->godot_rid_get_id(p_font), p_enabled ? "T" : "F");
}

bool godot_text_server_font_get_distance_field_hint(void *p_data, godot_rid *p_font) {
	printf("GDN Dummy TS: font_get_distance_field_hint(%lld)\n", core_api->godot_rid_get_id(p_font));
	return false;
}

void godot_text_server_font_set_hinting(void *p_data, godot_rid *p_font, godot_int p_hint) {
	printf("GDN Dummy TS: font_set_hinting(%lld, %lld)\n", core_api->godot_rid_get_id(p_font), p_hint);
}

godot_int godot_text_server_font_get_hinting(void *p_data, godot_rid *p_font) {
	printf("GDN Dummy TS: font_get_hinting(%lld)\n", core_api->godot_rid_get_id(p_font));
	return 0;
}

void godot_text_server_font_set_force_autohinter(void *p_data, godot_rid *p_font, bool p_enabled) {
	printf("GDN Dummy TS: font_set_force_autohinter(%lld, %s)\n", core_api->godot_rid_get_id(p_font), p_enabled ? "T" : "F");
}

bool godot_text_server_font_get_force_autohinter(void *p_data, godot_rid *p_font) {
	printf("GDN Dummy TS: font_get_force_autohinter(%lld)\n", core_api->godot_rid_get_id(p_font));
	return false;
}

bool godot_text_server_font_has_char(void *p_data, godot_rid *p_font, char32_t p_char) {
	printf("GDN Dummy TS: font_has_char(%lld, %x)\n", core_api->godot_rid_get_id(p_font), p_char);
	return false;
}

godot_string godot_text_server_font_get_supported_chars(void *p_data, godot_rid *p_font) {
	printf("GDN Dummy TS: font_get_supported_chars%lld)\n", core_api->godot_rid_get_id(p_font));
	godot_string ret;
	core_api->godot_string_new(&ret);
	return ret;
}

bool godot_text_server_font_has_outline(void *p_data, godot_rid *p_font) {
	printf("GDN Dummy TS: font_has_outline(%lld)\n", core_api->godot_rid_get_id(p_font));
	return false;
}

int godot_text_server_font_get_base_size(void *p_data, godot_rid *p_font) {
	printf("GDN Dummy TS: get_base_size(%lld)\n", core_api->godot_rid_get_id(p_font));
	return 16;
}

bool godot_text_server_font_is_language_supported(void *p_data, godot_rid *p_font, const godot_string *p_language) {
	godot_char_string cs = core_api->godot_string_utf8(p_language);
	printf("GDN Dummy TS: font_is_language_supported(%lld, \"%s\")\n", core_api->godot_rid_get_id(p_font), core_api->godot_char_string_get_data(&cs));
	core_api->godot_char_string_destroy(&cs);
	return false;
}

void godot_text_server_font_set_language_support_override(void *p_data, godot_rid *p_font, const godot_string *p_language, bool p_supported) {
	godot_char_string cs = core_api->godot_string_utf8(p_language);
	printf("GDN Dummy TS: font_set_language_support_override(%lld, \"%s\", %s)\n", core_api->godot_rid_get_id(p_font), core_api->godot_char_string_get_data(&cs), p_supported? "T" : "F");
	core_api->godot_char_string_destroy(&cs);
}

bool godot_text_server_font_get_language_support_override(void *p_data, godot_rid *p_font, const godot_string *p_language) {
	godot_char_string cs = core_api->godot_string_utf8(p_language);
	printf("GDN Dummy TS: font_get_language_support_override(%lld, \"%s\")\n", core_api->godot_rid_get_id(p_font), core_api->godot_char_string_get_data(&cs));
	core_api->godot_char_string_destroy(&cs);

	return false;
}

void godot_text_server_font_remove_language_support_override(void *p_data, godot_rid *p_font, const godot_string *p_language) {
	godot_char_string cs = core_api->godot_string_utf8(p_language);
	printf("GDN Dummy TS: font_remove_language_support_override(%lld, \"%s\")\n", core_api->godot_rid_get_id(p_font), core_api->godot_char_string_get_data(&cs));
	core_api->godot_char_string_destroy(&cs);

}

godot_packed_string_array godot_text_server_font_get_language_support_overrides(void *p_data, godot_rid *p_font) {
	printf("GDN Dummy TS: font_get_language_support_overrides(%lld\n)", core_api->godot_rid_get_id(p_font));
	godot_packed_string_array ret;
	core_api->godot_packed_string_array_new(&ret);
	return ret;

}

bool godot_text_server_font_is_script_supported(void *p_data, godot_rid *p_font, const godot_string *p_script) {
	godot_char_string cs = core_api->godot_string_utf8(p_script);
	printf("GDN Dummy TS: font_is_script_supported(%lld, \"%s\")\n", core_api->godot_rid_get_id(p_font), core_api->godot_char_string_get_data(&cs));
	core_api->godot_char_string_destroy(&cs);

	return false;
}

void godot_text_server_font_set_script_support_override(void *p_data, godot_rid *p_font, const godot_string *p_script, bool p_supported) {
	godot_char_string cs = core_api->godot_string_utf8(p_script);
	printf("GDN Dummy TS: font_set_script_support_override(%lld, \"%s\", %s)\n", core_api->godot_rid_get_id(p_font), core_api->godot_char_string_get_data(&cs), p_supported? "T" : "F");
	core_api->godot_char_string_destroy(&cs);
}

bool godot_text_server_font_get_script_support_override(void *p_data, godot_rid *p_font, const godot_string *p_script) {
	godot_char_string cs = core_api->godot_string_utf8(p_script);
	printf("GDN Dummy TS: font_get_script_support_override(%lld, \"%s\")\n", core_api->godot_rid_get_id(p_font), core_api->godot_char_string_get_data(&cs));
	core_api->godot_char_string_destroy(&cs);

	return false;
}

void godot_text_server_font_remove_script_support_override(void *p_data, godot_rid *p_font, const godot_string *p_script) {
	godot_char_string cs = core_api->godot_string_utf8(p_script);
	printf("GDN Dummy TS: font_remove_script_support_override(%lld, \"%s\")\n", core_api->godot_rid_get_id(p_font), core_api->godot_char_string_get_data(&cs));
	core_api->godot_char_string_destroy(&cs);
}

godot_packed_string_array godot_text_server_font_get_script_support_overrides(void *p_data, godot_rid *p_font) {
	printf("GDN Dummy TS: font_get_script_support_overrides(%lld\n)", core_api->godot_rid_get_id(p_font));
	godot_packed_string_array ret;
	core_api->godot_packed_string_array_new(&ret);
	return ret;
}

uint32_t godot_text_server_font_get_glyph_index(void * p_data, godot_rid *p_font, char32_t p_char, char32_t p_var_selector) {
	printf("GDN Dummy TS: font_get_glyph_index(%lld, %x %x\n)", core_api->godot_rid_get_id(p_font), p_char, p_var_selector);
	return 0;
}

godot_vector2 godot_text_server_font_get_glyph_advance(void *p_data, godot_rid *p_font, uint32_t p_char, int p_size) {
	printf("GDN Dummy TS: _font_get_glyph_advance(%lld, %x, %d)\n", core_api->godot_rid_get_id(p_font), p_char, p_size);
	godot_vector2 ret;
	core_api->godot_vector2_new(&ret, 0.f, 0.f);
	return ret;
}

godot_vector2 godot_text_server_font_get_glyph_kerning(void *p_data, godot_rid *p_font, uint32_t p_char_a, uint32_t p_char_b, int p_size) {
	printf("GDN Dummy TS: _font_get_glyph_kerning(%lld, %x, %x, %d)\n", core_api->godot_rid_get_id(p_font), p_char_a, p_char_b, p_size);
	godot_vector2 ret;
	core_api->godot_vector2_new(&ret, 0.f, 0.f);
	return ret;
}

godot_vector2 godot_text_server_font_draw_glyph(void *p_data, godot_rid *p_font, godot_rid *p_canvas, int p_size, const godot_vector2 *p_pos, uint32_t p_glyph, const godot_color *p_color) {
	printf("GDN Dummy TS: font_draw_glyph(%lld, %lld, %d, [x:%f y:%f], %u, [r:%f g:%f b:%f])\n",
			core_api->godot_rid_get_id(p_font),
			core_api->godot_rid_get_id(p_canvas),
			p_size,
			core_api->godot_vector2_get_x(p_pos),
			core_api->godot_vector2_get_y(p_pos),
			p_glyph,
			core_api->godot_color_get_r(p_color),
			core_api->godot_color_get_g(p_color),
			core_api->godot_color_get_b(p_color)
		);

	godot_vector2 ret;
	core_api->godot_vector2_new(&ret, 0.f, 0.f);
	return ret;
}

godot_vector2 godot_text_server_font_draw_glyph_outline(void *p_data, godot_rid *p_font, godot_rid *p_canvas, int p_size, int p_outline_size, const godot_vector2 *p_pos, uint32_t p_glyph, const godot_color *p_color) {
	printf("GDN Dummy TS: font_draw_glyph_outline(%lld, %lld, %d %d, [x:%f y:%f], %u, [r:%f g:%f b:%f])\n",
			core_api->godot_rid_get_id(p_font),
			core_api->godot_rid_get_id(p_canvas),
			p_size,
			p_outline_size,
			core_api->godot_vector2_get_x(p_pos),
			core_api->godot_vector2_get_y(p_pos),
			p_glyph,
			core_api->godot_color_get_r(p_color),
			core_api->godot_color_get_g(p_color),
			core_api->godot_color_get_b(p_color)
		);

	godot_vector2 ret;
	core_api->godot_vector2_new(&ret, 0.f, 0.f);
	return ret;
}

float godot_text_server_font_get_oversampling(void * p_data) {
	printf("GDN Dummy TS: font_get_oversampling()\n");
	return 0.f;
}

void godot_text_server_font_set_oversampling(void *p_data, float p_oversampling) {
	printf("GDN Dummy TS: font_set_oversampling(%f)\n", p_oversampling);
}

godot_packed_string_array godot_text_server_get_system_fonts(void *p_data) {
	printf("GDN Dummy TS: godot_text_server_get_system_fonts()\n");

	godot_packed_string_array ret;
	core_api->godot_packed_string_array_new(&ret);

	return ret;
}

godot_rid godot_text_server_create_shaped_text(void *p_data, godot_int p_direction, godot_int p_orientation) {
	printf("GDN Dummy TS: create_shaped_text(%lld, %lld)\n", p_direction, p_orientation);
	godot_text_server_data_struct *data = (godot_text_server_data_struct *)p_data;

	godot_rid r;
	*((uint64_t *)&r) = data->last_id;
	data->buffers[data->last_id] = text_buffer();
	data->last_id++;
	return r;
}

void godot_text_server_shaped_text_clear(void *p_data, godot_rid *p_shaped) {
	printf("GDN Dummy TS: shaped_text_clear(%lld)\n", core_api->godot_rid_get_id(p_shaped));
	godot_text_server_data_struct *data = (godot_text_server_data_struct *)p_data;
	uint64_t id = *((uint64_t *)p_shaped);
	if (data->fonts.count(id) == 0) {
		printf("Invalid RID\n");
	}
	//...
}

void godot_text_server_shaped_text_set_direction(void *p_data, godot_rid *p_shaped, godot_int p_direction) {
	printf("GDN Dummy TS: shaped_text_set_direction(%lld, %lld)\n", core_api->godot_rid_get_id(p_shaped), p_direction);
}

godot_int godot_text_server_shaped_text_get_direction(void *p_data, godot_rid *p_shaped) {
	printf("GDN Dummy TS: shaped_text_get_direction(%lld)\n", core_api->godot_rid_get_id(p_shaped));
	return 0;
}

void godot_text_server_shaped_text_set_bidi_override(void *p_data, godot_rid *p_shaped, const godot_packed_vector2i_array *p_overrides) {
	printf("GDN Dummy TS: shaped_text_set_bidi_override(%lld, [...])\n", core_api->godot_rid_get_id(p_shaped));
}

void godot_text_server_shaped_text_set_orientation(void *p_data, godot_rid *p_shaped, godot_int p_orientation) {
	printf("GDN Dummy TS: shaped_text_set_orientation(%lld, %lld)\n", core_api->godot_rid_get_id(p_shaped), p_orientation);
}

godot_int godot_text_server_shaped_text_get_orientation(void *p_data, godot_rid *p_shaped) {
	printf("GDN Dummy TS: shaped_text_get_orientation(%lld)\n", core_api->godot_rid_get_id(p_shaped));
	return 0;
}

void godot_text_server_shaped_text_set_preserve_invalid(void *p_data, godot_rid *p_shaped, bool p_enabled) {
	printf("GDN Dummy TS: shaped_text_set_preserve_invalid(%lld, %s)\n", core_api->godot_rid_get_id(p_shaped), p_enabled ? "T" : "F");
}

bool godot_text_server_shaped_text_get_preserve_invalid(void *p_data, godot_rid *p_shaped) {
	printf("GDN Dummy TS: shaped_text_get_preserve_invalid(%lld)\n", core_api->godot_rid_get_id(p_shaped));
	return false;
}

void godot_text_server_shaped_text_set_preserve_control(void *p_data, godot_rid *p_shaped, bool p_enabled) {
	printf("GDN Dummy TS: shaped_text_set_preserve_control(%lld, %s)\n", core_api->godot_rid_get_id(p_shaped), p_enabled ? "T" : "F");
}

bool godot_text_server_shaped_text_get_preserve_control(void *p_data, godot_rid *p_shaped) {
	printf("GDN Dummy TS: shaped_text_get_preserve_control(%lld)\n", core_api->godot_rid_get_id(p_shaped));
	return false;
}

bool godot_text_server_shaped_text_add_string(void *p_data, godot_rid *p_shaped, const godot_string *p_text, const godot_rid **p_fonts, int p_size, const godot_dictionary *p_ot_features, const godot_string *p_language) {
	godot_char_string cs_t = core_api->godot_string_utf8(p_text);
	printf("GDN Dummy TS: shaped_text_add_string(%lld, \"%s\", [ ", core_api->godot_rid_get_id(p_shaped), core_api->godot_char_string_get_data(&cs_t));
	core_api->godot_char_string_destroy(&cs_t);
	const godot_rid *rid = p_fonts[0];
	while (rid != nullptr) {
		printf("%lld ", core_api->godot_rid_get_id(rid));
		rid++;
	}
	godot_char_string cs_l = core_api->godot_string_utf8(p_language);
	printf("], %d, \"%s\", [])\n", p_size, core_api->godot_char_string_get_data(&cs_l));
	core_api->godot_char_string_destroy(&cs_l);

	return false;
}

bool godot_text_server_shaped_text_add_object(void *p_data, godot_rid *p_shaped, const godot_variant *p_id, const godot_vector2 *p_size, godot_int p_align) {
	printf("GDN Dummy TS: shaped_text_add_object(%lld, [%p], [x:%f y:%f], %lld)\n", core_api->godot_rid_get_id(p_shaped), p_id, core_api->godot_vector2_get_x(p_size), core_api->godot_vector2_get_y(p_size), p_align);
	return false;
}

bool godot_text_server_shaped_text_resize_object(void *p_data, godot_rid *p_shaped, const godot_variant *p_id, const godot_vector2 *p_size, godot_int p_align) {
	printf("GDN Dummy TS: shaped_text_resize_object(%lld, [%p], [x:%f y:%f], %lld)\n", core_api->godot_rid_get_id(p_shaped), p_id, core_api->godot_vector2_get_x(p_size), core_api->godot_vector2_get_y(p_size), p_align);
	return false;
}

godot_rid godot_text_server_shaped_text_substr(void *p_data, godot_rid *p_shaped, godot_int p_start, godot_int p_length) {
	printf("GDN Dummy TS: shaped_text_substr(%lld, %lld, %lld)\n", core_api->godot_rid_get_id(p_shaped), p_start, p_length);

	godot_rid r;
	*((uint64_t *)&r) = 10000 + *(uint64_t *)&p_shaped;
	return r;
}

godot_rid godot_text_server_shaped_text_get_parent(void *p_data, godot_rid *p_shaped) {
	printf("GDN Dummy TS: shaped_text_get_parent(%lld)\n", core_api->godot_rid_get_id(p_shaped));
	godot_rid r;
	*((uint64_t *)&r) = *(uint64_t *)&p_shaped - 10000;
	return r;
}

float godot_text_server_shaped_text_fit_to_width(void *p_data, godot_rid *p_shaped, float p_width, uint8_t p_flags) {
	printf("GDN Dummy TS: shaped_text_fit_to_width(%lld, %f, %d)\n", core_api->godot_rid_get_id(p_shaped), p_width, p_flags);
	return 0.f;
}

float godot_text_server_shaped_text_tab_align(void *p_data, godot_rid *p_shaped, godot_packed_float32_array *p_tab_stops) {
	printf("GDN Dummy TS: shaped_text_tab_align(%lld, [ ", core_api->godot_rid_get_id(p_shaped));
	for (int i = 0; i < core_api->godot_packed_float32_array_size(p_tab_stops); i++) {
		printf("%f ", core_api->godot_packed_float32_array_get(p_tab_stops, i));
	}
	printf("])\n");
	return 0.f;
}

bool godot_text_server_shaped_text_shape(void *p_data, godot_rid *p_shaped) {
	printf("GDN Dummy TS: shaped_text_shape(%lld)\n", core_api->godot_rid_get_id(p_shaped));
	return false;
}

bool godot_text_server_shaped_text_update_breaks(void *p_data, godot_rid *p_shaped) {
	printf("GDN Dummy TS: shaped_text_update_breaks(%lld)\n", core_api->godot_rid_get_id(p_shaped));
	return false;
}

bool godot_text_server_shaped_text_update_justification_ops(void *p_data, godot_rid *p_shaped) {
	printf("GDN Dummy TS: shaped_text_update_justification_ops(%lld)\n", core_api->godot_rid_get_id(p_shaped));
	return false;
}

bool godot_text_server_shaped_text_is_ready(void *p_data, godot_rid *p_shaped) {
	printf("GDN Dummy TS: shaped_text_is_ready(%lld)\n", core_api->godot_rid_get_id(p_shaped));
	return false;
}

godot_packed_glyph_array godot_text_server_shaped_text_get_glyphs(void *p_data, godot_rid *p_shaped) {
	printf("GDN Dummy TS: shaped_text_get_glyphs(%lld)\n", core_api->godot_rid_get_id(p_shaped));
	godot_packed_glyph_array ret;
	text_api->godot_packed_glyph_array_new(&ret);

	return ret;
}

godot_vector2i godot_text_server_shaped_text_get_range(void *p_data, godot_rid *p_shaped) {
	printf("GDN Dummy TS: shaped_text_get_range(%lld)\n", core_api->godot_rid_get_id(p_shaped));
	godot_vector2i ret;
	core_api->godot_vector2i_new(&ret, 0, 0);
	return ret;
}

godot_packed_glyph_array godot_text_server_shaped_text_sort_logical(void *p_data, godot_rid *p_shaped) {
	printf("GDN Dummy TS: shaped_text_sort_logical(%lld)\n", core_api->godot_rid_get_id(p_shaped));
	godot_packed_glyph_array ret;
	text_api->godot_packed_glyph_array_new(&ret);

	return ret;
}

godot_packed_vector2i_array godot_text_server_shaped_text_get_line_breaks_adv(void *p_data, godot_rid *p_shaped, godot_packed_float32_array *p_widths, int p_start, bool p_once, uint8_t p_flags) {
	printf("GDN Dummy TS: shaped_text_get_line_breaks_adv(%lld", core_api->godot_rid_get_id(p_shaped));
	for (int i = 0; i < core_api->godot_packed_float32_array_size(p_widths); i++) {
		printf("%f ", core_api->godot_packed_float32_array_get(p_widths, i));
	}
	printf(", %d, %s, %d)\n", p_start, p_once ? "T" : "F", p_flags);

	godot_packed_vector2i_array ret;
	core_api->godot_packed_vector2i_array_new(&ret);
	return ret;
}

godot_packed_vector2i_array godot_text_server_shaped_text_get_line_breaks(void *p_data, godot_rid *p_shaped, float p_width, int p_start, uint8_t p_flags) {
	printf("GDN Dummy TS: shaped_text_get_line_breaks(%lld, %f, %d, %d)", core_api->godot_rid_get_id(p_shaped), p_width, p_start, p_flags);
	godot_packed_vector2i_array ret;
	core_api->godot_packed_vector2i_array_new(&ret);
	return ret;
}

godot_packed_vector2i_array godot_text_server_shaped_text_get_word_breaks(void *p_data, godot_rid *p_shaped) {
	printf("GDN Dummy TS: shaped_text_get_word_breaks(%lld)", core_api->godot_rid_get_id(p_shaped));
	godot_packed_vector2i_array ret;
	core_api->godot_packed_vector2i_array_new(&ret);
	return ret;
}

godot_array godot_text_server_shaped_text_get_objects(void *p_data, godot_rid *p_shaped) {
	printf("GDN Dummy TS: shaped_text_get_objects(%lld)", core_api->godot_rid_get_id(p_shaped));
	godot_array ret;
	godot_array_new(&ret);
	return ret;
}

godot_rect2 godot_text_server_shaped_text_get_object_rect(void *p_data, godot_rid *p_shaped, const godot_variant *p_id) {
	printf("GDN Dummy TS: shaped_text_get_object_rect(%lld, [%p])", core_api->godot_rid_get_id(p_shaped), p_id);
	godot_rect2 ret;
	core_api->godot_rect2_new(&ret, 0.f, 0.f, 0.f, 0.f);
	return ret;
}

godot_vector2 godot_text_server_shaped_text_get_size(void *p_data, godot_rid *p_shaped) {
	printf("GDN Dummy TS: shaped_text_get_size(%lld)", core_api->godot_rid_get_id(p_shaped));
	godot_vector2 ret;
	core_api->godot_vector2_new(&ret, 0.f, 0.f);
	return ret;
}

float godot_text_server_shaped_text_get_ascent(void *p_data, godot_rid *p_shaped) {
	printf("GDN Dummy TS: shaped_text_get_ascent(%lld)", core_api->godot_rid_get_id(p_shaped));
	return 0.f;
}

float godot_text_server_shaped_text_get_descent(void *p_data, godot_rid *p_shaped) {
	printf("GDN Dummy TS: shaped_text_get_descent(%lld)", core_api->godot_rid_get_id(p_shaped));
	return 0.f;
}

float godot_text_server_shaped_text_get_width(void *p_data, godot_rid *p_shaped) {
	printf("GDN Dummy TS: shaped_text_get_width(%lld)", core_api->godot_rid_get_id(p_shaped));
	return 0.f;
}

float godot_text_server_shaped_text_get_underline_position(void *p_data, godot_rid *p_shaped) {
	printf("GDN Dummy TS: shaped_text_get_underline_position(%lld)", core_api->godot_rid_get_id(p_shaped));
	return 0.f;
}

float godot_text_server_shaped_text_get_underline_thickness(void *p_data, godot_rid *p_shaped) {
	printf("GDN Dummy TS: shaped_text_get_underline_thickness(%lld)", core_api->godot_rid_get_id(p_shaped));
	return 0.f;
}

godot_string godot_text_server_format_number(void *p_data, const godot_string *p_text, const godot_string *p_lang) {
	godot_char_string cs = core_api->godot_string_utf8(p_text);
	godot_char_string csl = core_api->godot_string_utf8(p_lang);
	printf("GDN Dummy TS: format_number(\"%s\", \"%s\")\n", core_api->godot_char_string_get_data(&cs), core_api->godot_char_string_get_data(&csl));
	core_api->godot_char_string_destroy(&cs);
	core_api->godot_char_string_destroy(&csl);

	godot_string ret;
	godot_string_new_copy(&ret, p_text);
	return ret;
}

godot_string godot_text_server_parse_number(void *p_data, const godot_string *p_text, const godot_string *p_lang) {
	godot_char_string cs = core_api->godot_string_utf8(p_text);
	godot_char_string csl = core_api->godot_string_utf8(p_lang);
	printf("GDN Dummy TS: parse_number(\"%s\", \"%s\")\n", core_api->godot_char_string_get_data(&cs), core_api->godot_char_string_get_data(&csl));
	core_api->godot_char_string_destroy(&cs);
	core_api->godot_char_string_destroy(&csl);

	godot_string ret;
	godot_string_new_copy(&ret, p_text);
	return ret;
}

godot_string godot_text_server_percent_sign(void *p_data, const godot_string *p_lang) {
	godot_char_string cs = core_api->godot_string_utf8(p_lang);
	printf("GDN Dummy TS: percent_sign(\"%s\")\n", core_api->godot_char_string_get_data(&cs));
	core_api->godot_char_string_destroy(&cs);

	godot_string ret;
	core_api->godot_string_new(&ret);
	core_api->godot_string_parse_utf8(&ret, "%");
	return ret;
}

const godot_text_interface_gdnative interface_struct = {
	GODOT_TEXT_API_MAJOR, GODOT_TEXT_API_MINOR,
	&godot_text_server_constructor,
	&godot_text_server_destructor,
	&godot_text_server_get_name,
	&godot_text_server_has_feature,
	&godot_text_server_load_support_data,
	&godot_text_server_get_support_data_filename,
	&godot_text_server_get_support_data_info,
	&godot_text_server_save_support_data,
	&godot_text_server_is_locale_right_to_left,
	&godot_text_server_free_rid,
	&godot_text_server_has_rid,
	&godot_text_server_create_font_system,
	&godot_text_server_create_font_resource,
	&godot_text_server_create_font_memory,
	&godot_text_server_font_get_height,
	&godot_text_server_font_get_ascent,
	&godot_text_server_font_get_descent,
	&godot_text_server_font_get_underline_position,
	&godot_text_server_font_get_underline_thickness,
	&godot_text_server_font_set_antialiased,
	&godot_text_server_font_get_antialiased,
	&godot_text_server_font_get_feature_list,
	&godot_text_server_font_get_variation_list,
	&godot_text_server_font_set_variation,
	&godot_text_server_font_get_variation,
	&godot_text_server_font_set_distance_field_hint,
	&godot_text_server_font_get_distance_field_hint,
	&godot_text_server_font_set_hinting,
	&godot_text_server_font_get_hinting,
	&godot_text_server_font_set_force_autohinter,
	&godot_text_server_font_get_force_autohinter,
	&godot_text_server_font_has_char,
	&godot_text_server_font_get_supported_chars,
	&godot_text_server_font_has_outline,
	&godot_text_server_font_get_base_size,
	&godot_text_server_font_is_language_supported,
	&godot_text_server_font_set_language_support_override,
	&godot_text_server_font_get_language_support_override,
	&godot_text_server_font_remove_language_support_override,
	&godot_text_server_font_get_language_support_overrides,
	&godot_text_server_font_is_script_supported,
	&godot_text_server_font_set_script_support_override,
	&godot_text_server_font_get_script_support_override,
	&godot_text_server_font_remove_script_support_override,
	&godot_text_server_font_get_script_support_overrides,
	&godot_text_server_font_get_glyph_index,
	&godot_text_server_font_get_glyph_advance,
	&godot_text_server_font_get_glyph_kerning,
	&godot_text_server_font_draw_glyph,
	&godot_text_server_font_draw_glyph_outline,
	&godot_text_server_font_get_oversampling,
	&godot_text_server_font_set_oversampling,
	&godot_text_server_get_system_fonts,
	&godot_text_server_create_shaped_text,
	&godot_text_server_shaped_text_clear,
	&godot_text_server_shaped_text_set_direction,
	&godot_text_server_shaped_text_get_direction,
	&godot_text_server_shaped_text_set_bidi_override,
	&godot_text_server_shaped_text_set_orientation,
	&godot_text_server_shaped_text_get_orientation,
	&godot_text_server_shaped_text_set_preserve_invalid,
	&godot_text_server_shaped_text_get_preserve_invalid,
	&godot_text_server_shaped_text_set_preserve_control,
	&godot_text_server_shaped_text_get_preserve_control,
	&godot_text_server_shaped_text_add_string,
	&godot_text_server_shaped_text_add_object,
	&godot_text_server_shaped_text_resize_object,
	&godot_text_server_shaped_text_substr,
	&godot_text_server_shaped_text_get_parent,
	&godot_text_server_shaped_text_fit_to_width,
	&godot_text_server_shaped_text_tab_align,
	&godot_text_server_shaped_text_shape,
	&godot_text_server_shaped_text_update_breaks,
	&godot_text_server_shaped_text_update_justification_ops,
	&godot_text_server_shaped_text_is_ready,
	&godot_text_server_shaped_text_get_glyphs,
	&godot_text_server_shaped_text_get_range,
	&godot_text_server_shaped_text_sort_logical,
	&godot_text_server_shaped_text_get_line_breaks_adv,
	&godot_text_server_shaped_text_get_line_breaks,
	&godot_text_server_shaped_text_get_word_breaks,
	&godot_text_server_shaped_text_get_objects,
	&godot_text_server_shaped_text_get_object_rect,
	&godot_text_server_shaped_text_get_size,
	&godot_text_server_shaped_text_get_ascent,
	&godot_text_server_shaped_text_get_descent,
	&godot_text_server_shaped_text_get_width,
	&godot_text_server_shaped_text_get_underline_position,
	&godot_text_server_shaped_text_get_underline_thickness,
	&godot_text_server_format_number,
	&godot_text_server_parse_number,
	&godot_text_server_percent_sign,
};

/*************************************************************************/

void GDN_EXPORT godot_text_server_gdnative_init(godot_gdnative_init_options *p_options) {
	printf("GDN Dummy TS: GDN API init - ");
	core_api = p_options->api_struct;
	for (unsigned int i = 0; i < core_api->num_extensions; i++) {
		if (core_api->extensions[i]->type == GDNATIVE_EXT_TEXT) {
			text_api = reinterpret_cast<const godot_gdnative_ext_text_api_struct *>(core_api->extensions[i]);
		}
	}
	if (text_api != nullptr && core_api != nullptr) {
		printf("OK\n");
	} else {
		printf("Failed\n");
	}
}

void GDN_EXPORT godot_text_server_gdnative_terminate(godot_gdnative_terminate_options *p_options) {
	printf("GDN Dummy TS: GDN API terminated\n");
}

void GDN_EXPORT godot_text_server_gdnative_singleton() {
	printf("GDN Dummy TS: Server register - ");
	if (text_api != nullptr && core_api != nullptr) {
		godot_string name;
		core_api->godot_string_new(&name);
		core_api->godot_string_parse_utf8(&name, "Dummy");
		text_api->godot_text_register_interface(&interface_struct, &name, features);
		core_api->godot_string_destroy(&name);
		printf("OK\n");
	} else {
		printf("Failed\n");
	}
}

void GDN_EXPORT godot_text_server_nativescript_init(void *p_handle) {
	printf("GDN Dummy TS: NativeScript API init\n");
}

void GDN_EXPORT godot_text_server_nativescript_terminate(void *p_handle) {
	printf("GDN Dummy TS: NativeScript API terminated\n");
}
