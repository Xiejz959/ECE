#include<iostream>
#include<cstring>
#include "BroadcastStation.h"
#include "RadioReceive.h"
int main()
{
    BroadcastStation stationA("Music", 99.5, "FM", "Pop");
    BroadcastStation stationB("News", 720.0, "AM", "News");

    RadioReceive myRadio;
    std::cout << "[1] Factory defaults" << std::endl;
    myRadio.displayCurrentState();

    std::cout << "\n[2] Set current station = stationA, set volume = 75" << std::endl;
    myRadio.setusepreset(stationA);
    myRadio.setVolume(75.0);
    myRadio.displayCurrentState();

    std::cout << "\n[3] Store current channel into Preset 1" << std::endl;
    myRadio.storeCurrentToPreset1();
    myRadio.displayCurrentState();

    std::cout << "\n[4] Switch current station to stationB, then store into Preset 2" << std::endl;
    myRadio.setusepreset(stationB);
    myRadio.storeCurrentToPreset2();
    myRadio.displayCurrentState();

    std::cout << "\n[5] Turn knobs: volume +1, frequency +1" << std::endl;
    myRadio.volumeUp();
    myRadio.frequencyUp();
    myRadio.displayCurrentState();

    std::cout << "\n[6] Select Preset 1" << std::endl;
    myRadio.selectPreset1();
    myRadio.displayCurrentState();

    std::cout << "\n[7] Turn knobs: volume -1, frequency -1" << std::endl;
    myRadio.volumeDown();
    myRadio.frequencyDown();
    myRadio.displayCurrentState();

    std::cout << "\n[8] Select Preset 2" << std::endl;
    myRadio.selectPreset2();
    myRadio.displayCurrentState();

    return 0;
}

BroadcastStation::BroadcastStation(std::string name, double frequency, std::string type, std::string genre)
{
    Name = name;
    Frequency = frequency;
    Type = type;
    Genre = genre;
}
void BroadcastStation::setterName(const std::string name)
{
    Name = name;
}
void BroadcastStation::setterFrequency(double frequency)
{
    Frequency = frequency;
}
void BroadcastStation::setterType(const std::string type)
{
    Type = type;
}
void BroadcastStation::setterGenre(const std::string genre)
{
    Genre = genre;
}
std::string BroadcastStation::getterName() const
{
    return Name;
}
double BroadcastStation::getterFrequency() const
{
    return Frequency;
}
std::string BroadcastStation::getterType() const
{
    return Type;
}
std::string BroadcastStation::getterGenre() const
{
    return Genre;
}

void RadioReceive::frequencyUp()
{
    CurrFrequency += 1.0;
}
void RadioReceive::frequencyDown()
{
    CurrFrequency -= 1.0;
}
void RadioReceive::volumeUp()
{
    Volume += 1.0;
}
void RadioReceive::volumeDown()
{
    Volume -= 1.0;
}
void RadioReceive::presetStation(const std::string stationName, const double stationFrequency, const std::string stationType, const std::string stationGenre)
{
    BroadcastStation presetStation(stationName, stationFrequency, stationType, stationGenre);
    setusepreset(presetStation);
}
void RadioReceive::setusepreset(const BroadcastStation station)
{
    setCurrName(station.getterName());
    setCurrFrequency(station.getterFrequency());
    setCurrType(station.getterType());
    setCurrGenre(station.getterGenre());
}
void RadioReceive::storeCurrentToPreset1()
{
    Station1 = BroadcastStation(CurrName, CurrFrequency, CurrType, CurrGenre);
}
void RadioReceive::storeCurrentToPreset2()
{
    Station2 = BroadcastStation(CurrName, CurrFrequency, CurrType, CurrGenre);
}
void RadioReceive::selectPreset1()
{
    setusepreset(Station1);
}
void RadioReceive::selectPreset2()
{
    setusepreset(Station2);
}
void RadioReceive::displayCurrentState() const
{
    std::cout << "Current Station: " << CurrName << std::endl;
    std::cout << "Frequency: " << CurrFrequency << " MHz" << std::endl;
    std::cout << "Type: " << CurrType << std::endl;
    std::cout << "Genre: " << CurrGenre << std::endl;
    std::cout << "Volume: " << Volume << std::endl;

    std::cout << "Preset 1: " << Station1.getterName()
              << " | " << Station1.getterFrequency() << " MHz"
              << " | " << Station1.getterType()
              << " | " << Station1.getterGenre()
              << std::endl;
    std::cout << "Preset 2: " << Station2.getterName()
              << " | " << Station2.getterFrequency() << " MHz"
              << " | " << Station2.getterType()
              << " | " << Station2.getterGenre()
              << std::endl;
}