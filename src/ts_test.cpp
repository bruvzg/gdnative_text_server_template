#include "ts_test.h"

using namespace godot;

/*************************************************************************/

uint32_t TextServerTest::interface_features = FEATURE_BIDI_LAYOUT | FEATURE_VERTICAL_LAYOUT | FEATURE_SHAPING | FEATURE_KASHIDA_JUSTIFICATION | FEATURE_BREAK_ITERATORS | FEATURE_FONT_VARIABLE;

bool TextServerTest::_has_feature(TextServer::Feature p_feature) const{
    return (interface_features & p_feature) == p_feature;
}

String TextServerTest::_get_name() const{
    return "Test text server";
}

int64_t TextServerTest::_get_features() const{
    return (int64_t)interface_features;
}

void TextServerTest::_free(const RID &p_rid){
}

bool TextServerTest::_has(const RID &p_rid){
    return false;
}

bool TextServerTest::_load_support_data(const String &p_filename){
    return false;
}

String TextServerTest::_get_support_data_filename() const{
    return "";
}

String TextServerTest::_get_support_data_info() const{
    return "";
}

bool TextServerTest::_save_support_data(const String &p_filename) const{
    return false;
}

bool TextServerTest::_is_locale_right_to_left(const String &p_locale) const{
    return false;
}

int64_t TextServerTest::_name_to_tag(const String &p_name) const{
    return 0;
}

String TextServerTest::_tag_to_name(int64_t p_tag) const{
    return "";
}

RID TextServerTest::_create_font(){
    return RID();
}

void TextServerTest::_font_set_data(const RID &p_font_rid, const PackedByteArray &p_data){
}

void TextServerTest::_font_set_data_ptr(const RID &p_font_rid, const uint8_t *p_data_ptr, int64_t p_data_size) {
}

void TextServerTest::_font_set_antialiased(const RID &p_font_rid, bool p_antialiased){
}

bool TextServerTest::_font_is_antialiased(const RID &p_font_rid) const{
    return false;
}

void TextServerTest::_font_set_multichannel_signed_distance_field(const RID &p_font_rid, bool p_msdf){
}

bool TextServerTest::_font_is_multichannel_signed_distance_field(const RID &p_font_rid) const{
    return false;
}

void TextServerTest::_font_set_msdf_pixel_range(const RID &p_font_rid, int64_t p_msdf_pixel_range){
}

int64_t TextServerTest::_font_get_msdf_pixel_range(const RID &p_font_rid) const{
    return 0;
}

void TextServerTest::_font_set_msdf_size(const RID &p_font_rid, int64_t p_msdf_size){
}

int64_t TextServerTest::_font_get_msdf_size(const RID &p_font_rid) const{
    return 0;
}

void TextServerTest::_font_set_fixed_size(const RID &p_font_rid, int64_t p_fixed_size){
}

int64_t TextServerTest::_font_get_fixed_size(const RID &p_font_rid) const{
    return 0;
}

void TextServerTest::_font_set_force_autohinter(const RID &p_font_rid, bool p_force_autohinter){
}

bool TextServerTest::_font_is_force_autohinter(const RID &p_font_rid) const{
    return false;
}

void TextServerTest::_font_set_hinting(const RID &p_font_rid, Hinting p_hinting){
}

/*Hinting*/ int64_t TextServerTest::_font_get_hinting(const RID &p_font_rid) const{
    return 0;
}

void TextServerTest::_font_set_variation_coordinates(const RID &p_font_rid, const Dictionary &p_variation_coordinates){
}

Dictionary TextServerTest::_font_get_variation_coordinates(const RID &p_font_rid) const{
    return Dictionary();
}

void TextServerTest::_font_set_oversampling(const RID &p_font_rid, double p_oversampling){
}

double TextServerTest::_font_get_oversampling(const RID &p_font_rid) const{
    return 0.f;
}

Array TextServerTest::_font_get_size_cache_list(const RID &p_font_rid) const{
    return Array();

}

void TextServerTest::_font_clear_size_cache(const RID &p_font_rid){
}

