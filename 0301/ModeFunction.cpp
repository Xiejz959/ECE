#include<bits/stdc++.h>
using namespace std;
struct statistics
{
    int number=-1;
    int frequency=0;
};
int ModeJudge(int *num, int length);
bool cmp(struct statistics a, struct statistics b)
{
    return a.frequency>b.frequency;
}
int main()
{
    int length=0;
    cin>>length;
    int *num=new int[length];
    for(int i=0;i<length;i++)
    {
        cin>>*(num+i);
    }
    int mode=ModeJudge(num,length);
    if(mode==-1) cout<<"No mode"<<endl;
    else cout<<"Mode: "<<mode<<endl;
    return 0;
}
int ModeJudge(int *num, int length)
{

    statistics *stat=new statistics[length];
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<length;j++)//state the frequency of each number
        {
            if((stat+j)->number== *(num+i)) //find
            {
                (stat+j)->frequency++;
                break;
            }
            else if((stat+j)->number==-1) //do not find
            {
                (stat+j)->number=*(num+i);
                (stat+j)->frequency=1;
                break;
            }
        }
    }
    sort(stat,stat+length,cmp);
    if((stat+0)->frequency==(stat+1)->frequency) return -1; // no mode
    else return (stat+0)->number;
}