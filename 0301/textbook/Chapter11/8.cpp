#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>
#include <string>
using namespace std;

struct ComputerConfig 
{
	double clockGHz;      // CPU clock speed 
	int cpuCores;         // Number of CPU cores
	int ramGB;            // RAM size 
	int diskGB;           // Hard disk size
	double benchmark;     // Benchmark score (higher is faster)
	double price;         // Price
};


void clear_input() 
{
	cin.clear();
	cin.ignore(1000, '\n');
}


double read_ND(const string &prompt) 
{
	while (true) 
	{
		cout << prompt;
		double v;
		if (cin >> v) 
		{
			if (v >= 0.0) return v;
			cout << "Value must be non-negative."<<endl;
		} 
		else 
		{
			cout << "Invalid input. "<<endl;
		}
		clear_input();
	}
}


int read_PI(const string &prompt) 
{
	while (true) 
	{
		cout << prompt;
		int v;
		if (cin >> v) 
		{
			if (v > 0) return v;
			cout << "Value must be a positive integer."<<endl;
		} 
		else 
		{
			cout << "Invalid input. "<<endl;
		}
		clear_input();
	}
}


int read_NI(const string &prompt) 
{
	while (true) 
	{
		cout << prompt;
		int v;
		if (cin >> v) 
		{
			if (v >= 0) return v;
			cout << "Value must be a non-negative integer."<<endl;
		} 
		else 
		{
			cout << "Invalid input. "<<endl;
		}
		clear_input();
	}
}

void printConfig(const ComputerConfig &c, int indexDisplay) 
{
	cout << "No.: " << indexDisplay << endl;
	cout << fixed << setprecision(2);
	cout << "  Clock (GHz): " << c.clockGHz << endl;
	cout << "  CPU Cores: " << c.cpuCores << endl;
	cout << "  RAM (GB): " << c.ramGB << endl;
	cout << "  Disk (GB): " << c.diskGB << endl;
	cout << "  Benchmark: " << c.benchmark << endl;
	cout << "  Price: " << c.price << endl;
}

void printAll(const vector<ComputerConfig> &list) 
{
	if (list.empty()) 
	{
		cout << "No configurations yet." << endl;
		return;
	}
	cout << "-- All Computer Configurations --" << endl;
	for (size_t i = 0; i < list.size(); ++i) 
	{
		printConfig(list[i], static_cast<int>(i) + 1);
		if (i + 1 < list.size()) cout << "---------------------" << endl;
	}
}

void addConfig(vector<ComputerConfig> &list) 
{
	ComputerConfig c;
	c.clockGHz = read_ND("Enter clock speed (GHz): ");
	c.cpuCores = read_PI("Enter number of CPU cores: ");
	c.ramGB = read_PI("Enter RAM size (GB): ");
	c.diskGB = read_PI("Enter hard disk size (GB): ");
	c.benchmark = read_ND("Enter benchmark score: ");
	c.price = read_ND("Enter price: ");
	list.push_back(c);
	cout << "Added. Total count: " << list.size() << endl;
}

void changePrice(vector<ComputerConfig> &list) 
{
	if (list.empty()) 
	{
		cout << "List is empty. Cannot change price." << endl;
		return;
	}
	cout << "There are " << list.size() << " configurations." << endl;
	int num;
	while (true) 
	{
		num = read_PI("Enter configuration number to change price (1-" + to_string(list.size()) + "): ");
		if (num >= 1 && static_cast<size_t>(num) <= list.size()) break;
		cout << "Number does not exist." << endl;
	}
	double newPrice = read_ND("Enter new price: ");
	list[static_cast<size_t>(num) - 1].price = newPrice;
	cout << "Updated price for configuration " << num << "." << endl;
}

void showOne(const vector<ComputerConfig> &list) 
{
	if (list.empty()) 
	{
		cout << "List is empty." << endl;
		return;
	}
	int num;
	while (true) 
	{
		num = read_PI("Enter configuration number to show (1-" + to_string(list.size()) + "): ");
		if (num >= 1 && static_cast<size_t>(num) <= list.size()) break;
		cout << "Number does not exist." << endl;
	}
	printConfig(list[static_cast<size_t>(num) - 1], num);
}

// Search function: find configurations meeting min benchmark and within max budget
void searchByBenchmarkAndPrice(const vector<ComputerConfig> &list)
{
	if (list.empty())
	{
		cout << "No configurations yet." << endl;
		return;
	}

	double minBenchmark = read_ND("Enter minimum benchmark score: ");
	double maxPrice = read_ND("Enter maximum price: ");

	vector<int> matchedIndices;
	for (size_t i = 0; i < list.size(); ++i)
	{
		if (list[i].benchmark >= minBenchmark && list[i].price <= maxPrice)
		{
			matchedIndices.push_back(static_cast<int>(i));
		}
	}

	if (matchedIndices.empty())
	{
		cout << "No configurations match the given criteria." << endl;
		return;
	}

	cout << "-- Suitable Configurations --" << endl;
	for (size_t j = 0; j < matchedIndices.size(); ++j)
	{
		int idx = matchedIndices[j];
		printConfig(list[static_cast<size_t>(idx)], idx + 1);
		if (j + 1 < matchedIndices.size()) cout << "---------------------" << endl;
	}
}

void printMenu() 
{
	cout << endl;
	cout << "===== Menu =====" << endl;
	cout << "1) Add new configuration" << endl;
	cout << "2) Change price of existing configuration" << endl;
	cout << "3) Show all configurations" << endl;
	cout << "4) Show a configuration by number" << endl;
	cout << "5) Search by benchmark(min) and price(max)" << endl;
	cout << "6) Exit" << endl;
}

int main() 
{
	vector<ComputerConfig> configs;

	while (true) 
	{
		printMenu();
		cout << "Choose (1-6): ";
		int choice;
		if (!(cin >> choice)) 
		{
			cout << "Invalid input. Please enter an integer." << endl;
			clear_input();
			continue;
		}

		switch (choice) 
		{
			case 1:
				addConfig(configs);
				break;
			case 2:
				changePrice(configs);
				break;
			case 3:
				printAll(configs);
				break;
			case 4:
				showOne(configs);
				break;
			case 5:
				searchByBenchmarkAndPrice(configs);
				break;
			case 6:
				cout << "Exit." << endl;
				return 0;
			default:
				cout << "Invalid option." << endl;
				break;
		}
	}
}

