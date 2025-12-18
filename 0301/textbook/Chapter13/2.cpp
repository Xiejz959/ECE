#include<iostream>
#include<string>

class Employee
{
    private:
        std::string name;
        long long idNumber;
        std::string department;
        std::string position;
    public:
        //constructors
        Employee(std::string n, long long id, std::string dept, std::string pos)
        {
            name = n;
            idNumber = id;
            department = dept;
            position = pos;
        }

        Employee(std::string n, long long id)
        {
            name = n;
            idNumber = id;
            department = "";
            position = "";
        }

        Employee()
        {
            name = "";
            idNumber = 0;
            department = "";
            position = "";
        }
        //accessor functions
        void showInfo()
        {
            std::cout<<"Name: "<<name<<std::endl;
            std::cout<<"ID Number: "<<idNumber<<std::endl;
            std::cout<<"Department: "<<department<<std::endl;
            std::cout<<"Position: "<<position<<std::endl;
        }
};

int main()
{
    Employee emp1("Susan Meyers", 47899, "Accounting", "Vice President");
    Employee emp2("Mark Jones", 39119, "IT", "Programmer");
    Employee emp3("Joy Rogers", 81774, "Manufacturing", "Engineer");

    std::cout<<"Employee 1 details:"<<std::endl;
    emp1.showInfo();
    std::cout<<std::endl;

    std::cout<<"Employee 2 details:"<<std::endl;
    emp2.showInfo();
    std::cout<<std::endl;

    std::cout<<"Employee 3 details:"<<std::endl;
    emp3.showInfo();
    std::cout<<std::endl;

    return 0;
}