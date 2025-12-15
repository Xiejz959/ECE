#include<bits/stdc++.h>
using namespace std;
double median(int *arry, int n);
int main()
{
    int num=0;
    cin>>num;
    int *arr= new int[num];
    for(int i=0;i<num;i++) cin>>*(arr+i);
    sort(arr,arr+num);//ascending order, creating condition for our function
    double ans = median(arr,num);
    cout<<fixed<<setprecision(1)<<ans;
    delete [] arr;// free memory
    arr=nullptr;// avoid dangling pointer
    return 0;
}
double median(int *arry, int n)
{
    if(n%2==0)//even
    {
        return (arry[n/2-1]+arry[n/2])/2.0;
    }
    else//odd
    {
        return arry[n/2];
    }
}