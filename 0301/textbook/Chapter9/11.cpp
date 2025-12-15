#include<bits/stdc++.h>
using namespace std;
int* connector(int *, int, int *, int);
int main()
{
    int n,m;cin>>n>>m;
    int *a=new int[n];
    int *b=new int[m];
    for(int i=0;i<n;i++) cin>>*(a+i);
    for(int i=0;i<m;i++) cin>>*(b+i);
    int *ans=connector(a,n,b,m);
    for(int i=0;i<n+m;i++) cout<<*(ans+i)<<" ";
    delete [] a;
    a=nullptr;
    delete [] b;
    b=nullptr;
    delete [] ans;
    ans=nullptr;
    return 0;
}
int* connector(int *arr1, int num1, int *arr2, int num2)
{
    int *res=new int[num1+num2];
    for(int i=0;i<num1;i++) *(res+i)=*(arr1+i);
    for(int i=0;i<num2;i++) *(res+num1+i)=*(arr2+i);
    return res;
}