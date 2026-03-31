#include<string.h>
#include<iostream>
using namespace std;

int ValidString(string str)
{
    int len = str.length();
    int point = 0;
    int ValidCount = 0;
    for(int i=0;i<len;i++)
    {
        int position = 0;
        if(str[i] == ')')
        {
            continue;
        }
        else
        {
            position ++;
            for(point=i+1;point<len;point++)
            {
                if((str[point]==')' && position%2==1)||(str[point]=='(' && position%2==0))
                {
                    position++;
                }
                else
                {
                    break;
                }
            }
            if(str[point] == '(')
                i = point-1;
            else
                i = point;
                ValidCount = max(ValidCount,position);
        }
    }
    return ValidCount;
}

int main()
{
    string par_str="";
    cin>>par_str;
    cout<<ValidString(par_str)<<endl;
    return 0;
}