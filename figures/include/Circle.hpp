#pragma once

#include "Figure.hpp"

class Circle : public Figure {
public:
	Circle(int id, int x, int y, int radius, const char* label);
	~Circle();

	void print() const;
	bool is_inside(int x, int y);
	void zoom(int factor);

protected:
	int radius;
	char* label;
};