void TextServerTest::_font_remove_size_cache(const RID &p_font_rid, const Vector2i &p_size){
}

void TextServerTest::_font_set_ascent(const RID &p_font_rid, int64_t p_size, double p_ascent){
}

double TextServerTest::_font_get_ascent(const RID &p_font_rid, int64_t p_size) const{
    return 0.f;
}

void TextServerTest::_font_set_descent(const RID &p_font_rid, int64_t p_size, double p_descent){
}

double TextServerTest::_font_get_descent(const RID &p_font_rid, int64_t p_size) const{
    return 0.f;
}

void TextServerTest::_font_set_underline_position(const RID &p_font_rid, int64_t p_size, double p_underline_position){
}

double TextServerTest::_font_get_underline_position(const RID &p_font_rid, int64_t p_size) const{
    return 0.f;
}

void TextServerTest::_font_set_underline_thickness(const RID &p_font_rid, int64_t p_size, double p_underline_thickness){
}

double TextServerTest::_font_get_underline_thickness(const RID &p_font_rid, int64_t p_size) const{
    return 0.f;
}

void TextServerTest::_font_set_scale(const RID &p_font_rid, int64_t p_size, double p_scale){
}

double TextServerTest::_font_get_scale(const RID &p_font_rid, int64_t p_size) const{
    return 0.f;
}

void TextServerTest::_font_set_spacing(const RID &p_font_rid, int64_t p_size, SpacingType p_spacing, int64_t p_value){
}

int64_t TextServerTest::_font_get_spacing(const RID &p_font_rid, int64_t p_size, SpacingType p_spacing) const{
	return 0;
}

int64_t TextServerTest::_font_get_texture_count(const RID &p_font_rid, const Vector2i &p_size) const{
    return 0;
}

void TextServerTest::_font_clear_textures(const RID &p_font_rid, const Vector2i &p_size){
}

void TextServerTest::_font_remove_texture(const RID &p_font_rid, const Vector2i &p_size, int64_t p_texture_index){
}

void TextServerTest::_font_set_texture_image(const RID &p_font_rid, const Vector2i &p_size, int64_t p_texture_index, const Ref<Image> &p_image){
}

Ref<Image> TextServerTest::_font_get_texture_image(const RID &p_font_rid, const Vector2i &p_size, int64_t p_texture_index) const{
	Ref<Image> img;
    img.instantiate();
	return img;
}

void TextServerTest::_font_set_texture_offsets(const RID &p_font_rid, const Vector2i &p_size, int64_t p_texture_index, const PackedInt32Array &p_offset){
}

PackedInt32Array TextServerTest::_font_get_texture_offsets(const RID &p_font_rid, const Vector2i &p_size, int64_t p_texture_index) const{
    return PackedInt32Array();
}

Array TextServerTest::_font_get_glyph_list(const RID &p_font_rid, const Vector2i &p_size) const{
    return Array();
}

void TextServerTest::_font_clear_glyphs(const RID &p_font_rid, const Vector2i &p_size){
}

void TextServerTest::_font_remove_glyph(const RID &p_font_rid, const Vector2i &p_size, int64_t p_glyph){
}

Vector2 TextServerTest::_font_get_glyph_advance(const RID &p_font_rid, int64_t p_size, int64_t p_glyph) const{
    return Vector2();
}

void TextServerTest::_font_set_glyph_advance(const RID &p_font_rid, int64_t p_size, int64_t p_glyph, const Vector2 &p_advance){
}

Vector2 TextServerTest::_font_get_glyph_offset(const RID &p_font_rid, const Vector2i &p_size, int64_t p_glyph) const{
    return Vector2();
}

void TextServerTest::_font_set_glyph_offset(const RID &p_font_rid, const Vector2i &p_size, int64_t p_glyph, const Vector2 &p_offset){
}

Vector2 TextServerTest::_font_get_glyph_size(const RID &p_font_rid, const Vector2i &p_size, int64_t p_glyph) const{
	return Vector2();
}

void TextServerTest::_font_set_glyph_size(const RID &p_font_rid, const Vector2i &p_size, int64_t p_glyph, const Vector2 &p_gl_size){
}

