/* Generated by wayland-scanner 1.13.0 */

#ifndef TEXT_INPUT_UNSTABLE_V1_SERVER_PROTOCOL_H
#define TEXT_INPUT_UNSTABLE_V1_SERVER_PROTOCOL_H

#include <stdint.h>
#include <stddef.h>
#include "wayland-server.h"

#ifdef  __cplusplus
extern "C" {
#endif

struct wl_client;
struct wl_resource;

/**
 * @page page_text_input_unstable_v1 The text_input_unstable_v1 protocol
 * @section page_ifaces_text_input_unstable_v1 Interfaces
 * - @subpage page_iface_zwp_text_input_v1 - text input
 * - @subpage page_iface_zwp_text_input_manager_v1 - text input manager
 * @section page_copyright_text_input_unstable_v1 Copyright
 * <pre>
 *
 * Copyright © 2012, 2013 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 * </pre>
 */
struct wl_seat;
struct wl_surface;
struct zwp_text_input_manager_v1;
struct zwp_text_input_v1;

/**
 * @page page_iface_zwp_text_input_v1 zwp_text_input_v1
 * @section page_iface_zwp_text_input_v1_desc Description
 *
 * An object used for text input. Adds support for text input and input
 * methods to applications. A text-input object is created from a
 * wl_text_input_manager and corresponds typically to a text entry in an
 * application.
 * Requests are used to activate/deactivate the text-input object and set
 * state information like surrounding and selected text or the content type.
 * The information about entered text is sent to the text-input object via
 * the pre-edit and commit events. Using this interface removes the need
 * for applications to directly process hardware key events and compose text
 * out of them.
 *
 * Text is generally UTF-8 encoded, indices and lengths are in bytes.
 *
 * Serials are used to synchronize the state between the text input and
 * an input method. New serials are sent by the text input in the
 * commit_state request and are used by the input method to indicate
 * the known text input state in events like preedit_string, commit_string,
 * and keysym. The text input can then ignore events from the input method
 * which are based on an outdated state (for example after a reset).
 *
 * Warning! The protocol described in this file is experimental and
 * backward incompatible changes may be made. Backward compatible changes
 * may be added together with the corresponding interface version bump.
 * Backward incompatible changes are done by bumping the version number in
 * the protocol and interface names and resetting the interface version.
 * Once the protocol is to be declared stable, the 'z' prefix and the
 * version number in the protocol and interface names are removed and the
 * interface version number is reset.
 * @section page_iface_zwp_text_input_v1_api API
 * See @ref iface_zwp_text_input_v1.
 */
/**
 * @defgroup iface_zwp_text_input_v1 The zwp_text_input_v1 interface
 *
 * An object used for text input. Adds support for text input and input
 * methods to applications. A text-input object is created from a
 * wl_text_input_manager and corresponds typically to a text entry in an
 * application.
 * Requests are used to activate/deactivate the text-input object and set
 * state information like surrounding and selected text or the content type.
 * The information about entered text is sent to the text-input object via
 * the pre-edit and commit events. Using this interface removes the need
 * for applications to directly process hardware key events and compose text
 * out of them.
 *
 * Text is generally UTF-8 encoded, indices and lengths are in bytes.
 *
 * Serials are used to synchronize the state between the text input and
 * an input method. New serials are sent by the text input in the
 * commit_state request and are used by the input method to indicate
 * the known text input state in events like preedit_string, commit_string,
 * and keysym. The text input can then ignore events from the input method
 * which are based on an outdated state (for example after a reset).
 *
 * Warning! The protocol described in this file is experimental and
 * backward incompatible changes may be made. Backward compatible changes
 * may be added together with the corresponding interface version bump.
 * Backward incompatible changes are done by bumping the version number in
 * the protocol and interface names and resetting the interface version.
 * Once the protocol is to be declared stable, the 'z' prefix and the
 * version number in the protocol and interface names are removed and the
 * interface version number is reset.
 */
extern const struct wl_interface zwp_text_input_v1_interface;
/**
 * @page page_iface_zwp_text_input_manager_v1 zwp_text_input_manager_v1
 * @section page_iface_zwp_text_input_manager_v1_desc Description
 *
 * A factory for text-input objects. This object is a global singleton.
 * @section page_iface_zwp_text_input_manager_v1_api API
 * See @ref iface_zwp_text_input_manager_v1.
 */
/**
 * @defgroup iface_zwp_text_input_manager_v1 The zwp_text_input_manager_v1 interface
 *
 * A factory for text-input objects. This object is a global singleton.
 */
extern const struct wl_interface zwp_text_input_manager_v1_interface;

#ifndef ZWP_TEXT_INPUT_V1_CONTENT_HINT_ENUM
#define ZWP_TEXT_INPUT_V1_CONTENT_HINT_ENUM
/**
 * @ingroup iface_zwp_text_input_v1
 * content hint
 *
 * Content hint is a bitmask to allow to modify the behavior of the text
 * input.
 */
enum zwp_text_input_v1_content_hint {
	/**
	 * no special behaviour
	 */
	ZWP_TEXT_INPUT_V1_CONTENT_HINT_NONE = 0x0,
	/**
	 * auto completion, correction and capitalization
	 */
	ZWP_TEXT_INPUT_V1_CONTENT_HINT_DEFAULT = 0x7,
	/**
	 * hidden and sensitive text
	 */
	ZWP_TEXT_INPUT_V1_CONTENT_HINT_PASSWORD = 0xc0,
	/**
	 * suggest word completions
	 */
	ZWP_TEXT_INPUT_V1_CONTENT_HINT_AUTO_COMPLETION = 0x1,
	/**
	 * suggest word corrections
	 */
	ZWP_TEXT_INPUT_V1_CONTENT_HINT_AUTO_CORRECTION = 0x2,
	/**
	 * switch to uppercase letters at the start of a sentence
	 */
	ZWP_TEXT_INPUT_V1_CONTENT_HINT_AUTO_CAPITALIZATION = 0x4,
	/**
	 * prefer lowercase letters
	 */
	ZWP_TEXT_INPUT_V1_CONTENT_HINT_LOWERCASE = 0x8,
	/**
	 * prefer uppercase letters
	 */
	ZWP_TEXT_INPUT_V1_CONTENT_HINT_UPPERCASE = 0x10,
	/**
	 * prefer casing for titles and headings (can be language dependent)
	 */
	ZWP_TEXT_INPUT_V1_CONTENT_HINT_TITLECASE = 0x20,
	/**
	 * characters should be hidden
	 */
	ZWP_TEXT_INPUT_V1_CONTENT_HINT_HIDDEN_TEXT = 0x40,
	/**
	 * typed text should not be stored
	 */
	ZWP_TEXT_INPUT_V1_CONTENT_HINT_SENSITIVE_DATA = 0x80,
	/**
	 * just latin characters should be entered
	 */
	ZWP_TEXT_INPUT_V1_CONTENT_HINT_LATIN = 0x100,
	/**
	 * the text input is multiline
	 */
	ZWP_TEXT_INPUT_V1_CONTENT_HINT_MULTILINE = 0x200,
};
#endif /* ZWP_TEXT_INPUT_V1_CONTENT_HINT_ENUM */

#ifndef ZWP_TEXT_INPUT_V1_CONTENT_PURPOSE_ENUM
#define ZWP_TEXT_INPUT_V1_CONTENT_PURPOSE_ENUM
/**
 * @ingroup iface_zwp_text_input_v1
 * content purpose
 *
 * The content purpose allows to specify the primary purpose of a text
 * input.
 *
 * This allows an input method to show special purpose input panels with
 * extra characters or to disallow some characters.
 */
enum zwp_text_input_v1_content_purpose {
	/**
	 * default input, allowing all characters
	 */
	ZWP_TEXT_INPUT_V1_CONTENT_PURPOSE_NORMAL = 0,
	/**
	 * allow only alphabetic characters
	 */
	ZWP_TEXT_INPUT_V1_CONTENT_PURPOSE_ALPHA = 1,
	/**
	 * allow only digits
	 */
	ZWP_TEXT_INPUT_V1_CONTENT_PURPOSE_DIGITS = 2,
	/**
	 * input a number (including decimal separator and sign)
	 */
	ZWP_TEXT_INPUT_V1_CONTENT_PURPOSE_NUMBER = 3,
	/**
	 * input a phone number
	 */
	ZWP_TEXT_INPUT_V1_CONTENT_PURPOSE_PHONE = 4,
	/**
	 * input an URL
	 */
	ZWP_TEXT_INPUT_V1_CONTENT_PURPOSE_URL = 5,
	/**
	 * input an email address
	 */
	ZWP_TEXT_INPUT_V1_CONTENT_PURPOSE_EMAIL = 6,
	/**
	 * input a name of a person
	 */
	ZWP_TEXT_INPUT_V1_CONTENT_PURPOSE_NAME = 7,
	/**
	 * input a password (combine with password or sensitive_data hint)
	 */
	ZWP_TEXT_INPUT_V1_CONTENT_PURPOSE_PASSWORD = 8,
	/**
	 * input a date
	 */
	ZWP_TEXT_INPUT_V1_CONTENT_PURPOSE_DATE = 9,
	/**
	 * input a time
	 */
	ZWP_TEXT_INPUT_V1_CONTENT_PURPOSE_TIME = 10,
	/**
	 * input a date and time
	 */
	ZWP_TEXT_INPUT_V1_CONTENT_PURPOSE_DATETIME = 11,
	/**
	 * input for a terminal
	 */
	ZWP_TEXT_INPUT_V1_CONTENT_PURPOSE_TERMINAL = 12,
};
#endif /* ZWP_TEXT_INPUT_V1_CONTENT_PURPOSE_ENUM */

#ifndef ZWP_TEXT_INPUT_V1_PREEDIT_STYLE_ENUM
#define ZWP_TEXT_INPUT_V1_PREEDIT_STYLE_ENUM
enum zwp_text_input_v1_preedit_style {
	/**
	 * default style for composing text
	 */
	ZWP_TEXT_INPUT_V1_PREEDIT_STYLE_DEFAULT = 0,
	/**
	 * style should be the same as in non-composing text
	 */
	ZWP_TEXT_INPUT_V1_PREEDIT_STYLE_NONE = 1,
	ZWP_TEXT_INPUT_V1_PREEDIT_STYLE_ACTIVE = 2,
	ZWP_TEXT_INPUT_V1_PREEDIT_STYLE_INACTIVE = 3,
	ZWP_TEXT_INPUT_V1_PREEDIT_STYLE_HIGHLIGHT = 4,
	ZWP_TEXT_INPUT_V1_PREEDIT_STYLE_UNDERLINE = 5,
	ZWP_TEXT_INPUT_V1_PREEDIT_STYLE_SELECTION = 6,
	ZWP_TEXT_INPUT_V1_PREEDIT_STYLE_INCORRECT = 7,
};
#endif /* ZWP_TEXT_INPUT_V1_PREEDIT_STYLE_ENUM */

#ifndef ZWP_TEXT_INPUT_V1_TEXT_DIRECTION_ENUM
#define ZWP_TEXT_INPUT_V1_TEXT_DIRECTION_ENUM
enum zwp_text_input_v1_text_direction {
	/**
	 * automatic text direction based on text and language
	 */
	ZWP_TEXT_INPUT_V1_TEXT_DIRECTION_AUTO = 0,
	/**
	 * left-to-right
	 */
	ZWP_TEXT_INPUT_V1_TEXT_DIRECTION_LTR = 1,
	/**
	 * right-to-left
	 */
	ZWP_TEXT_INPUT_V1_TEXT_DIRECTION_RTL = 2,
};
#endif /* ZWP_TEXT_INPUT_V1_TEXT_DIRECTION_ENUM */

/**
 * @ingroup iface_zwp_text_input_v1
 * @struct zwp_text_input_v1_interface
 */
struct zwp_text_input_v1_interface {
	/**
	 * request activation
	 *
	 * Requests the text-input object to be activated (typically when
	 * the text entry gets focus). The seat argument is a wl_seat which
	 * maintains the focus for this activation. The surface argument is
	 * a wl_surface assigned to the text-input object and tracked for
	 * focus lost. The enter event is emitted on successful activation.
	 */
	void (*activate)(struct wl_client *client,
			 struct wl_resource *resource,
			 struct wl_resource *seat,
			 struct wl_resource *surface);
	/**
	 * request deactivation
	 *
	 * Requests the text-input object to be deactivated (typically
	 * when the text entry lost focus). The seat argument is a wl_seat
	 * which was used for activation.
	 */
	void (*deactivate)(struct wl_client *client,
			   struct wl_resource *resource,
			   struct wl_resource *seat);
	/**
	 * show input panels
	 *
	 * Requests input panels (virtual keyboard) to show.
	 */
	void (*show_input_panel)(struct wl_client *client,
				 struct wl_resource *resource);
	/**
	 * hide input panels
	 *
	 * Requests input panels (virtual keyboard) to hide.
	 */
	void (*hide_input_panel)(struct wl_client *client,
				 struct wl_resource *resource);
	/**
	 * reset
	 *
	 * Should be called by an editor widget when the input state
	 * should be reset, for example after the text was changed outside
	 * of the normal input method flow.
	 */
	void (*reset)(struct wl_client *client,
		      struct wl_resource *resource);
	/**
	 * sets the surrounding text
	 *
	 * Sets the plain surrounding text around the input position.
	 * Text is UTF-8 encoded. Cursor is the byte offset within the
	 * surrounding text. Anchor is the byte offset of the selection
	 * anchor within the surrounding text. If there is no selected text
	 * anchor is the same as cursor.
	 */
	void (*set_surrounding_text)(struct wl_client *client,
				     struct wl_resource *resource,
				     const char *text,
				     uint32_t cursor,
				     uint32_t anchor);
	/**
	 * set content purpose and hint
	 *
	 * Sets the content purpose and content hint. While the purpose
	 * is the basic purpose of an input field, the hint flags allow to
	 * modify some of the behavior.
	 *
	 * When no content type is explicitly set, a normal content purpose
	 * with default hints (auto completion, auto correction, auto
	 * capitalization) should be assumed.
	 */
	void (*set_content_type)(struct wl_client *client,
				 struct wl_resource *resource,
				 uint32_t hint,
				 uint32_t purpose);
	/**
	 */
	void (*set_cursor_rectangle)(struct wl_client *client,
				     struct wl_resource *resource,
				     int32_t x,
				     int32_t y,
				     int32_t width,
				     int32_t height);
	/**
	 * sets preferred language
	 *
	 * Sets a specific language. This allows for example a virtual
	 * keyboard to show a language specific layout. The "language"
	 * argument is a RFC-3066 format language tag.
	 *
	 * It could be used for example in a word processor to indicate
	 * language of currently edited document or in an instant message
	 * application which tracks languages of contacts.
	 */
	void (*set_preferred_language)(struct wl_client *client,
				       struct wl_resource *resource,
				       const char *language);
	/**
	 * @param serial used to identify the known state
	 */
	void (*commit_state)(struct wl_client *client,
			     struct wl_resource *resource,
			     uint32_t serial);
	/**
	 */
	void (*invoke_action)(struct wl_client *client,
			      struct wl_resource *resource,
			      uint32_t button,
			      uint32_t index);
};

#define ZWP_TEXT_INPUT_V1_ENTER 0
#define ZWP_TEXT_INPUT_V1_LEAVE 1
#define ZWP_TEXT_INPUT_V1_MODIFIERS_MAP 2
#define ZWP_TEXT_INPUT_V1_INPUT_PANEL_STATE 3
#define ZWP_TEXT_INPUT_V1_PREEDIT_STRING 4
#define ZWP_TEXT_INPUT_V1_PREEDIT_STYLING 5
#define ZWP_TEXT_INPUT_V1_PREEDIT_CURSOR 6
#define ZWP_TEXT_INPUT_V1_COMMIT_STRING 7
#define ZWP_TEXT_INPUT_V1_CURSOR_POSITION 8
#define ZWP_TEXT_INPUT_V1_DELETE_SURROUNDING_TEXT 9
#define ZWP_TEXT_INPUT_V1_KEYSYM 10
#define ZWP_TEXT_INPUT_V1_LANGUAGE 11
#define ZWP_TEXT_INPUT_V1_TEXT_DIRECTION 12

/**
 * @ingroup iface_zwp_text_input_v1
 */
#define ZWP_TEXT_INPUT_V1_ENTER_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v1
 */
#define ZWP_TEXT_INPUT_V1_LEAVE_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v1
 */
#define ZWP_TEXT_INPUT_V1_MODIFIERS_MAP_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v1
 */
#define ZWP_TEXT_INPUT_V1_INPUT_PANEL_STATE_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v1
 */
#define ZWP_TEXT_INPUT_V1_PREEDIT_STRING_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v1
 */
#define ZWP_TEXT_INPUT_V1_PREEDIT_STYLING_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v1
 */
#define ZWP_TEXT_INPUT_V1_PREEDIT_CURSOR_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v1
 */
#define ZWP_TEXT_INPUT_V1_COMMIT_STRING_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v1
 */
#define ZWP_TEXT_INPUT_V1_CURSOR_POSITION_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v1
 */
#define ZWP_TEXT_INPUT_V1_DELETE_SURROUNDING_TEXT_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v1
 */
#define ZWP_TEXT_INPUT_V1_KEYSYM_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v1
 */
#define ZWP_TEXT_INPUT_V1_LANGUAGE_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v1
 */
#define ZWP_TEXT_INPUT_V1_TEXT_DIRECTION_SINCE_VERSION 1

/**
 * @ingroup iface_zwp_text_input_v1
 */
#define ZWP_TEXT_INPUT_V1_ACTIVATE_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v1
 */
#define ZWP_TEXT_INPUT_V1_DEACTIVATE_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v1
 */
#define ZWP_TEXT_INPUT_V1_SHOW_INPUT_PANEL_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v1
 */
#define ZWP_TEXT_INPUT_V1_HIDE_INPUT_PANEL_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v1
 */
#define ZWP_TEXT_INPUT_V1_RESET_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v1
 */
#define ZWP_TEXT_INPUT_V1_SET_SURROUNDING_TEXT_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v1
 */
#define ZWP_TEXT_INPUT_V1_SET_CONTENT_TYPE_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v1
 */
#define ZWP_TEXT_INPUT_V1_SET_CURSOR_RECTANGLE_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v1
 */
#define ZWP_TEXT_INPUT_V1_SET_PREFERRED_LANGUAGE_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v1
 */
#define ZWP_TEXT_INPUT_V1_COMMIT_STATE_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_text_input_v1
 */
#define ZWP_TEXT_INPUT_V1_INVOKE_ACTION_SINCE_VERSION 1

/**
 * @ingroup iface_zwp_text_input_v1
 * Sends an enter event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
zwp_text_input_v1_send_enter(struct wl_resource *resource_, struct wl_resource *surface)
{
	wl_resource_post_event(resource_, ZWP_TEXT_INPUT_V1_ENTER, surface);
}

/**
 * @ingroup iface_zwp_text_input_v1
 * Sends an leave event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
zwp_text_input_v1_send_leave(struct wl_resource *resource_)
{
	wl_resource_post_event(resource_, ZWP_TEXT_INPUT_V1_LEAVE);
}

/**
 * @ingroup iface_zwp_text_input_v1
 * Sends an modifiers_map event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
zwp_text_input_v1_send_modifiers_map(struct wl_resource *resource_, struct wl_array *map)
{
	wl_resource_post_event(resource_, ZWP_TEXT_INPUT_V1_MODIFIERS_MAP, map);
}

/**
 * @ingroup iface_zwp_text_input_v1
 * Sends an input_panel_state event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
zwp_text_input_v1_send_input_panel_state(struct wl_resource *resource_, uint32_t state)
{
	wl_resource_post_event(resource_, ZWP_TEXT_INPUT_V1_INPUT_PANEL_STATE, state);
}

/**
 * @ingroup iface_zwp_text_input_v1
 * Sends an preedit_string event to the client owning the resource.
 * @param resource_ The client's resource
 * @param serial serial of the latest known text input state
 */
static inline void
zwp_text_input_v1_send_preedit_string(struct wl_resource *resource_, uint32_t serial, const char *text, const char *commit)
{
	wl_resource_post_event(resource_, ZWP_TEXT_INPUT_V1_PREEDIT_STRING, serial, text, commit);
}

/**
 * @ingroup iface_zwp_text_input_v1
 * Sends an preedit_styling event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
zwp_text_input_v1_send_preedit_styling(struct wl_resource *resource_, uint32_t index, uint32_t length, uint32_t style)
{
	wl_resource_post_event(resource_, ZWP_TEXT_INPUT_V1_PREEDIT_STYLING, index, length, style);
}

/**
 * @ingroup iface_zwp_text_input_v1
 * Sends an preedit_cursor event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
zwp_text_input_v1_send_preedit_cursor(struct wl_resource *resource_, int32_t index)
{
	wl_resource_post_event(resource_, ZWP_TEXT_INPUT_V1_PREEDIT_CURSOR, index);
}

/**
 * @ingroup iface_zwp_text_input_v1
 * Sends an commit_string event to the client owning the resource.
 * @param resource_ The client's resource
 * @param serial serial of the latest known text input state
 */
static inline void
zwp_text_input_v1_send_commit_string(struct wl_resource *resource_, uint32_t serial, const char *text)
{
	wl_resource_post_event(resource_, ZWP_TEXT_INPUT_V1_COMMIT_STRING, serial, text);
}

/**
 * @ingroup iface_zwp_text_input_v1
 * Sends an cursor_position event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
zwp_text_input_v1_send_cursor_position(struct wl_resource *resource_, int32_t index, int32_t anchor)
{
	wl_resource_post_event(resource_, ZWP_TEXT_INPUT_V1_CURSOR_POSITION, index, anchor);
}

/**
 * @ingroup iface_zwp_text_input_v1
 * Sends an delete_surrounding_text event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
zwp_text_input_v1_send_delete_surrounding_text(struct wl_resource *resource_, int32_t index, uint32_t length)
{
	wl_resource_post_event(resource_, ZWP_TEXT_INPUT_V1_DELETE_SURROUNDING_TEXT, index, length);
}

/**
 * @ingroup iface_zwp_text_input_v1
 * Sends an keysym event to the client owning the resource.
 * @param resource_ The client's resource
 * @param serial serial of the latest known text input state
 */
static inline void
zwp_text_input_v1_send_keysym(struct wl_resource *resource_, uint32_t serial, uint32_t time, uint32_t sym, uint32_t state, uint32_t modifiers)
{
	wl_resource_post_event(resource_, ZWP_TEXT_INPUT_V1_KEYSYM, serial, time, sym, state, modifiers);
}

/**
 * @ingroup iface_zwp_text_input_v1
 * Sends an language event to the client owning the resource.
 * @param resource_ The client's resource
 * @param serial serial of the latest known text input state
 */
static inline void
zwp_text_input_v1_send_language(struct wl_resource *resource_, uint32_t serial, const char *language)
{
	wl_resource_post_event(resource_, ZWP_TEXT_INPUT_V1_LANGUAGE, serial, language);
}

/**
 * @ingroup iface_zwp_text_input_v1
 * Sends an text_direction event to the client owning the resource.
 * @param resource_ The client's resource
 * @param serial serial of the latest known text input state
 */
static inline void
zwp_text_input_v1_send_text_direction(struct wl_resource *resource_, uint32_t serial, uint32_t direction)
{
	wl_resource_post_event(resource_, ZWP_TEXT_INPUT_V1_TEXT_DIRECTION, serial, direction);
}

/**
 * @ingroup iface_zwp_text_input_manager_v1
 * @struct zwp_text_input_manager_v1_interface
 */
struct zwp_text_input_manager_v1_interface {
	/**
	 * create text input
	 *
	 * Creates a new text-input object.
	 */
	void (*create_text_input)(struct wl_client *client,
				  struct wl_resource *resource,
				  uint32_t id);
};


/**
 * @ingroup iface_zwp_text_input_manager_v1
 */
#define ZWP_TEXT_INPUT_MANAGER_V1_CREATE_TEXT_INPUT_SINCE_VERSION 1

#ifdef  __cplusplus
}
#endif

#endif
