#ifndef TS_TEST_H
#define TS_TEST_H

#include <godot_cpp/godot.hpp>
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/core/memory.hpp>
#include <godot_cpp/core/error_macros.hpp>

#include <godot_cpp/classes/image.hpp>
#include <godot_cpp/classes/image_texture.hpp>

#include <godot_cpp/classes/font.hpp>
#include <godot_cpp/classes/font_data.hpp>

#include <godot_cpp/classes/text_server.hpp>

#include <godot_cpp/classes/translation.hpp>
#include <godot_cpp/classes/translation_server.hpp>

#include <godot_cpp/classes/caret_info.hpp>
#include <godot_cpp/classes/glyph.hpp>

#include <godot_cpp/classes/mutex.hpp>

#include <godot_cpp/classes/text_server_extension.hpp>
#include <godot_cpp/classes/text_server_manager.hpp>

#include <godot_cpp/classes/rendering_server.hpp>

#include <godot_cpp/variant/utility_functions.hpp>

#include "rid_owner.h" //TODO move to godot-cpp

namespace godot {

// ========================================= //
// FIXME: Move to godot-cpp                  //
// ========================================= //

template <class MutexT>
class MutexLock {
	const MutexT &mutex;

public:
	_ALWAYS_INLINE_ explicit MutexLock(const MutexT &p_mutex) :
			mutex(p_mutex) {
		mutex.lock();
	}

	_ALWAYS_INLINE_ ~MutexLock() {
		mutex.unlock();
	}
};

GDVIRTUAL_NATIVE_PTR(Glyph *);
GDVIRTUAL_NATIVE_PTR(CaretInfo);

MAKE_PTRARGCONV(TextServer::Direction, int64_t);
MAKE_PTRARGCONV(TextServer::Orientation, int64_t);
MAKE_PTRARGCONV(TextServer::Hinting, int64_t);
MAKE_PTRARGCONV(TextServer::Feature, int64_t);
MAKE_PTRARGCONV(TextServer::ContourPointTag, int64_t);
MAKE_PTRARGCONV(TextServer::SpacingType, int64_t);
MAKE_PTRARGCONV(InlineAlign, int64_t);

#define memalloc(m_size) Memory::alloc_static(m_size)
#define memrealloc(m_mem, m_size) Memory::realloc_static(m_mem, m_size)
#define memfree(m_mem) Memory::free_static(m_mem)

#define _THREAD_SAFE_CLASS_ mutable Mutex _thread_safe_;
#define _THREAD_SAFE_METHOD_ MutexLock _thread_safe_method_(_thread_safe_);
#define _THREAD_SAFE_LOCK_ _thread_safe_.lock();
#define _THREAD_SAFE_UNLOCK_ _thread_safe_.unlock();

#ifndef ABS
#define ABS(m_v) (((m_v) < 0) ? (-(m_v)) : (m_v))
#endif

#ifndef SGN
#define SGN(m_v) (((m_v) == 0) ? (0.0) : (((m_v) < 0) ? (-1.0) : (+1.0)))
#endif

#ifndef MIN
#define MIN(m_a, m_b) (((m_a) < (m_b)) ? (m_a) : (m_b))
#endif

#ifndef MAX
#define MAX(m_a, m_b) (((m_a) > (m_b)) ? (m_a) : (m_b))
#endif

#ifndef CLAMP
#define CLAMP(m_a, m_min, m_max) (((m_a) < (m_min)) ? (m_min) : (((m_a) > (m_max)) ? m_max : m_a))
#endif

/*************************************************************************/
/*************************************************************************/
/*************************************************************************/
/*************************************************************************/
/*************************************************************************/

class TextServerTest : public TextServerExtension {
	GDCLASS(TextServerTest, TextServerExtension);
	_THREAD_SAFE_CLASS_

	static uint32_t interface_features;

protected:
	static void _bind_methods() {};

public:
	virtual bool _has_feature(Feature p_feature) const;
	virtual String _get_name() const;
	virtual int64_t _get_features() const;

