#include<iostream>
using namespace std;
int main()
{
    double MaxCredit, UsedCredit, AvaCredit;
    cout<<" Input your maximum amount of credit ";
    cin>>MaxCredit;
    cout<<" Input your amount of credit used ";
    cin>>UsedCredit;
    AvaCredit = MaxCredit - UsedCredit;
    cout<<" Your Available Credit "<<AvaCredit;
    return 0;
}