#include<bits/stdc++.h>
using namespace std;
int main()
{
    double meal_charge=88.67,tax=0,tip=0,total=0;
    tax=meal_charge*0.0675;
    tip=(meal_charge+tax)*0.2;
    total=meal_charge+tax+tip;
    cout<<"Meal Charge: $"<<fixed<<setprecision(2)<<meal_charge<<endl;
    cout<<"Tax: $"<<fixed<<setprecision(2)<<tax<<endl;
    cout<<"Tip: $"<<fixed<<setprecision(2)<<tip<<endl;
    cout<<"Total: $"<<fixed<<setprecision(2)<<total<<endl;
    return 0;
}