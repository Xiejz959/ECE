#include <iostream>

class NumberArray
{
private:
	double *arr;
	int size;

public:
	NumberArray(int n)
	{
		size = n;
		arr = new double[size];
		for (int i = 0; i < size; ++i)
		{
			arr[i] = 0.0;
		}
	}

	~NumberArray()
	{
		delete[] arr;
	}

	void set(int index, double value)
	{
		arr[index] = value;
	}

	double get(int index) const
	{
		return arr[index];
	}

	double highest() const
	{
		double hi = arr[0];
		for (int i = 1; i < size; ++i)
		{
			if (arr[i] > hi)
			{
				hi = arr[i];
			}
		}
		return hi;
	}

	double lowest() const
	{
		double lo = arr[0];
		for (int i = 1; i < size; ++i)
		{
			if (arr[i] < lo)
			{
				lo = arr[i];
			}
		}
		return lo;
	}

	double average() const
	{
		double sum = 0.0;
		for (int i = 0; i < size; ++i)
		{
			sum += arr[i];
		}
		return sum / size;
	}
};

int main()
{
	int n = 0;
	std::cout << "Enter the number of elements: ";
	std::cin >> n;

	NumberArray numbers(n);

	for (int i = 0; i < n; ++i)
	{
		double value = 0.0;
		std::cout << "Enter value #" << (i + 1) << ": ";
		std::cin >> value;
		numbers.set(i, value);
	}

	std::cout << "Highest: " << numbers.highest() << std::endl;
	std::cout << "Lowest: " << numbers.lowest() << std::endl;
	std::cout << "Average: " << numbers.average() << std::endl;

	return 0;
}
