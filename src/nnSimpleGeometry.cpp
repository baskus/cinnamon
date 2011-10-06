/*
 * nnSimpleGeometry.cpp
 *
 * Copyright (c) 2011 Carl Andersson
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

#include "nnSimpleGeometry.h"
#include "gdt_gles1.h"
#include <math.h>

#define PI (3.1415926535)

/*
 * Draw square with center at (x1,y1) with width and height
 */
void nnDrawSquare(const float x, const float y, const float width, const float height) {
	const float v[] = { -(width /2), -(height /2),
						-(width /2),  (height /2),
						 (width /2), -(height /2),
						 (width /2),  (height /2) };

	glPushMatrix();
		glTranslatef(x, y, 0);
		glVertexPointer(2, GL_FLOAT, 2 * sizeof(float), v);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glPopMatrix();
}

/*
 * Draw square with center at (x1,y1) with width and height rotated rotation degrees
 */
void nnDrawSquare(const float x, const float y, const  float width, const float height, const float rotation) {
	const float v[] = { -(width /2), -(height /2),
						-(width /2),  (height /2),
						 (width /2), -(height /2),
						 (width /2),  (height /2) };

	glPushMatrix();
		glTranslatef(x, y, 0);
		glRotatef(rotation, 0,0,1);
		glVertexPointer(2, GL_FLOAT, 2 * sizeof(float), v);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glPopMatrix();
}

/*
 * Draw ellipse with center at (x1,y1) with horisontal radius hRadius and vertical radius vRadius
 */
void nnDrawEllipse(const float x, const float y, const float hRadius, const float vRadius) {
	float vertex[ELLIPSE_NUMBER_OF_VERITCES << 1];
	for (int i=0;i<ELLIPSE_NUMBER_OF_VERITCES<<1;i+=2){
		vertex[i] = hRadius * cos(i * PI/ELLIPSE_NUMBER_OF_VERITCES);
		vertex[i+1] = vRadius * sin(i * PI/ELLIPSE_NUMBER_OF_VERITCES);
	}

	glPushMatrix();
		glTranslatef(x, y, 0);
		glVertexPointer(2, GL_FLOAT, 2 * sizeof(float), vertex);
		glDrawArrays(GL_TRIANGLE_FAN, 0, ELLIPSE_NUMBER_OF_VERITCES);
	glPopMatrix();
}

/*
 * Draw ellipse with center at (x1,y1) with horisontal radius hRadius and vertical radius vRadius
 * rotated rotation degrees
 */
void nnDrawEllipse(const float x, const float y, const float hRadius, const float vRadius, const float rotation) {
	float vertex[ELLIPSE_NUMBER_OF_VERITCES << 1];
	for (int i=0;i<ELLIPSE_NUMBER_OF_VERITCES<<1;i+=2){
		vertex[i] = hRadius * cos(i * PI/ELLIPSE_NUMBER_OF_VERITCES);
		vertex[i+1] = vRadius * sin(i * PI/ELLIPSE_NUMBER_OF_VERITCES);
	}

	glPushMatrix();
		glTranslatef(x, y, 0);
		glRotatef(rotation, 0,0,1);
		glVertexPointer(2, GL_FLOAT, 2 * sizeof(float), vertex);
		glDrawArrays(GL_TRIANGLE_FAN, 0, ELLIPSE_NUMBER_OF_VERITCES);
	glPopMatrix();
}
