#include<bits/stdc++.h>
using namespace std;
struct earthquake
{
    string name;
    string location;
    int year;
    double magnitude;
    double fatalities;
};
int main()
{
    earthquake eq1,eq2,eq3;
    cout<<"Enter details of earthquake 1 (name, location, year, magnitude, fatalities): ";
    cin>>eq1.name>>eq1.location>>eq1.year>>eq1.magnitude>>eq1.fatalities;
    cout<<"Enter details of earthquake 2 (name, location, year, magnitude, fatalities): ";
    cin>>eq2.name>>eq2.location>>eq2.year>>eq2.magnitude>>eq2.fatalities;
    cout<<"Enter details of earthquake 3 (name, location, year, magnitude, fatalities): ";
    cin>>eq3.name>>eq3.location>>eq3.year>>eq3.magnitude>>eq3.fatalities;
    cout<<"\nEarthquake Details:\n";
    cout<<"total fatalities: "<<(eq1.fatalities)+(eq2.fatalities)+(eq3.fatalities)<<endl;
    cout<<"Average Magnitude: "<<((eq1.magnitude)+(eq2.magnitude)+(eq3.magnitude))/3<<endl;
    cout<<"maximum magnitude earthquake: ";
    if(eq1.magnitude>=eq2.magnitude && eq1.magnitude>=eq3.magnitude)
        cout<<eq1.name<<endl;
    else if(eq2.magnitude>=eq1.magnitude && eq2.magnitude>=eq3.magnitude)
        cout<<eq2.name<<endl;
    else
        cout<<eq3.name<<endl;
    cout<<"maximum fatalities earthquake: ";
    if(eq1.fatalities>=eq2.fatalities && eq1.fatalities>=eq3.fatalities)
        cout<<eq1.name<<endl;
    else if(eq2.fatalities>=eq1.fatalities && eq2.fatalities>=eq3.fatalities)
        cout<<eq2.name<<endl;
    else
        cout<<eq3.name<<endl;
    return 0;
}