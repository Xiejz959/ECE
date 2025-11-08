#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double sum = 0.0;

    cout << "Series:\n";
    for (int n = 1; n <= 10; n++) {
        double term = (2.0 * n) / (n * n);  // 即 2.0 / n
        cout << "(" << (2 * n) << "/" << n << "^2)";
        if (n < 10) cout << " + ";
        else cout << "\n";

        sum += term;
    }

    cout << fixed << setprecision(6);
    cout << "Sum = " << sum << endl;

    return 0;
}