Rect2 TextServerTest::_font_get_glyph_uv_rect(const RID &p_font_rid, const Vector2i &p_size, int64_t p_glyph) const{
	return Rect2();
}

void TextServerTest::_font_set_glyph_uv_rect(const RID &p_font_rid, const Vector2i &p_size, int64_t p_glyph, const Rect2 &p_uv_rect){
}

int64_t TextServerTest::_font_get_glyph_texture_idx(const RID &p_font_rid, const Vector2i &p_size, int64_t p_glyph) const{
    return 0;
}

void TextServerTest::_font_set_glyph_texture_idx(const RID &p_font_rid, const Vector2i &p_size, int64_t p_glyph, int64_t p_texture_idx){
}

Dictionary TextServerTest::_font_get_glyph_contours(const RID &p_font_rid, int64_t p_size, int64_t p_index) const{
    return Dictionary();
}

Array TextServerTest::_font_get_kerning_list(const RID &p_font_rid, int64_t p_size) const{
    return Array();
}

void TextServerTest::_font_clear_kerning_map(const RID &p_font_rid, int64_t p_size){
}

void TextServerTest::_font_remove_kerning(const RID &p_font_rid, int64_t p_size, const Vector2i &p_glyph_pair){
}

void TextServerTest::_font_set_kerning(const RID &p_font_rid, int64_t p_size, const Vector2i &p_glyph_pair, const Vector2 &p_kerning){
}

Vector2 TextServerTest::_font_get_kerning(const RID &p_font_rid, int64_t p_size, const Vector2i &p_glyph_pair) const{
    return Vector2();
}

int64_t TextServerTest::_font_get_glyph_index(const RID &p_font_rid, int64_t p_size, int64_t p_char, int64_t p_variation_selector) const{
	return 0;
}

bool TextServerTest::_font_has_char(const RID &p_font_rid, int64_t p_char) const{
    return false;
}

String TextServerTest::_font_get_supported_chars(const RID &p_font_rid) const{
    return ""; 
}

void TextServerTest::_font_render_range(const RID &p_font_rid, const Vector2i &p_size, int64_t p_start, int64_t p_end){
}

void TextServerTest::_font_render_glyph(const RID &p_font_rid, const Vector2i &p_size, int64_t p_index){
}

void TextServerTest::_font_draw_glyph(const RID &p_font_rid, const RID &p_canvas, int64_t p_size, const Vector2 &p_pos, int64_t p_index, const Color &p_color) const{
}

void TextServerTest::_font_draw_glyph_outline(const RID &p_font_rid, const RID &p_canvas, int64_t p_size, int64_t p_outline_size, const Vector2 &p_pos, int64_t p_index, const Color &p_color) const{
}

bool TextServerTest::_font_is_language_supported(const RID &p_font_rid, const String &p_language) const{
	return true;
}

void TextServerTest::_font_set_language_support_override(const RID &p_font_rid, const String &p_language, bool p_supported){
}

bool TextServerTest::_font_get_language_support_override(const RID &p_font_rid, const String &p_language){
    return false;
}

void TextServerTest::_font_remove_language_support_override(const RID &p_font_rid, const String &p_language){
}

PackedStringArray TextServerTest::_font_get_language_support_overrides(const RID &p_font_rid){
    return PackedStringArray();
}

bool TextServerTest::_font_is_script_supported(const RID &p_font_rid, const String &p_script) const{
    return false;
}

void TextServerTest::_font_set_script_support_override(const RID &p_font_rid, const String &p_script, bool p_supported){
}

bool TextServerTest::_font_get_script_support_override(const RID &p_font_rid, const String &p_script){
	return false;
}

void TextServerTest::_font_remove_script_support_override(const RID &p_font_rid, const String &p_script){
}

PackedStringArray TextServerTest::_font_get_script_support_overrides(const RID &p_font_rid){
    return PackedStringArray();
}

Dictionary TextServerTest::_font_supported_feature_list(const RID &p_font_rid) const{
    return Dictionary();
}

