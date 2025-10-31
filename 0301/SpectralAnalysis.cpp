#include <iostream>
using namespace std;
int main()
{
    double wavelength=0;
    cout << "Enter the wavelength in meters: \n";
    cin >> wavelength;
    if (wavelength >= 1e-2)
        cout << "Radio Wave\n";
    else if (wavelength >= 1e-3)
        cout << "Microwave\n";
    else if (wavelength >= 7e-7)
        cout << "Infrared\n";
    else if (wavelength >= 4e-7)
        cout << "Visible Light\n";
    else if (wavelength >= 1e-8)
        cout << "Ultraviolet\n";
    else if (wavelength >= 1e-11)
        cout << "X-Ray\n";
    else
        cout << "Gamma Ray\n";
    return 0;
}