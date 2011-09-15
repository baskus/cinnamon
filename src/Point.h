
class Point {
public:
	float x;
	float y;

	Point();
	Point(float x, float y);

	Point operator-() const;
	Point operator+(const Point &other) const;
	Point operator-(const Point &other) const;
};
