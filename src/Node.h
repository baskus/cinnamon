#include <vector>

#include "Point.h"

class Node {
private:
	std::vector<Node*> *mChildren;

	Point mPos;

public:
	Node();

	void setPosition(Point pos);

	void addChild(Node *child);
	void removeChild(Node *child);

	void draw();
};
