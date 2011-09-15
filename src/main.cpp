/*
 * simple_example.c
 *
 * Copyright (c) 2011 Rickard Edström
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

const char* TAG = "main.c"; 

GLint _screen_width;
GLint _screen_height;

// (_x, _y): the current position of the square 
int _x = 100; 
int _y = 100;

Render *r;

static boolean inside_the_square(int x, int y) {
  return (x > _x && x < (_x + 90))
      && (y > _y && y < (_y + 90));
}

static void move(int x, int y) {
  _x = x-90/2;
  _y = y-90/2;
}

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

static void draw_the_square() {
  static const float v[] = {
    0,  90,
    0,  0,
    90, 90,
    90, 0
  };    
  
  glPushMatrix();
   glTranslatef(_x, _y, 0);
   glVertexPointer(2, GL_FLOAT, 2*sizeof(float), v);
   glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  glPopMatrix();  
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

  _screen_width = width;
  _screen_height = height;
  
  /*
  glViewport(0, 0, width, height);
  
  glMatrixMode(GL_PROJECTION);  
  glOrthof(0, width, 0, height, 0, 1);
  
  glMatrixMode(GL_MODELVIEW); 
  glEnableClientState(GL_VERTEX_ARRAY); 
  glClearColor(0.4, 0.8, 0.4, 1);
  */

  r->setup(width, height);
}

void gdt_hook_hidden(boolean exiting) {

}

void gdt_hook_render() {
	/*
  glClear(GL_COLOR_BUFFER_BIT);
  
  glColor4f(0, 0, 1, 0.5);
  
  draw_the_square();
  */

	r->render();
}





