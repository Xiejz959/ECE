#include<bits/stdc++.h>
using namespace std;
struct MovieData
{
    string title;
    string director;
    int yearReleased;
    int runningTime;
    double cost;
    double revenue;
};
void displayMovieInfo(MovieData *movie)
{
    cout<<"Title: "<<movie->title<<endl;
    cout<<"Director: "<<movie->director<<endl;
    cout<<"Year Released: "<<movie->yearReleased<<endl;
    cout<<"Running Time (in minutes): "<<movie->runningTime<<endl;
    cout<<"benifit: "<<(movie->revenue)-(movie->cost)<<"$"<<endl;
}
int main()
{
    MovieData movie1={"Flipped","Rob Reiner",2010,90,14000000,4300000};
    MovieData movie2={"Zootopia","Byron Howard and Rich Moore",2016,108,150000000,1023784195};
    displayMovieInfo(&movie1);
    displayMovieInfo(&movie2);
    return 0;
}