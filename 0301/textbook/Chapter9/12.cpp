#include<bits/stdc++.h>
using namespace std;
int* selection(int* , int , int);
int sum=0;
int main()
{
    int n;cin>>n;
    int k;cin>>k;
    int *num= new int[n];
    for(int i=0;i<n;i++) cin>>*(num+i);
    int *selected=selection(num,n,k);
    for(int i=0;i<sum;i++) cout<<*(selected+i)<<" ";
    cout<<endl;
    delete [] num;// free memory
    delete [] selected;// free memory
    num=nullptr;// avoid dangling pointer
    selected=nullptr;// avoid dangling pointer
    return 0;
}
int* selection(int* arr, int n, int k)
{
    if (k == 0) {
        sum = 0;
        return new int[0];
    }
    sum = 0; // reset global counter each call
    for(int i=0;i<n;i++)
    {
        if(*(arr+i)%k==0)
        {
            sum++;
        }
    }
    int *selected=new int[sum];
    int j = 0;
    for(int i=0;i<n;i++)
    {
        if(*(arr+i)%k==0)
        {
            *(selected+j)=*(arr+i);
            j++;
        }
    }
    return selected;
}