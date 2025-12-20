#include<iostream>
#include "Inventory.h"
int main()
{
    Inventory item1(1001, 5, 10.0);
    Inventory item2(1002, 3, 20.0);

    std::cout << "Item 1:" << std::endl;
    std::cout << "Item Number: " << item1.getItemNumber() << std::endl;
    std::cout << "Quantity: " << item1.getQuantity() << std::endl;
    std::cout << "Cost per Item: $" << item1.getCost() << std::endl;
    std::cout << "Total Cost: $" << item1.getTotalCost() << std::endl;

    std::cout << "\nItem 2:" << std::endl;
    std::cout << "Item Number: " << item2.getItemNumber() << std::endl;
    std::cout << "Quantity: " << item2.getQuantity() << std::endl;
    std::cout << "Cost per Item: $" << item2.getCost() << std::endl;
    std::cout << "Total Cost: $" << item2.getTotalCost() << std::endl;

    // Demonstrate input validation (negative values are not accepted)
    Inventory badItem(-1, -5, -9.99);
    std::cout << "\nBad Item (after validation):" << std::endl;
    std::cout << "Item Number: " << badItem.getItemNumber() << std::endl;
    std::cout << "Quantity: " << badItem.getQuantity() << std::endl;
    std::cout << "Cost per Item: $" << badItem.getCost() << std::endl;
    std::cout << "Total Cost: $" << badItem.getTotalCost() << std::endl;

    return 0;
}