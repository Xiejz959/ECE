#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char answer[25]={'E',
                     'A','D','B','B','C',
                     'B','A','B','C','D',
                     'A','C','D','B','D',
                     'C','C','A','D','B'};//E is invalid
    char input[25];
    for(int i=1;i<=20;i++)
    {
        cout<<"Enter answer for question "<<i<<": ";
        cin>>input[i];
    }
    int correct=0;
    for(int i=1;i<=20;i++)
    {
        if(input[i]==answer[i])
            correct++;
    }
    if(correct>=15)
        cout<<"You passed the exam "<<endl;
    else
        cout<<"You failed the exam "<<endl;
    cout<<"You got "<<correct<<" correct answers out of 20"<<endl;
    cout<<"You got "<<20-correct<<" wrong answers out of 20"<<endl;
    cout<<"the incorrect answers are "<<endl;
    for(int i=1;i<=20;i++)
    {
        if(input[i]!=answer[i])
            cout<<"Question "<<i<<" is incorrect."<<endl;
    }
    return 0;
}