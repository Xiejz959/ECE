#include<string>
#include<iostream>
#include "Map.h"

//initialize a object map
Map::Map()
{
    m_size = 0;
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
    if(m_size == DEFAULT_MAX_ITEMS)
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
    Map::m_map[m_size].key = key;
    Map::m_map[m_size].value = value;
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
        if(Map::m_map[i].key == key)
        {
            Map::m_map[i].value =value;
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
        if(Map::m_map[i].key == key)
        {
            // Keep used entries compact: shift left from i+1.
            for(int j=i; j<m_size-1; j++)
            {
                m_map[j] = m_map[j+1];
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
        if(Map::m_map[i].key ==key)
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
        if(Map::m_map[i].key == key)
        {
            value = Map::m_map[i].value;
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
            if(Map::m_map[k].key < Map::m_map[j].key)
            {
                cnt++;
            }
        }
        if (cnt == i)
        {
            key = Map::m_map[j].key;
            value = Map::m_map[j].value;
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
    for(int i=0; i<DEFAULT_MAX_ITEMS;i++)
    {
        pair tmp_pair =m_map[i];
        m_map[i] = other.m_map[i];
        other.m_map[i] = tmp_pair;
    }
}