	virtual void _free(const RID &p_rid);
	virtual bool _has(const RID &p_rid);
	virtual bool _load_support_data(const String &p_filename);

	virtual String _get_support_data_filename() const;
	virtual String _get_support_data_info() const;
	virtual bool _save_support_data(const String &p_filename) const;

	virtual bool _is_locale_right_to_left(const String &p_locale) const;

	virtual int64_t _name_to_tag(const String &p_name) const;
	virtual String _tag_to_name(int64_t p_tag) const;

	/* Font interface */
	virtual RID _create_font();

	virtual void _font_set_data(const RID &p_font_rid, const PackedByteArray &p_data);
	virtual void _font_set_data_ptr(const RID &p_font_rid, const uint8_t *p_p_data_ptr, int64_t p_data_size);

	virtual void _font_set_antialiased(const RID &p_font_rid, bool p_antialiased);
	virtual bool _font_is_antialiased(const RID &p_font_rid) const;

	virtual void _font_set_multichannel_signed_distance_field(const RID &p_font_rid, bool p_msdf);
	virtual bool _font_is_multichannel_signed_distance_field(const RID &p_font_rid) const;

	virtual void _font_set_msdf_pixel_range(const RID &p_font_rid, int64_t p_msdf_pixel_range);
	virtual int64_t _font_get_msdf_pixel_range(const RID &p_font_rid) const;

	virtual void _font_set_msdf_size(const RID &p_font_rid, int64_t p_msdf_size);
	virtual int64_t _font_get_msdf_size(const RID &p_font_rid) const;

	virtual void _font_set_fixed_size(const RID &p_font_rid, int64_t p_fixed_size);
	virtual int64_t _font_get_fixed_size(const RID &p_font_rid) const;

	virtual void _font_set_force_autohinter(const RID &p_font_rid, bool p_force_autohinter);
	virtual bool _font_is_force_autohinter(const RID &p_font_rid) const;

	virtual void _font_set_hinting(const RID &p_font_rid, Hinting p_hinting);
	virtual /*Hinting*/ int64_t _font_get_hinting(const RID &p_font_rid) const;

	virtual void _font_set_variation_coordinates(const RID &p_font_rid, const Dictionary &p_variation_coordinates);
	virtual Dictionary _font_get_variation_coordinates(const RID &p_font_rid) const;

	virtual void _font_set_oversampling(const RID &p_font_rid, double p_oversampling);
	virtual double _font_get_oversampling(const RID &p_font_rid) const;

	virtual Array _font_get_size_cache_list(const RID &p_font_rid) const;
	virtual void _font_clear_size_cache(const RID &p_font_rid);
	virtual void _font_remove_size_cache(const RID &p_font_rid, const Vector2i &p_size);

	virtual void _font_set_ascent(const RID &p_font_rid, int64_t p_size, double p_ascent);
	virtual double _font_get_ascent(const RID &p_font_rid, int64_t p_size) const;

	virtual void _font_set_descent(const RID &p_font_rid, int64_t p_size, double p_descent);
	virtual double _font_get_descent(const RID &p_font_rid, int64_t p_size) const;

	virtual void _font_set_underline_position(const RID &p_font_rid, int64_t p_size, double p_underline_position);
	virtual double _font_get_underline_position(const RID &p_font_rid, int64_t p_size) const;

	virtual void _font_set_underline_thickness(const RID &p_font_rid, int64_t p_size, double p_underline_thickness);
	virtual double _font_get_underline_thickness(const RID &p_font_rid, int64_t p_size) const;

	virtual void _font_set_scale(const RID &p_font_rid, int64_t p_size, double p_scale);
	virtual double _font_get_scale(const RID &p_font_rid, int64_t p_size) const;

	virtual void _font_set_spacing(const RID &p_font_rid, int64_t p_size, SpacingType p_spacing, int64_t p_value);
	virtual int64_t _font_get_spacing(const RID &p_font_rid, int64_t p_size, SpacingType p_spacing) const;

