#include<bits/stdc++.h>
#include<cstring>

class Car
{
    private:
        int yearModel;
        std::string make;
        int speed;
    public:
        Car(int ym, std::string m)
        {
            yearModel = ym;
            make = m;
            speed = 0;
        }

        void Accessor(std::string s)
        {
            if (s == "yearModel")
                std::cout << "Year Model: " << yearModel << std::endl;
            else if (s == "make")
                std::cout << "Make: " << make << std::endl;
            else if (s == "speed")
                std::cout << "Speed: " << speed << " mph" << std::endl;
        }

        void Accelerate()
        {
            speed += 5;
        }

        void Brake()
        {
            speed -= 5;
        }
};

int main()
{
    Car Benz(2020, "Mercedes");
    for(int i=0;i<5;i++)
    {
        Benz.Accelerate();
        Benz.Accessor("speed");
    }
    for(int i=0;i<5;i++)
    {
        Benz.Brake();
        Benz.Accessor("speed");
    }
    return 0;
}