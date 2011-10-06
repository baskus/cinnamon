/*
 * nnGDTIntegration.h
 *
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

#include "Cinnamon.h"
#include "nnRender.h"

//Log tag to use in this file
const char* TAG = "nnGDTIntegration.cpp";

nnRender *render;

//Called by gdt when when the program starts
void gdt_hook_initialize() {
	gdt_log(LOG_DEBUG, TAG, "gdt_hook_initialize called");

	render = nnRender::getSharedRender();
	if(render == NULL)
		gdt_log(LOG_DEBUG, TAG, "Render not set");
	else
		gdt_log(LOG_DEBUG, TAG, "Render set");



	//Give the program a chance to initialize and set a scene
	nnHookInitialize();

	nnScene *scene = render->getCurrentScene();
	//Get the render and make sure it was set in nnHookInitialize
	if(scene == NULL) {
		gdt_log(LOG_ERROR, TAG, "gdt_hook_initialize: Scene was not set in nnHookInitialize. Can't continue. Exiting.");
		gdt_exit(EXIT_FAIL);
	}
	else {
		gdt_log(LOG_DEBUG, TAG, "gdt_hook_initialize: Scene was set in nnHookInitialize. Continuing.");
	}
}

//Called when the program exits (check gdt.h for exact circumstances)
void gdt_hook_exit() {
	gdt_log(LOG_DEBUG, TAG, "gdt_hook_exit called");
}

//Called when a gl surface is ready of the specified dimensions.
void gdt_hook_visible(int width, int height) {
	gdt_log(LOG_DEBUG, TAG, "gdt_hook_visible called");

	render->setup(width, height);
}

//Called when going to the background or exiting.
void gdt_hook_hidden(boolean exiting) {
	gdt_log(LOG_DEBUG, TAG, "gdt_hook_hidden called");
}

//Called when the program should render a frame
void gdt_hook_render() {
	gdt_log(LOG_DEBUG, TAG, "gdt_hook_render called");

	render->render();
}
