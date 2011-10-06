/*
 * nnRender.cpp
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

#include "gdt_gles1.h"
#include "gdt.h"

#include "nnRender.h"

#include "nnScene.h"

//Also initialize the shared render! :D
nnRender *nnRender::sSharedRender = NULL;

nnRender * nnRender::getSharedRender() {
	if(sSharedRender == NULL)
		sSharedRender = new nnRender();

	return sSharedRender;
}

nnRender::nnRender() {
	mScene = NULL;
	mSceneStack = std::stack<nnScene *>();
}

void nnRender::setup(int width, int height) {
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glOrthof(0, width, 0, height, 0, 1);

	glMatrixMode(GL_MODELVIEW);
	glEnableClientState(GL_VERTEX_ARRAY);
	glClearColor(0.4, 0.8, 0.4, 1);
}

void nnRender::render() {
	glClear(GL_COLOR_BUFFER_BIT);

	glColor4f(0, 0, 1, 0.5);

	mScene->draw();
}



void nnRender::pushScene(nnScene *scene) {
	mScene->onExit();
	mSceneStack.push(mScene);

	mScene = scene;
	scene->onEnter();
}

/**
 * Take the Scene at the top of the scene stack and set it as the current scene. Calls onExit on the current scene.
 * If the scene stack is empty
 */
void nnRender::popScene() {
	if(mScene != NULL)
		mScene->onExit();

 	if(!mSceneStack.empty()) {
 		mScene = mSceneStack.top();
 		mSceneStack.top();
 		mScene->onEnter();
 	}
 	else
 		gdt_exit(EXIT_SUCCEED);
}

void nnRender::replaceScene(nnScene *scene) {
	if(mScene != NULL) {
		mScene->onExit();
		delete mScene;
	}

	mScene = scene;
	scene->onEnter();
}

nnScene * nnRender::getCurrentScene() {
	return mScene;
}
