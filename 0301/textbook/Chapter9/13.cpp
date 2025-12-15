#include<bits/stdc++.h>
using namespace std;
double average(int *arry, int n);
double median(int *arry, int n);
double mode(int *arry, int n);
int main()
{
    int num=0;cin>>num;
    int *MovieNum= new int[num];
    for(int i=0;i<num;i++) 
    {
        int n=0;cin>>n;
        if(n<0)// input check
        {
            cout<<"Invalid input"<<endl;
            i--;
            continue;
        }
        else 
            *(MovieNum+i)=n;
    }
    sort(MovieNum,MovieNum+num);//ascending order, creating condition for our functions
    double avg = average(MovieNum,num);
    double med = median(MovieNum,num);
    double mod = mode(MovieNum,num);
    cout<<fixed<<setprecision(1)<<avg<<endl;
    cout<<fixed<<setprecision(1)<<med<<endl;
    cout<<fixed<<setprecision(1)<<mod<<endl;
    delete [] MovieNum;// free memory
    MovieNum=nullptr;// avoid dangling pointer
    return 0;
}
double average(int *arry, int n)
{
    double sum=0.0;
    for(int i=0;i<n;i++)
    {
        sum+=*(arry+i);
    }
    return sum/n;
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
double mode(int *arry, int n)
{
    int maxValue = -1, maxCount = 0;
    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (arry[j] == arry[i]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            maxValue = arry[i];
        }
    }
    return maxValue;
}