#include <vector>

#include "Point.h"

class Node {
private:
	std::vector<Node*> *mChildren;

	//Vector mPos;

public:
	Node();

	//void setPosition(Vector pos);

	void addChild(Node *child);
	void removeChild(Node *child);

	void draw();
};
