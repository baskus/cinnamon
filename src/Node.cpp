/*
 * Node.cpp
 *
 * Copyright (c) 2011 Sebastian €rleryd
 * Copyright (c) 2011 Carl Andersson
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

#include <tr1/memory>

#include "gdt_gles1.h"
#include "GL_DrawSimpleGeo.h"

#include "Node.h"

Node::Node() {

	//std::tr1::shared_ptr<Node> kaka = std::tr1::shared_ptr<Node>(new Node());

	mPos = Point();
}

void Node::setPosition(Point pos) {
	mPos = pos;
}

void Node::addChild(Node *child) {

}

void Node::removeChild(Node *child) {

}

void Node::draw() {

	//drawSquare(100,400,90,90,25);


	drawEllipse(200,150,200,300);
	/*static const float v[] = {
		0,  90,
		0,  0,
		90, 90,
		90, 0
	};

	glPushMatrix();
    
    glTranslatef(mPos.x+20,mPos.y, 0);
    glRotatef(-20, 0, 0, 1);
	glVertexPointer(2, GL_FLOAT, 2*sizeof(float), v);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	
    glPopMatrix();*/
}
