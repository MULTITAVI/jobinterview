#include <iostream>
#include <math.h>

class Triangle {
public:
	Triangle() : a(0), b(0), c(0) {}

	Triangle(double a, double b) : a(a), b(b), c(sqrt(pow(a, 2) + pow(b, 2))) {}

	~Triangle() {}

	double square() {
		if (_square)
			return _square;
		else {
			_square = 0.5 * a * b;

			return _square;
		}
	}

	double a;
	double b;
	double c;

private:
	double _square = 0;
};

class Quadriliteral : public Triangle {
public:
	Quadriliteral() : Triangle() {}

	Quadriliteral(double a, double b) : Triangle(a, b) {}

	~Quadriliteral() {}

	double square() {
		return Triangle::square() * 2;
	}
};

int main() {
	Triangle triangle(3, 4);
	Quadriliteral quadriliteral(3, 4);

	std::cout << "Area of a triangle: " << triangle.square() << std::endl;
	std::cout << "Quadriliteral area: " << quadriliteral.square() << std::endl;

	return 0;
}