#include <iostream>

class Circle
{
private:
	double radius;
	double pi;

public:
	Circle()
	{
		radius = 0.0;
		pi = 3.14159;
	}

	Circle(double r)
	{
		radius = r;
		pi = 3.14159;
	}

	void setRadius(double r)
	{
		radius = r;
	}

	double getRadius() const
	{
		return radius;
	}

	double getArea() const
	{
		return pi * radius * radius;
	}

	double getDiameter() const
	{
		return radius * 2;
	}

	double getCircumference() const
	{
		return 2 * pi * radius;
	}
};

int main()
{
	double r = 0.0;
	std::cout << "Enter the circle's radius: ";
	std::cin >> r;

	Circle c(r);
	std::cout << "Area: " << c.getArea() << std::endl;
	std::cout << "Diameter: " << c.getDiameter() << std::endl;
	std::cout << "Circumference: " << c.getCircumference() << std::endl;

	return 0;
}
