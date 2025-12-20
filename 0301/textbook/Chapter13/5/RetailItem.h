#ifndef RETAILITEM_H
#define RETAILITEM_H
#include <string>
class RetailItem
{
    private:
        std::string description;
        int unitsOnHand;
        double price;
    public:
        RetailItem(std::string desc, int units, double prc)
        {
            description = desc;
            unitsOnHand = units;
            price = prc;
        }
        void updateDescription(std::string desc)
        {
            description = desc;
        }
        void updateUnitsOnHand(int units)
        {
            unitsOnHand = units;
        }
        void updatePrice(double prc)
        {
            price = prc;
        }
        std::string getDescription() const
        {
            return description;
        }
        int getUnitsOnHand() const
        {
            return unitsOnHand;
        }
        double getPrice() const
        {
            return price;
        }
};
#endif 