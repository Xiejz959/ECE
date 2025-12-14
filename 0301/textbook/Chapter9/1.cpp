#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={0,1,2,3,4,5,6,7,8,9};
    int num=sizeof(arr);
    cout<<num<<endl;
    for (int i = 0;i<10;i++)
    {
        cout<<arr[i]<<" "<<&arr[i]<<endl;
    }
    return 0;
}