Dictionary TextServerTest::_font_supported_variation_list(const RID &p_font_rid) const{
    return Dictionary();
}

double TextServerTest::_font_get_global_oversampling() const{
    return 0.f;
}

void TextServerTest::_font_set_global_oversampling(double p_oversampling){
}

Vector2 TextServerTest::_get_hex_code_box_size(int64_t p_size, int64_t p_index) const{
    return Vector2();
}

void TextServerTest::_draw_hex_code_box(const RID &p_canvas, int64_t p_size, const Vector2 &p_pos, int64_t p_index, const Color &p_color) const{
}

/*************************************************************************/
/* Shaped text buffer interface                                          */
/*************************************************************************/

RID TextServerTest::_create_shaped_text(Direction p_direction, Orientation p_orientation){
    return RID();
}

void TextServerTest::_shaped_text_clear(const RID &p_shaped){
}

void TextServerTest::_shaped_text_set_direction(const RID &p_shaped, Direction p_direction){
}

/*Direction*/ int64_t TextServerTest::_shaped_text_get_direction(const RID &p_shaped) const{
    return 0;
}

void TextServerTest::_shaped_text_set_bidi_override(const RID &p_shaped, const Array &p_override){
}

void TextServerTest::_shaped_text_set_orientation(const RID &p_shaped, Orientation p_orientation){
}

/*Orientation*/ int64_t TextServerTest::_shaped_text_get_orientation(const RID &p_shaped) const{
    return 0;
}

void TextServerTest::_shaped_text_set_preserve_invalid(const RID &p_shaped, bool p_enabled){
}

bool TextServerTest::_shaped_text_get_preserve_invalid(const RID &p_shaped) const{
    return false;
}

void TextServerTest::_shaped_text_set_preserve_control(const RID &p_shaped, bool p_enabled){
}

bool TextServerTest::_shaped_text_get_preserve_control(const RID &p_shaped) const{
    return false;
}

bool TextServerTest::_shaped_text_add_string(const RID &p_shaped, const String &p_text, const Array &p_fonts, int64_t p_size, const Dictionary &p_opentype_features, const String &p_language){
	return true;
}

bool TextServerTest::_shaped_text_add_object(const RID &p_shaped, const Variant &p_key, const Vector2 &p_size, InlineAlign p_inline_align, int64_t p_length){
	return true;
}

bool TextServerTest::_shaped_text_resize_object(const RID &p_shaped, const Variant &p_key, const Vector2 &p_size, InlineAlign p_inline_align){
    return true;
}

RID TextServerTest::_shaped_text_substr(const RID &p_shaped, int64_t p_start, int64_t p_length) const{
	return RID();
}

RID TextServerTest::_shaped_text_get_parent(const RID &p_shaped) const{
    return RID();
}

double TextServerTest::_shaped_text_fit_to_width(const RID &p_shaped, double p_width, int64_t p_jst_flags){
    return 0.f;
}

double TextServerTest::_shaped_text_tab_align(const RID &p_shaped, const PackedFloat32Array &p_tab_stops){
	return 0.f;
}

bool TextServerTest::_shaped_text_shape(const RID &p_shaped){
	return true;
}

bool TextServerTest::_shaped_text_update_breaks(const RID &p_shaped){
	return true;
}

bool TextServerTest::_shaped_text_update_justification_ops(const RID &p_shaped){
	return true;
}

bool TextServerTest::_shaped_text_is_ready(const RID &p_shaped) const{
    return false;
}

void TextServerTest::_shaped_text_get_glyphs(const RID &p_shaped, const Glyph **r_glyphs) const {
}

void TextServerTest::_shaped_text_sort_logical(const RID &p_shaped, const Glyph **r_glyphs) {
}

int64_t TextServerTest::_shaped_text_get_glyph_count(const RID &p_shaped) const{
    return 0;
}

Vector2i TextServerTest::_shaped_text_get_range(const RID &p_shaped) const{
	return Vector2i();
}

