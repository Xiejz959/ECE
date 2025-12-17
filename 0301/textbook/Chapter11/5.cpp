#include<bits/stdc++.h>
using namespace std;
struct Weather{
    double rainfall;
    double HighTemperature;
    double LowTemperature;
    double AverageTemperature;
};

enum Month{JANUARY=0,FEBRUARY,MARCH,APRIL,MAY,JUNE,JULY,AUGUST,SEPTEMBER,OCTOBER,NOVEMBER,DECEMBER,MONTH_COUNT};
int main()
{
    Weather month[MONTH_COUNT];
    double totalRainfall=0.0;
    double avgRainfall=0.0;
    double AverageTemperature=0.0;
    double highestTemperature=-200;
    double lowestTemperature=150;
    for(Month m=JANUARY; m<MONTH_COUNT; m=Month(m+1))
    {
        int i = static_cast<int>(m);
        cout<<"Enter the data of month "<<i+1<<endl;
        cout<<"Rainfall: ";
        cin>>month[i].rainfall;
        cout<<"High Temperature: ";
        cin>>month[i].HighTemperature;
        cout<<"Low Temperature: ";
        cin>>month[i].LowTemperature;
        if(month[i].HighTemperature< -100 || month[i].HighTemperature>140 || month[i].LowTemperature< -100 || month[i].LowTemperature>140)
        {
            cout<<"Error: Temperature out of range."<<endl;
            m = Month(m-1);
            continue;
        }
        month[i].AverageTemperature=(month[i].HighTemperature+month[i].LowTemperature)/2.0;
        totalRainfall+=month[i].rainfall;
        AverageTemperature+=month[i].AverageTemperature;
        if(i==0)
        {
            highestTemperature=month[i].HighTemperature;
            lowestTemperature=month[i].LowTemperature;
        }
        else
        {
            if(month[i].HighTemperature>highestTemperature)
                highestTemperature=month[i].HighTemperature;
            if(month[i].LowTemperature<lowestTemperature)
                lowestTemperature=month[i].LowTemperature;
        }
    }
    avgRainfall=totalRainfall/static_cast<double>(MONTH_COUNT);
    AverageTemperature/=static_cast<double>(MONTH_COUNT);
    cout<<fixed<<setprecision(2);
    cout<<"Total Rainfall: "<<totalRainfall<<" inches"<<endl;
    cout<<"Average Monthly Rainfall: "<<avgRainfall<<" inches"<<endl;
    cout<<"Average of Average Monthly Temperatures: "<<AverageTemperature<<" F"<<endl;
    cout<<"Highest Temperature: "<<highestTemperature<<" F"<<endl;
    cout<<"Lowest Temperature: "<<lowestTemperature<<" F"<<endl;
    return 0;
}