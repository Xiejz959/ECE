#ifndef radio_receive_h
#define radio_receive_h
#include<cstring>
#include "BroadcastStation.h"
class RadioReceive
{
    private:
        BroadcastStation Station1, Station2;
        double Volume;
        std::string CurrName;
        double CurrFrequency;
        std::string CurrType;
        std::string CurrGenre;
    public:
        RadioReceive()
        {
            Volume = 0.0;
            CurrName = "";
            CurrFrequency = 0.0;
            CurrType = "";
            CurrGenre = "";
            Station1 = BroadcastStation(" ", 0.0, " ", " ");
            Station2 = BroadcastStation(" ", 0.0, " ", " ");
        }
        //@set info
        void setStation1(const BroadcastStation station)
        {
            Station1 = station;
        }
        void setStation2(const BroadcastStation station)
        {
            Station2 = station;
        }
        void setVolume(const double volume)
        {
            Volume = volume;
        }
        void setCurrName(const std::string name)
        {
            CurrName = name;
        }
        void setCurrFrequency(const double frequency)
        {
            CurrFrequency = frequency;
        }
        void setCurrType(const std::string type)
        {
            CurrType = type;
        }
        void setCurrGenre(const std::string genre)
        {
            CurrGenre = genre;
        }
        //@get info
        BroadcastStation getStation1() const
        {
            return Station1;
        }
        BroadcastStation getStation2() const
        {
            return Station2;
        }
        double getVolume() const
        {
            return Volume;
        } 
        std::string getCurrName() const
        {
            return CurrName;
        }
        double getCurrFrequency() const
        {
            return CurrFrequency;
        }
        std::string getCurrType() const
        {
            return CurrType;
        }
        std::string getCurrGenre() const
        {
            return CurrGenre;
        }
        //@knobs (increase/decrease by 1 unit)
        void frequencyUp();
        void frequencyDown();
        void volumeUp();
        void volumeDown();

        //@presets
        void presetStation(const std::string stationName, const double stationFrequency, const std::string stationType, const std::string stationGenre);
        void setusepreset(const BroadcastStation station);
        void storeCurrentToPreset1();
        void storeCurrentToPreset2();
        void selectPreset1();
        void selectPreset2();
        //@display current state
        void displayCurrentState() const;
};
#endif