PackedInt32Array TextServerTest::_shaped_text_get_line_breaks_adv(const RID &p_shaped, const PackedFloat32Array &p_width, int64_t p_start, bool p_once, int64_t p_break_flags) const{
    return PackedInt32Array();
}

PackedInt32Array TextServerTest::_shaped_text_get_line_breaks(const RID &p_shaped, double p_width, int64_t p_start, int64_t p_break_flags) const{
	return PackedInt32Array();
}

PackedInt32Array TextServerTest::_shaped_text_get_word_breaks(const RID &p_shaped, int64_t p_grapheme_flags) const{
	return PackedInt32Array();
}

int64_t TextServerTest::_shaped_text_get_trim_pos(const RID &p_shaped) const{
	return 0;
}

int64_t TextServerTest::_shaped_text_get_ellipsis_pos(const RID &p_shaped) const{
	return 0;
}

int64_t TextServerTest::_shaped_text_get_ellipsis_glyph_count(const RID &p_shaped) const{
	return 0;
}

void TextServerTest::_shaped_text_get_ellipsis_glyphs(const RID &p_shaped, const Glyph **r_glyphs) const {
}

void TextServerTest::_shaped_text_overrun_trim_to_width(const RID &p_shaped_line, double p_width, int64_t p_trim_flags){
}

Array TextServerTest::_shaped_text_get_objects(const RID &p_shaped) const{
	return Array();
}

Rect2 TextServerTest::_shaped_text_get_object_rect(const RID &p_shaped, const Variant &p_key) const{
	return Rect2();
}

Vector2 TextServerTest::_shaped_text_get_size(const RID &p_shaped) const{
	return Vector2();
}

double TextServerTest::_shaped_text_get_ascent(const RID &p_shaped) const{
	return 0.f;
}

double TextServerTest::_shaped_text_get_descent(const RID &p_shaped) const{
	return 0.f;
}

double TextServerTest::_shaped_text_get_width(const RID &p_shaped) const{
	return 0.f;
}

double TextServerTest::_shaped_text_get_underline_position(const RID &p_shaped) const{
	return 0.f;
}

double TextServerTest::_shaped_text_get_underline_thickness(const RID &p_shaped) const{
	return 0.f;
}

int64_t TextServerTest::_shaped_text_get_dominant_direction_in_range(const RID &p_shaped, int64_t p_start, int64_t p_end) const{
	return 0;
}

void TextServerTest::_shaped_text_get_carets(const RID &p_shaped, int64_t p_position, CaretInfo *r_caret) const {
}

PackedVector2Array TextServerTest::_shaped_text_get_selection(const RID &p_shaped, int64_t p_start, int64_t p_end) const{
	return PackedVector2Array();
}

int64_t TextServerTest::_shaped_text_hit_test_grapheme(const RID &p_shaped, double p_coord) const{
	return 0;
}

int64_t TextServerTest::_shaped_text_hit_test_position(const RID &p_shaped, double p_coord) const{
	return 0;
}

void TextServerTest::_shaped_text_draw(const RID &p_shaped, const RID &p_canvas, const Vector2 &p_pos, double p_clip_l, double p_clip_r, const Color &p_color) const{
}

void TextServerTest::_shaped_text_draw_outline(const RID &p_shaped, const RID &p_canvas, const Vector2 &p_pos, double p_clip_l, double p_clip_r, int64_t p_outline_size, const Color &p_color) const{
}

int64_t TextServerTest::_shaped_text_next_grapheme_pos(const RID &p_shaped, int64_t p_pos) const{
	return 0;
}

int64_t TextServerTest::_shaped_text_prev_grapheme_pos(const RID &p_shaped, int64_t p_pos) const{
	return 0;
}

String TextServerTest::_format_number(const String &p_string, const String &p_language) const{
	return "";
}

String TextServerTest::_parse_number(const String &p_string, const String &p_language) const{
	return "";
}

String TextServerTest::_percent_sign(const String &p_language) const {
	return "";
}

TextServerTest::TextServerTest() {
    printf("::: ts create\n");
}

TextServerTest::~TextServerTest() {
    printf("::: ts dt\n");
}