	virtual int64_t _font_get_texture_count(const RID &p_font_rid, const Vector2i &p_size) const;
	virtual void _font_clear_textures(const RID &p_font_rid, const Vector2i &p_size);
	virtual void _font_remove_texture(const RID &p_font_rid, const Vector2i &p_size, int64_t p_texture_index);

	virtual void _font_set_texture_image(const RID &p_font_rid, const Vector2i &p_size, int64_t p_texture_index, const Ref<Image> &p_image);
	virtual Ref<Image> _font_get_texture_image(const RID &p_font_rid, const Vector2i &p_size, int64_t p_texture_index) const;

	virtual void _font_set_texture_offsets(const RID &p_font_rid, const Vector2i &p_size, int64_t p_texture_index, const PackedInt32Array &p_offset);
	virtual PackedInt32Array _font_get_texture_offsets(const RID &p_font_rid, const Vector2i &p_size, int64_t p_texture_index) const;

	virtual Array _font_get_glyph_list(const RID &p_font_rid, const Vector2i &p_size) const;
	virtual void _font_clear_glyphs(const RID &p_font_rid, const Vector2i &p_size);
	virtual void _font_remove_glyph(const RID &p_font_rid, const Vector2i &p_size, int64_t p_glyph);

	virtual Vector2 _font_get_glyph_advance(const RID &p_font_rid, int64_t p_size, int64_t p_glyph) const;
	virtual void _font_set_glyph_advance(const RID &p_font_rid, int64_t p_size, int64_t p_glyph, const Vector2 &p_advance);

	virtual Vector2 _font_get_glyph_offset(const RID &p_font_rid, const Vector2i &p_size, int64_t p_glyph) const;
	virtual void _font_set_glyph_offset(const RID &p_font_rid, const Vector2i &p_size, int64_t p_glyph, const Vector2 &p_offset);

	virtual Vector2 _font_get_glyph_size(const RID &p_font_rid, const Vector2i &p_size, int64_t p_glyph) const;
	virtual void _font_set_glyph_size(const RID &p_font_rid, const Vector2i &p_size, int64_t p_glyph, const Vector2 &p_gl_size);

	virtual Rect2 _font_get_glyph_uv_rect(const RID &p_font_rid, const Vector2i &p_size, int64_t p_glyph) const;
	virtual void _font_set_glyph_uv_rect(const RID &p_font_rid, const Vector2i &p_size, int64_t p_glyph, const Rect2 &p_uv_rect);

	virtual int64_t _font_get_glyph_texture_idx(const RID &p_font_rid, const Vector2i &p_size, int64_t p_glyph) const;
	virtual void _font_set_glyph_texture_idx(const RID &p_font_rid, const Vector2i &p_size, int64_t p_glyph, int64_t p_texture_idx);

	virtual Dictionary _font_get_glyph_contours(const RID &p_font_rid, int64_t p_size, int64_t p_index) const;

	virtual Array _font_get_kerning_list(const RID &p_font_rid, int64_t p_size) const;
	virtual void _font_clear_kerning_map(const RID &p_font_rid, int64_t p_size);
	virtual void _font_remove_kerning(const RID &p_font_rid, int64_t p_size, const Vector2i &p_glyph_pair);

	virtual void _font_set_kerning(const RID &p_font_rid, int64_t p_size, const Vector2i &p_glyph_pair, const Vector2 &p_kerning);
	virtual Vector2 _font_get_kerning(const RID &p_font_rid, int64_t p_size, const Vector2i &p_glyph_pair) const;

	virtual int64_t _font_get_glyph_index(const RID &p_font_rid, int64_t p_size, int64_t p_char, int64_t p_variation_selector) const;

	virtual bool _font_has_char(const RID &p_font_rid, int64_t p_char) const;
	virtual String _font_get_supported_chars(const RID &p_font_rid) const;

	virtual void _font_render_range(const RID &p_font_rid, const Vector2i &p_size, int64_t p_start, int64_t p_end);
	virtual void _font_render_glyph(const RID &p_font_rid, const Vector2i &p_size, int64_t p_index);

