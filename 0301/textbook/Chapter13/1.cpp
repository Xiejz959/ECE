#include<iostream>
#include<string>

class Date
{
    private:
        int day;
        int month;
        int year;
        std::string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    public:
        void setDate(int d, int m, int y)
        {
            day = d;
            month = m;
            year = y;
        }
        void showAmerican()
        {
            std::cout<<month<<"/"<<day<<"/"<<year<<std::endl;
        }
        void showEnglish()
        {
            std::cout<<months[month-1]<<" "<<day<<", "<<year<<std::endl;
        }
        void showUnofficial()
        {
            std::cout<<day<<" "<<months[month-1]<<" "<<year<<std::endl;
        }
};

int main()
{
    int d, m, y;
    Date date;
    std::cout<<"Enter day: ";
    std::cin>>d;
    while(d<1 || d>31)
    {
        std::cout<<"Invalid day. Enter again: ";
        std::cin>>d;
    }
    std::cout<<"Enter month: ";
    std::cin>>m;
    while(m<1 || m>12)
    {
        std::cout<<"Invalid month. Enter again: ";
        std::cin>>m;
    }
    std::cout<<"Enter year: ";
    std::cin>>y;
    date.setDate(d, m, y);
    int format;
    std::cout<<"Choose date format (1: American, 2: English, 3: Unofficial): ";
    std::cin>>format;
    switch(format)
    {
        case 1:
            date.showAmerican();
            break;
        case 2:
            date.showEnglish();
            break;
        case 3:
            date.showUnofficial();
            break;
        default:
            std::cout<<"Invalid format choice."<<std::endl;
    }
    return 0;
}