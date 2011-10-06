/*
 * nnNode.cpp
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

#include "gdt_gles1.h"
#include "nnSimpleGeometry.h"

#include "nnNode.h"

nnNode::nnNode() {
	//std::tr1::shared_ptr<Node> kaka = std::tr1::shared_ptr<Node>(new Node());

	mChildSortDirty = false;
	mChildren = std::vector<nnNode *>();
	mInvisible = false;
	mPos = nnPoint();
	mRotation = 0;
}

void nnNode::setPosition(nnPoint pos) {
	mPos = pos;
}

void nnNode::addChild(nnNode *child) {
	//Make sure we don't add the same node twice
	for(int i = 0; i < mChildren.size(); i++) {
		if(mChildren[i] == child)
			return;
	}

	mChildren.push_back(child);
	mChildSortDirty = true;
}

void nnNode::removeChild(nnNode *child) {
	for(std::vector<nnNode *>::iterator itr = mChildren.begin(); itr != mChildren.end(); itr++) {
		if(*itr == child) {
			mChildren.erase(itr);
			return;
		}
	}
}

void nnNode::transform() {
	glTranslatef(mPos.x,mPos.y, 0);
	glRotatef(mRotation, 0, 0, 1);
}

void nnNode::sortChildren() {
	if(mChildSortDirty) {

		//Sort children based on mZOrder here
		bool didSorting = true;
		while(didSorting) {
			didSorting = false;
			for(int i = 0; i < mChildren.size()-1; i++) {
				if(mChildren[i]->mZOrder > mChildren[i+1]->mZOrder) {
					nnNode *temp = mChildren[i];
					mChildren[i] = mChildren[i+1];
					mChildren[i+1] = temp;
					didSorting = true;
				}
			}
		}

		mChildSortDirty = false;
	}
}

void nnNode::visit() {

	//No need to do anything if we're invisible
	if(mInvisible)
		return;

	glPushMatrix();

	//Transform before anything else
	transform();

	//Sort children by z order so they can be more efficently drawn.
	sortChildren();

	//Index into the children array used when visiting children, first infront of this node, and then behind.
	int childIndex = 0;

	//Visit children behind us here
	for( ; childIndex < mChildren.size(); childIndex++) {
		if(mChildren[childIndex]->mZOrder >= 0) {
			break;
		}

		mChildren[childIndex]->visit();
	}

	//Draw self
	draw();

	//Visit children in front of us here
	for( ; childIndex < mChildren.size(); childIndex++) {
		mChildren[childIndex]->visit();
	}

	glPopMatrix();

	//drawSquare(100,400,90,90,25);

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

void nnNode::draw() {
}

void nnNode::onEnter() {

}

void nnNode::onExit() {

}

