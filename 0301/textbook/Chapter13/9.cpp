#include <iostream>

class VisitorCounter
{
private:
	int current;
	int maximum;

public:
	VisitorCounter(int maxCapacity)
	{
		maximum = maxCapacity;
		current = 0;
	}

	int getCurrent() const
	{
		return current;
	}

	int getMaximum() const
	{
		return maximum;
	}

	bool addVisitor()
	{
		if (current < maximum)
		{
			++current;
			return true;
		}
		return false;
	}

	void removeVisitor()
	{
		if (current > 0)
		{
			--current;
		}
	}
};

int main()
{
	VisitorCounter counter(5);

	std::cout << "Maximum capacity: " << counter.getMaximum() << std::endl;
	std::cout << "Current visitors: " << counter.getCurrent() << std::endl;

	for (int i = 0; i < 6; ++i)
	{
		bool allowed = counter.addVisitor();
		std::cout << "Add visitor: " << (allowed ? "allowed" : "blocked")
				  << ", current = " << counter.getCurrent() << std::endl;
	}

	counter.removeVisitor();
	std::cout << "Remove visitor, current = " << counter.getCurrent() << std::endl;

	bool allowed = counter.addVisitor();
	std::cout << "Add visitor: " << (allowed ? "allowed" : "blocked")
			  << ", current = " << counter.getCurrent() << std::endl;

	return 0;
}
