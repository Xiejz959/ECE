#include <iostream>
#include <limits>
#include <string>
#include <cctype>
using namespace std;

struct MenuItem {
    string name;     // dish name
    string picture;  // link to a picture of the dish
    double price = 0.0; // non-negative
    bool vegetarian = false; // whether the dish is vegetarian
};

struct Restaurant {
    string name;              // Restaurant name
    string description;       // Short description
    MenuItem* menus = nullptr; // Pointer to dynamically allocated array of menu items
    int menuSize = 0;          // The size of the menu
    double averagePrice = 0.0; // The average price of the items
    double minimum = 0.0;      // The price of the cheapest menu item
    double maximum = 0.0;      // The price of the most expensive menu item
    bool vegetarianOptions = false; // Derived: at least one menu item is vegetarian
};

void clear_input() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int readPositiveInt(const string &prompt) {
    while (true) {
        cout << prompt;
        int v;
        if (cin >> v) {
            clear_input();
            if (v > 0) return v;
            cout << "Value must be a positive integer." << endl;
        } else {
            cout << "Invalid input." << endl;
            clear_input();
        }
    }
}

double readNonNegativeDouble(const string &prompt) {
    while (true) {
        cout << prompt;
        double v;
        if (cin >> v) {
            clear_input();
            if (v >= 0.0) return v;
            cout << "Price must be non-negative." << endl;
        } else {
            cout << "Invalid number." << endl;
            clear_input();
        }
    }
}

string readNonEmptyLine(const string &prompt) {
    while (true) {
        cout << prompt;
        string s;
        getline(cin, s);
        if (!s.empty()) return s;
        cout << "This field cannot be empty." << endl;
    }
}

bool readYesNo(const string &prompt) {
    while (true) {
        cout << prompt << " (y/n): ";
        string s; getline(cin, s);
        if (s.size()) {
            char c = static_cast<char>(tolower(static_cast<unsigned char>(s[0])));
            if (c == 'y') return true;
            if (c == 'n') return false;
        }
        cout << "Please enter 'y' or 'n'." << endl;
    }
}

int main() {
    cout << "-- Restaurant Top Dishes --" << endl;
    int n = readPositiveInt("Enter number of restaurants: ");
    Restaurant* rs = new Restaurant[n];

    for (int i = 0; i < n; ++i) {
        cout << "\nRestaurant #" << (i + 1) << endl;
        rs[i].name = readNonEmptyLine("Name: ");
        rs[i].description = readNonEmptyLine("Short description: ");

        rs[i].menuSize = readPositiveInt("Number of menu items: ");
        rs[i].menus = new MenuItem[rs[i].menuSize];

        double sum = 0.0;
        rs[i].vegetarianOptions = false;
        for (int j = 0; j < rs[i].menuSize; ++j) {
            cout << "  Menu item #" << (j + 1) << endl;
            rs[i].menus[j].name = readNonEmptyLine("    Dish name: ");
            rs[i].menus[j].picture = readNonEmptyLine("    Picture link: ");
            rs[i].menus[j].price = readNonNegativeDouble("    Price: ");
            rs[i].menus[j].vegetarian = readYesNo("    Is this dish vegetarian?");

            if (j == 0) {
                rs[i].minimum = rs[i].menus[j].price;
                rs[i].maximum = rs[i].menus[j].price;
            } else {
                if (rs[i].menus[j].price < rs[i].minimum) rs[i].minimum = rs[i].menus[j].price;
                if (rs[i].menus[j].price > rs[i].maximum) rs[i].maximum = rs[i].menus[j].price;
            }

            sum += rs[i].menus[j].price;
            if (rs[i].menus[j].vegetarian) rs[i].vegetarianOptions = true;
        }
        rs[i].averagePrice = sum / static_cast<double>(rs[i].menuSize);
    }

    cout << "\n-- Filter by average price range --" << endl;
    double minP = readNonNegativeDouble("Minimum average price: ");
    double maxP = readNonNegativeDouble("Maximum average price: ");
    while (maxP < minP) {
        cout << "Maximum cannot be less than minimum. Please re-enter." << endl;
        minP = readNonNegativeDouble("Minimum average price: ");
        maxP = readNonNegativeDouble("Maximum average price: ");
    }

    cout << "\nRestaurants within the range [" << minP << ", " << maxP << "]:" << endl;
    bool any = false;
    for (int i = 0; i < n; ++i) {
        if (rs[i].averagePrice >= minP && rs[i].averagePrice <= maxP) {
            any = true;
            cout << "- " << rs[i].name << " | avg: " << rs[i].averagePrice << endl;
        }
    }
    if (!any) cout << "No restaurants found in the given price range." << endl;

    // clean up allocated menus
    for (int i = 0; i < n; ++i) {
        delete[] rs[i].menus;
        rs[i].menus = nullptr;
    }
    delete[] rs;
    return 0;
}
