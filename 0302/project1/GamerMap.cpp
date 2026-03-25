# include "GamerMap.h"
# include <iostream>

//init
GamerMap::GamerMap()
{
    //let map initilize per se
}

//add new gamer to the map
// new gamer has 0 hours
bool GamerMap::addGamer(std::string name)
{
    if(m_gamers.contains(name))
    {
        std::cerr << "The gamer is already exist!" <<std::endl;
        return false;
    }
    return m_gamers.insert(name, 0);
}

// check how many hours someone spent in game
// people not exist return -1
double GamerMap::hoursSpent(std::string name) const
{
    double hours = -1;
    if(m_gamers.get(name, hours))
    {
        return hours;
    }
    std::cerr << "The gamer is not exist!" <<std::endl;
    return -1;
}

//false when no such gamer or hours is negative
//true when update successfully
bool GamerMap::play(std::string name, double hours)
{
    if(hours < 0)
    {
        return false;
    }

    double oldHours = 0;
    if(!m_gamers.get(name, oldHours))
    {
        return false;
    }

    return m_gamers.update(name, oldHours + hours);
}

//check the number of gamers
int GamerMap::numGamers() const
{
    return m_gamers.size();
}

//print info of all gamers
void GamerMap::print() const
{
    std::string name;
    double hours;
    for(int i=0;i<m_gamers.size();i++)
    {
        m_gamers.get(i,name,hours);
        std::cout << name << " " << hours << std::endl;
    }
}