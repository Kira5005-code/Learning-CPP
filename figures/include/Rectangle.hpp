#include "Figure.hpp"

class Rectangle : public Figure {
public:
	Rectangle(int id, int x, int y, int width, int height);
	~Rectangle() = default;

	void print() const;
	bool is_inside(int x, int y);
	void zoom(int factor);

private:
	int width;
	int height;
};
