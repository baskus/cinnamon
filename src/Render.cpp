
#include "gdt_gles1.h"

#include "Render.h"

Render::Render() {

}

void Render::setup(int width, int height) {
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glOrthof(0, width, 0, height, 0, 1);

	glMatrixMode(GL_MODELVIEW);
	glEnableClientState(GL_VERTEX_ARRAY);
	glClearColor(0.4, 0.8, 0.4, 1);
}

void Render::render() {
	glClear(GL_COLOR_BUFFER_BIT);

	glColor4f(0, 0, 1, 0.5);

	n.draw();
}
