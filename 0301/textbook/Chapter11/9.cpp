#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
using namespace std;

struct Speaker {
    string name;
    string phone;
    string topic;
    double fee = 0.0;
    bool occupied = false;
};

void clear_input() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int readIndexInRange(const string &prompt, int lo, int hi) {
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

double readNonNegativeDouble(const string &prompt) {
    while (true) {
        cout << prompt;
        double v;
        if (cin >> v) {
            clear_input();
            if (v >= 0.0) return v;
            cout << "Fee must be non-negative." << endl;
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

void printOne(const Speaker &s, int idxDisplay) {
    cout << "No.: " << idxDisplay << endl;
    if (!s.occupied) {
        cout << "  <empty>" << endl;
        return;
    }
    cout << fixed << setprecision(2);
    cout << "  Name: " << s.name << endl;
    cout << "  Telephone: " << s.phone << endl;
    cout << "  Topic: " << s.topic << endl;
    cout << "  Fee: " << s.fee << endl;
}

void enterOrEdit(Speaker arr[], int n) {
    int idx = readIndexInRange("Enter slot to fill/edit (1-" + to_string(n) + "): ", 1, n) - 1;
    if (arr[idx].occupied) {
        cout << "This slot currently has data, it will be overwritten." << endl;
    }

    string name = readNonEmptyLine("Enter name: ");
    string phone = readNonEmptyLine("Enter telephone number: ");
    string topic = readNonEmptyLine("Enter speaking topic: ");
    double fee = readNonNegativeDouble("Enter fee required: ");

    arr[idx].name = name;
    arr[idx].phone = phone;
    arr[idx].topic = topic;
    arr[idx].fee = fee;
    arr[idx].occupied = true;
    cout << "Saved to slot " << (idx + 1) << "." << endl;
}

void editExisting(Speaker arr[], int n) {
    int idx = readIndexInRange("Enter speaker number to edit (1-" + to_string(n) + "): ", 1, n) - 1;
    if (!arr[idx].occupied) {
        cout << "No data in this slot. Use 'Enter new' to add." << endl;
        return;
    }
    cout << "Re-enter all fields for this speaker:" << endl;
    arr[idx].name = readNonEmptyLine("Enter name: ");
    arr[idx].phone = readNonEmptyLine("Enter telephone number: ");
    arr[idx].topic = readNonEmptyLine("Enter speaking topic: ");
    arr[idx].fee = readNonNegativeDouble("Enter fee required: ");
    arr[idx].occupied = true;
    cout << "Updated speaker " << (idx + 1) << "." << endl;
}

void showAll(const Speaker arr[], int n) {
    cout << "-- All Speakers --" << endl;
    for (int i = 0; i < n; ++i) {
        printOne(arr[i], i + 1);
        if (i + 1 < n) cout << "---------------------" << endl;
    }
}

void showOneByNumber(const Speaker arr[], int n) {
    int idx = readIndexInRange("Enter number to show (1-" + to_string(n) + "): ", 1, n) - 1;
    printOne(arr[idx], idx + 1);
}

void printMenu() {
    cout << endl;
    cout << "===== Speakers' Bureau =====" << endl;
    cout << "1) Enter new speaker" << endl;
    cout << "2) Edit a speaker" << endl;
    cout << "3) Show all speakers" << endl;
    cout << "4) Show a speaker by number" << endl;
    cout << "5) Exit" << endl;
}

int main() {
    const int N = 10; // at least 10
    Speaker bureau[N];

    while (true) {
        printMenu();
        cout << "Choose (1-5): ";
        int choice;
        if (cin >> choice) {
            clear_input();
        } else {
            cout << "Invalid input. Please enter an integer." << endl;
            clear_input();
            continue;
        }

        switch (choice) {
            case 1:
                enterOrEdit(bureau, N);
                break;
            case 2:
                editExisting(bureau, N);
                break;
            case 3:
                showAll(bureau, N);
                break;
            case 4:
                showOneByNumber(bureau, N);
                break;
            case 5:
                cout << "Exit." << endl;
                return 0;
            default:
                cout << "Invalid option." << endl;
                break;
        }
    }
}
