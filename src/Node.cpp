#include <tr1/memory>

#include "gdt_gles1.h"

#include "Node.h"

Node::Node() {

	//std::tr1::shared_ptr<Node> kaka = std::tr1::shared_ptr<Node>(new Node());

	//mPos = Vector();
}

/*
void Node::setPosition(Vector pos) {
	mPos = pos;
}
*/

void Node::addChild(Node *child) {

}

void Node::removeChild(Node *child) {

}

void Node::draw() {
	static const float v[] = {
		0,  90,
		0,  0,
		90, 90,
		90, 0
	};

	glPushMatrix();
    
    glTranslatef(50,200, 0);
    glRotatef(20, 0, 0, 1);
	glVertexPointer(2, GL_FLOAT, 2*sizeof(float), v);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	
    glPopMatrix();
}
