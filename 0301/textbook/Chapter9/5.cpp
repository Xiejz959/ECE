#include<bits/stdc++.h>
using namespace std;
void dosomething( int *x, int *y);
int main()
{
    int a=0,b=0;
    cin>>a>>b;
    dosomething(&a,&b);
    cout<<a<<" "<<b<<endl;
    return 0;
}
void dosomething( int *x, int *y)//pass the address of a b into the function
{
    int temp=*x;
    *x=*y;
    *y=temp;
}