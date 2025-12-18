#include <iostream>
#include <limits>
#include <string>
using namespace std;

struct dateTime {
	int year;
	int month;
	int date;    // day of month
	int hours;
	int minutes;
	int seconds;
};

void clear_input() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int readIntAny(const string &prompt) {
	while (true) {
		cout << prompt;
		int v;
		if (cin >> v) { clear_input(); return v; }
		cout << "Invalid input." << endl;
		clear_input();
	}
}

int readNonNegativeInt(const string &prompt) {
	while (true) {
		cout << prompt;
		int v;
		if (cin >> v) {
			clear_input();
			if (v >= 0) return v; // year must be non-negative
			cout << "Value must be non-negative." << endl;
		} else {
			cout << "Invalid input." << endl;
			clear_input();
		}
	}
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

dateTime readDateTime(const string &title) {
	cout << "-- Enter " << title << " --" << endl;
	dateTime dt{};
	dt.year = readNonNegativeInt("Year (>=0): ");
	dt.month = readIntInRange("Month (1-12): ", 1, 12);
	dt.date = readIntAny("Date (day): ");
	dt.hours = readIntInRange("Hours (0-23): ", 0, 23);
	dt.minutes = readIntInRange("Minutes (0-59): ", 0, 59);
	dt.seconds = readIntInRange("Seconds (0-59): ", 0, 59);
	return dt;
}

// Compare only date part (year, month, date).
// If identical, print message and return any argument (first).
dateTime earlierDate(const dateTime &a, const dateTime &b) {
	if (a.year != b.year) return (a.year < b.year) ? a : b;
	if (a.month != b.month) return (a.month < b.month) ? a : b;
	if (a.date != b.date) return (a.date < b.date) ? a : b;
	cout << "Identical dates" << endl;
	return a;
}

int main() {
	dateTime d1 = readDateTime("first date & time");
	dateTime d2 = readDateTime("second date & time");

	dateTime e = earlierDate(d1, d2);
	cout << "Earlier date: " << e.year << "-" << e.month << "-" << e.date << endl;
	return 0;
}

