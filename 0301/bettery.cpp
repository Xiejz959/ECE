#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double BetteryPower=3000, GPSConsume=148, WiFiConsume=352, ScreenConsume=197;
    double TotalConsume=GPSConsume+WiFiConsume+ScreenConsume;
    double Time=0;
    cout<<"Input the time spent: ";
    cin>>Time;
    double BetteryConsume=TotalConsume*Time;
    if(BetteryConsume>BetteryPower)
        cout<<"the battery can't support the time spent, the total consumption is "<<3000<<"mAh"<<endl;
    else
        cout<<"battery consumption is "<<BetteryConsume<<"mAh"<<endl;
    return 0;
}