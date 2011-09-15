#include "Point.h"

Point::Point() : x(0), y(0) {}

Point::Point(float x, float y) : x(x), y(y) {}

Point Point::operator-() const {
	return Point(-x, -y);
}

Point Point::operator+(const Point &other) const {
	return Point(x + other.x, y + other.y);
}

Point Point::operator-(const Point &other) const {
	return Point(x - other.x, y - other.y);
}
