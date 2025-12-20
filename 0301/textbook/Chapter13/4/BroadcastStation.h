#ifndef BROADCASTSTATION_H
#define BROADCASTSTATION_H
#include <string>
class BroadcastStation
{
    private:
        std::string Name;
        double Frequency;
        std::string Type;
        std::string Genre;
    public:
        BroadcastStation(std::string name="", double  frequency=0.0, std::string type="", std::string genre="");
        //@set info
        void setterName(const std::string name);
        void setterFrequency(double frequency);
        void setterType(const std::string type);
        void setterGenre(const std::string genre);    
        //@get info
        std::string getterName() const;
        double getterFrequency() const;
        std::string getterType() const;
        std::string getterGenre() const;
};
#endif