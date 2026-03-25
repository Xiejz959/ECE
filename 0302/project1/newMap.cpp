#include<string>
#include<iostream>
#include<cstdlib>
#include "newMap.h"

//initialize a object map
Map::Map()
{
    m_capacity = DEFAULT_MAX_ITEMS;
    m_size = 0;
    m_data = new pair[m_capacity];
}

//initialize a object map
Map::Map(int capacity)
{
    if(capacity < 0)
    {
        std::cerr << "Capacity cannot be negative! Set to 0." <<std::endl;
        capacity = 0;
    }
    m_capacity = capacity;
    m_size = 0;
    m_data = new pair[m_capacity];
}

//destructor
Map::~Map()
{
    delete[] m_data;
}

//copy constructor
Map::Map(const Map& other)
{
    m_capacity = other.m_capacity;
    m_size = other.m_size;
    m_data = new pair[m_capacity];
    
    for(int i=0; i<m_size; i++)
    {
        m_data[i] = other.m_data[i];
    }
}

Map& Map::operator=(const Map& other)
{
    if(this != &other)
    {
        delete[] m_data;
        m_capacity = other.m_capacity;
        m_size = other.m_size;
        m_data = new pair[m_capacity];

        for(int i=0;i<m_size;i++)
        {
            m_data[i]= other.m_data[i];
        }
    }
    return *this;
}

//empty is true, otherwise is false
bool Map::empty() const
{
    return m_size == 0;
}

//return the number of pairs
int Map::size() const
{
    return m_size;
}

//insert new pair to the map
//return true when add successfully
//return false and indicate whether exist already or full
bool Map::insert(const KeyType& key, const ValueType& value)
{
    if(m_size == m_capacity)
    {
        std::cerr << "Map is already full!" <<std::endl;
        return false;
    }
    if(Map::contains(key))
    {
        std::cerr << "The key is already exist!" <<std::endl;
        return false;
    }
    //add new pair to the map
    Map::m_data[m_size].key = key;
    Map::m_data[m_size].value = value;
    m_size++;
    return true;
}

// map existed key to another value
// return true when update successfully
// return false when the key is not exist
bool Map::update(const KeyType& key, const ValueType& value)
{
    //update the value of the key
    for(int i=0;i<m_size;i++)
    {
        if(Map::m_data[i].key == key)
        {
            Map::m_data[i].value =value;
            return true;
        }
    }
    //the input key is not exist
    std::cerr << "The key is not exist!"<< std::endl;
    return false;
}

// uniform for insert and update
// return true when insert or update successfully
// return false when the key is not exist and the map is full
bool Map::insertOrUpdate(const KeyType& key, const ValueType& value)
{
    if(Map::contains(key))//already exist
    {
        return Map::update(key, value);
    }
    else//new key
    {
        return Map::insert(key, value);
    }

}

//remove exist pair
//true when erase and false when not
bool Map::erase(const KeyType& key)
{
    if(!Map::contains(key))
    {
        std::cerr << "Such a key is not exist!" <<std::endl;
        return false;
    }

    for(int i=0;i<m_size;i++)
    {
        if(Map::m_data[i].key == key)
        {
            // Keep used entries compact: shift left from i+1.
            for(int j=i; j<m_size-1; j++)
            {
                m_data[j] = m_data[j+1];
            }
            m_size--;
            return true;
        }
    }

    return false;
}

//true when contain the key otherwise false
bool Map::contains(const KeyType& key) const
{
    for(int i=0;i<m_size;i++)
    {
        if(Map::m_data[i].key ==key)
        {
            return true;
        }
    }
    return false;
}

//get1 determine whether the key exist, whether the value is same as the in map value
//get2 sortthe map and find the i-th max pair in map
bool Map::get(const KeyType& key, ValueType& value) const
{
    if(!Map::contains(key))
    {
        std::cerr << "Such a key is not exist!" <<std::endl;
        return false;
    }

    for(int i=0;i<m_size;i++)
    {
        if(Map::m_data[i].key == key)
        {
            value = Map::m_data[i].value;
            return true;
        }
    }

    return false;
}
bool Map::get(int i, KeyType& key, ValueType& value) const
{
    // Return the pair whose key is the i-th smallest (0-based).
    // keep the map's structure, do not sort it.
    if(i < 0 || i >= m_size)
    {
        return false;
    }

    for(int j=0;j<m_size;j++)
    {
        int cnt = 0;
        for(int k=0; k<m_size; k++)
        {
            if(Map::m_data[k].key < Map::m_data[j].key)
            {
                cnt++;
            }
        }
        if (cnt == i)
        {
            key = Map::m_data[j].key;
            value = Map::m_data[j].value;
            return true;
        }
    }

    return false;
}

//exchange the content of two map
// based on task5, do not copy the object
void Map::swap(Map& other)
{
    int tmp_size = m_size;
    m_size = other.m_size;
    other.m_size = tmp_size;
    //the time to swap is constant, not relying on the map size
    pair* tmp_data = m_data;
    m_data = other.m_data;
    other.m_data = tmp_data;

    int tmp_capacity = m_capacity;
    m_capacity = other.m_capacity;
    other.m_capacity = tmp_capacity;
}