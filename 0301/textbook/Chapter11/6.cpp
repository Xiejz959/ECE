#include<bits/stdc++.h>
using namespace std;
struct texbib
{
    string originator;
    string quotation;
    int likes;
};
void display(texbib *citation,int n)
{
    int totallikes=0;
    double averlikes=0;
    for(int i=0;i<n;i++)
    {
        totallikes+=citation[i].likes;
    }
    averlikes=double(totallikes)/n;
    for(int i=0;i<n;i++)
    {
        if(citation[i].likes>averlikes)
        {
            cout<<"Citations with likes more than average likes:\n";
            cout<<citation[i].originator<<"\n"<<citation[i].quotation<<"\n"<<citation[i].likes<<"\n";
            cout<<"----------------------\n";
        }
    }
}
int main()
{
    int n=7;
    texbib citation[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter originator, quotation and likes:\n";
        getline(cin,citation[i].originator);
        getline(cin,citation[i].quotation);
        int tmp;cin>>tmp;
        if(tmp<0)
        {
            i--;
            continue;
        }
        else
        {
            citation[i].likes=tmp;
            cin.ignore();
        }
    }
}