	virtual void _font_draw_glyph(const RID &p_font_rid, const RID &p_canvas, int64_t p_size, const Vector2 &p_pos, int64_t p_index, const Color &p_color) const;
	virtual void _font_draw_glyph_outline(const RID &p_font_rid, const RID &p_canvas, int64_t p_size, int64_t p_outline_size, const Vector2 &p_pos, int64_t p_index, const Color &p_color) const;

	virtual bool _font_is_language_supported(const RID &p_font_rid, const String &p_language) const;
	virtual void _font_set_language_support_override(const RID &p_font_rid, const String &p_language, bool p_supported);
	virtual bool _font_get_language_support_override(const RID &p_font_rid, const String &p_language);
	virtual void _font_remove_language_support_override(const RID &p_font_rid, const String &p_language);
	virtual PackedStringArray _font_get_language_support_overrides(const RID &p_font_rid);

	virtual bool _font_is_script_supported(const RID &p_font_rid, const String &p_script) const;
	virtual void _font_set_script_support_override(const RID &p_font_rid, const String &p_script, bool p_supported);
	virtual bool _font_get_script_support_override(const RID &p_font_rid, const String &p_script);
	virtual void _font_remove_script_support_override(const RID &p_font_rid, const String &p_script);
	virtual PackedStringArray _font_get_script_support_overrides(const RID &p_font_rid);

	virtual Dictionary _font_supported_feature_list(const RID &p_font_rid) const;
	virtual Dictionary _font_supported_variation_list(const RID &p_font_rid) const;

	virtual double _font_get_global_oversampling() const;
	virtual void _font_set_global_oversampling(double p_oversampling);

	virtual Vector2 _get_hex_code_box_size(int64_t p_size, int64_t p_index) const;
	virtual void _draw_hex_code_box(const RID &p_canvas, int64_t p_size, const Vector2 &p_pos, int64_t p_index, const Color &p_color) const;

	/* Shaped text buffer interface */

	virtual RID _create_shaped_text(Direction p_direction, Orientation p_orientation);

	virtual void _shaped_text_clear(const RID &p_shaped);

	virtual void _shaped_text_set_direction(const RID &p_shaped, Direction p_direction);
	virtual /*Direction*/ int64_t _shaped_text_get_direction(const RID &p_shaped) const;

	virtual void _shaped_text_set_bidi_override(const RID &p_shaped, const Array &p_override);

	virtual void _shaped_text_set_orientation(const RID &p_shaped, Orientation p_orientation);
	virtual /*Orientation*/ int64_t _shaped_text_get_orientation(const RID &p_shaped) const;

	virtual void _shaped_text_set_preserve_invalid(const RID &p_shaped, bool p_enabled);
	virtual bool _shaped_text_get_preserve_invalid(const RID &p_shaped) const;

	virtual void _shaped_text_set_preserve_control(const RID &p_shaped, bool p_enabled);
	virtual bool _shaped_text_get_preserve_control(const RID &p_shaped) const;

	virtual bool _shaped_text_add_string(const RID &p_shaped, const String &p_text, const Array &p_fonts, int64_t p_size, const Dictionary &p_opentype_features, const String &p_language);
	virtual bool _shaped_text_add_object(const RID &p_shaped, const Variant &p_key, const Vector2 &p_size, InlineAlign p_inline_align, int64_t p_length);
	virtual bool _shaped_text_resize_object(const RID &p_shaped, const Variant &p_key, const Vector2 &p_size, InlineAlign p_inline_align);

	virtual RID _shaped_text_substr(const RID &p_shaped, int64_t p_start, int64_t p_length) const;
	virtual RID _shaped_text_get_parent(const RID &p_shaped) const;

	virtual double _shaped_text_fit_to_width(const RID &p_shaped, double p_width, int64_t p_jst_flags);
	virtual double _shaped_text_tab_align(const RID &p_shaped, const PackedFloat32Array &p_tab_stops);
	virtual bool _shaped_text_shape(const RID &p_shaped);
	virtual bool _shaped_text_update_breaks(const RID &p_shaped);
	virtual bool _shaped_text_update_justification_ops(const RID &p_shaped);

