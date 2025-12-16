#include<bits/stdc++.h>
using namespace std;
struct Weather{
    double rainfall;
    double HighTemperature;
    double LowTemperature;
    double AverageTemperature;
};
int main()
{
    Weather month[12];
    double totalRainfall=0.0;
    double avgRainfall=0.0;
    double AverageTemperature=0.0;
    double highestTemperature=0;
    double lowestTemperature=0;
    for(int i=0;i<12;i++)
    {
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
            i--;
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
    avgRainfall=totalRainfall/12.0;
    AverageTemperature/=12.0;
    cout<<fixed<<setprecision(2);
    cout<<"Total Rainfall: "<<totalRainfall<<" inches"<<endl;
    cout<<"Average Monthly Rainfall: "<<avgRainfall<<" inches"<<endl;
    cout<<"Average of Average Monthly Temperatures: "<<AverageTemperature<<" F"<<endl;
    cout<<"Highest Temperature: "<<highestTemperature<<" F"<<endl;
    cout<<"Lowest Temperature: "<<lowestTemperature<<" F"<<endl;
    return 0;
}