/*************************************************************************/
/*  event_listener_line_edit.h                                           */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2022 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2022 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#ifndef EVENT_LISTENER_LINE_EDIT_H
#define EVENT_LISTENER_LINE_EDIT_H

#include "scene/gui/line_edit.h"

enum InputType {
	INPUT_KEY = 1,
	INPUT_MOUSE_BUTTON = 2,
	INPUT_JOY_BUTTON = 4,
	INPUT_JOY_MOTION = 8
};

class EventListenerLineEdit : public LineEdit {
	GDCLASS(EventListenerLineEdit, LineEdit)

	int allowed_input_types = INPUT_KEY | INPUT_MOUSE_BUTTON | INPUT_JOY_BUTTON | INPUT_JOY_MOTION;
	bool ignore = true;
	bool share_keycodes = false;
	Ref<InputEvent> event;

	bool _is_event_allowed(const Ref<InputEvent> &p_event) const;

	void gui_input(const Ref<InputEvent> &p_event) override;
	void _on_text_changed(const String &p_text);

	void _on_focus();
	void _on_unfocus();

protected:
	void _notification(int p_what);
	static void _bind_methods();

public:
	Ref<InputEvent> get_event() const;
	void clear_event();

	void set_allowed_input_types(int input_types);
	int get_allowed_input_types() const;

public:
	EventListenerLineEdit();
};

#endif // EVENT_LISTENER_LINE_EDIT_H
