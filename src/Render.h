#include "Node.h"

class Render {
public:
	Render();
	
	void setup(int width, int height);
	
	void render();

private:
	Node n;
};
