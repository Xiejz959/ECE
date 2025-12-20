#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>
class Inventory
{
    private:
        int itemNumber;
        int quantity;
        double cost;
        double totalCost;
    public:
        Inventory()
        {
            itemNumber = 0;
            quantity = 0;
            cost = 0.0;
            totalCost = 0.0;
        }

        Inventory(int itemNum, int qty, double cst)
        {
            setItemNumber(itemNum);
            setQuantity(qty);
            setCost(cst);
            setTotalCost();
        }

        // Mutators (Input Validation: do not accept negative values)
        void setItemNumber(int itemNum)
        {
            itemNumber = (itemNum < 0) ? 0 : itemNum;
        }
        void setQuantity(int qty)
        {
            quantity = (qty < 0) ? 0 : qty;
            setTotalCost();
        }
        void setCost(double cst)
        {
            cost = (cst < 0.0) ? 0.0 : cst;
            setTotalCost();
        }
        void setTotalCost()
        {
            totalCost = quantity * cost;
        }

        // Accessors
        int getItemNumber() const
        {
            return itemNumber;
        }
        int getQuantity() const
        {
            return quantity;
        }
        double getCost() const
        {
            return cost;
        }
        double getTotalCost() const
        {
            return totalCost;
        }
};
#endif