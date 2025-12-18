#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
using namespace std;

struct Bin {
	string description;
	int parts;
};

void clear_input() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int readIntInRange(const string &prompt, int lo, int hi) {
	while (true) {
		cout << prompt;
		int v;
		if (cin >> v) {
			clear_input();
			if (v >= lo && v <= hi) return v;
			cout << "Value out of range." << endl;
		} else {
			cout << "Invalid input." << endl;
			clear_input();
		}
	}
}

void AddParts(Bin bins[], int index, int amount, int maxParts) {
	bins[index].parts += amount;
	if (bins[index].parts > maxParts) bins[index].parts = maxParts;
}

void RemoveParts(Bin bins[], int index, int amount) {
	bins[index].parts -= amount;
	if (bins[index].parts < 0) bins[index].parts = 0;
}

void printBins(const Bin bins[], int n) {
	cout << "\n-- Inventory Bins --" << endl;
	cout << left << setw(4) << "No." << setw(18) << "Part" << "Count" << endl;
	for (int i = 0; i < n; ++i) {
		cout << left << setw(4) << (i + 1) << setw(18) << bins[i].description << bins[i].parts << endl;
	}
}

int main() {
	const int BIN_COUNT = 10;
	const int MAX_PARTS = 30;

	Bin bins[BIN_COUNT] = {
		{"Valve", 10},
		{"Bearing", 5},
		{"Bushing", 15},
		{"Coupling", 21},
		{"Flange", 7},
		{"Gear", 5},
		{"Gear Housing", 5},
		{"Vacuum Gripper", 25},
		{"Cable", 18},
		{"Rod", 12},
	};

	while (true) {
		printBins(bins, BIN_COUNT);
		int choice = readIntInRange("Select a bin (1-10) or 0 to quit: ", 0, BIN_COUNT);
		if (choice == 0) break;

		int idx = choice - 1;
		int op = readIntInRange("1) Add parts  2) Remove parts: ", 1, 2);

		if (op == 1) {
			int spaceLeft = MAX_PARTS - bins[idx].parts;
			int amount = readIntInRange("Number of parts to add: ", 0, spaceLeft);
			AddParts(bins, idx, amount, MAX_PARTS);
		} else {
			int amount = readIntInRange("Number of parts to remove: ", 0, bins[idx].parts);
			RemoveParts(bins, idx, amount);
		}
	}

	return 0;
}