	virtual bool _shaped_text_is_ready(const RID &p_shaped) const;

	virtual void _shaped_text_get_glyphs(const RID &p_shaped, const Glyph **r_glyphs) const;
	virtual void _shaped_text_sort_logical(const RID &p_shaped, const Glyph **r_glyphs);
	virtual int64_t _shaped_text_get_glyph_count(const RID &p_shaped) const;

	virtual Vector2i _shaped_text_get_range(const RID &p_shaped) const;

	virtual PackedInt32Array _shaped_text_get_line_breaks_adv(const RID &p_shaped, const PackedFloat32Array &p_width, int64_t p_start, bool p_once, int64_t p_break_flags) const;
	virtual PackedInt32Array _shaped_text_get_line_breaks(const RID &p_shaped, double p_width, int64_t p_start, int64_t p_break_flags) const;
	virtual PackedInt32Array _shaped_text_get_word_breaks(const RID &p_shaped, int64_t p_grapheme_flags) const;

	virtual int64_t _shaped_text_get_trim_pos(const RID &p_shaped) const;
	virtual int64_t _shaped_text_get_ellipsis_pos(const RID &p_shaped) const;
	virtual int64_t _shaped_text_get_ellipsis_glyph_count(const RID &p_shaped) const;
	virtual void _shaped_text_get_ellipsis_glyphs(const RID &p_shaped, const Glyph **r_glyphs) const;

	virtual void _shaped_text_overrun_trim_to_width(const RID &p_shaped, double p_width, int64_t p_trim_flags);

	virtual Array _shaped_text_get_objects(const RID &p_shaped) const;
	virtual Rect2 _shaped_text_get_object_rect(const RID &p_shaped, const Variant &p_key) const;

	virtual Vector2 _shaped_text_get_size(const RID &p_shaped) const;
	virtual double _shaped_text_get_ascent(const RID &p_shaped) const;
	virtual double _shaped_text_get_descent(const RID &p_shaped) const;
	virtual double _shaped_text_get_width(const RID &p_shaped) const;
	virtual double _shaped_text_get_underline_position(const RID &p_shaped) const;
	virtual double _shaped_text_get_underline_thickness(const RID &p_shaped) const;

	virtual int64_t _shaped_text_get_dominant_direction_in_range(const RID &p_shaped, int64_t p_start, int64_t p_end) const;

	virtual void _shaped_text_get_carets(const RID &p_shaped, int64_t p_position, CaretInfo *r_caret) const;
	virtual PackedVector2Array _shaped_text_get_selection(const RID &p_shaped, int64_t start, int64_t p_end) const;

	virtual int64_t _shaped_text_hit_test_grapheme(const RID &p_shaped, double p_coord) const;
	virtual int64_t _shaped_text_hit_test_position(const RID &p_shaped, double p_coord) const;

	virtual void _shaped_text_draw(const RID &p_shaped, const RID &p_canvas, const Vector2 &p_pos, double p_clip_l, double p_clip_r, const Color &p_color) const;
	virtual void _shaped_text_draw_outline(const RID &p_shaped, const RID &p_canvas, const Vector2 &p_pos, double p_clip_l, double p_clip_r, int64_t p_outline_size, const Color &p_color) const;

	virtual int64_t _shaped_text_next_grapheme_pos(const RID &p_shaped, int64_t p_pos) const;
	virtual int64_t _shaped_text_prev_grapheme_pos(const RID &p_shaped, int64_t p_pos) const;

	virtual String _format_number(const String &p_string, const String &p_language) const;
	virtual String _parse_number(const String &p_string, const String &p_language) const;
	virtual String _percent_sign(const String &p_language) const;

	TextServerTest();
	~TextServerTest();
};

} /* namespace godot */

#endif /* TS_TEST_H */
