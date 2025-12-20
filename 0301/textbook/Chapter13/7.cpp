#include <iostream>

class Length
{
private:
	int meters;
	int centimeters;

public:
	Length(int m = 0, int cm = 0)
	{
		meters = m;
		centimeters = cm;
	}

	void setMeters(int m)
	{
		meters = m;
	}

	void setCentimeters(int cm)
	{
		centimeters = cm;
	}

	int getMeters() const
	{
		return meters;
	}

	int getCentimeters() const
	{
		return centimeters;
	}

	int getLength() const
	{
		return meters * 100 + centimeters;
	}
};

int main()
{
	Length a, b;

	int m = 0;
	int cm = 0;

	std::cout << "Enter length 1 (meters then centimeters): ";
	std::cin >> m >> cm;
	a.setMeters(m);
	a.setCentimeters(cm);

	std::cout << "Enter length 2 (meters then centimeters): ";
	std::cin >> m >> cm;
	b.setMeters(m);
	b.setCentimeters(cm);

	if (a.getLength() > b.getLength())
	{
		std::cout << "Length 1 is longer." << std::endl;
	}
	else if (a.getLength() < b.getLength())
	{
		std::cout << "Length 2 is longer." << std::endl;
	}
	else
	{
		std::cout << "The two lengths are equal." << std::endl;
	}

	return 0;
}
