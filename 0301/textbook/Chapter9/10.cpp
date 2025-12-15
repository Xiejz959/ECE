#include<bits/stdc++.h>
using namespace std;
void splitter(int *, int);
int main()
{
    int n;cin>>n;
    int *num=new int[n];
    for(int i=0;i<n;i++) cin>>*(num+i);
    splitter(num,n);
    delete [] num;// free memory
    num=nullptr;// avoid dangling pointer
    return 0;
}
void splitter(int *num, int n)
{
    for(int i=0;i<n;i+=2)
    {
        cout<<*(num+i)<<" ";
    }
    cout<<endl;
}