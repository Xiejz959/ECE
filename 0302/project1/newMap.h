#ifndef NEWMAP_H
#define NEWMAP_H

#include<string>

// type alias for data
using KeyType = std::string;
using ValueType = double;

class Map
{
    public:
        Map();
        Map(int capacity);
        ~Map();
        Map(const Map& other);
        Map& operator=(const Map& other);
        bool empty() const;
        int size() const;
        bool insert(const KeyType& key, const ValueType& value);
        bool update(const KeyType& key, const ValueType& value);
        bool insertOrUpdate(const KeyType& key, const ValueType& value);
        bool erase(const KeyType& key);
        bool contains(const KeyType& key) const;
        bool get(const KeyType& key, ValueType& value) const;
        bool get(int i, KeyType& key, ValueType& value) const;
        void swap(Map& other);
    private:
        static constexpr int DEFAULT_MAX_ITEMS = 150;
        struct pair
        {
            KeyType key;
            ValueType value;
        };
        pair* m_data;
        int m_size;
        int m_capacity;

};


#endif


