/*
 * main.cpp
 *
 * Copyright (c) 2011 Rickard Edstršm
 * Copyright (c) 2011 Sebastian €rleryd
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "gdt.h"
#include "gdt_gles1.h"
#include <unistd.h> 

#include "Render.h"

const char* TAG = "main.cpp";

Render *r;

boolean state = 0;
static void on_touch(touch_type_t what, int x, int y) {
	if (state) {
		switch (what) {
		case TOUCH_MOVE:
			move(x, y);
			break;
		case TOUCH_UP:
			state = 0;
			break;
		default:
			{}
		}
	} else {
	switch (what) {
	case TOUCH_DOWN:
	if (inside_the_square(x, y)) {
	  state = 1;
	  move(x, y);
	}
	break;
	default:
	{}
	}
	}
}

void gdt_hook_initialize() {
  gdt_log(LOG_DEBUG, TAG, "started");
  
  r = new Render();

  gdt_set_callback_touch(&on_touch);
}

void gdt_hook_exit() {
  gdt_log(LOG_DEBUG, TAG, "exiting");
}

void gdt_hook_visible(int width, int height) {
  gdt_log(LOG_DEBUG, TAG, "visible, screen w=%d h=%d", width, height);
  
  r->setup(width, height);
}

void gdt_hook_hidden(boolean exiting) {

}

void gdt_hook_render() {
	r->render();
}
