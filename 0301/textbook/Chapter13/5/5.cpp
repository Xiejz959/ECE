#include<iostream>
#include "RetailItem.h"
#include<string>
int main()
{
    RetailItem item1("Jacket", 12, 59.95);
    RetailItem item2("Designer Jeans", 40, 34.95);
    RetailItem item3("Shirt", 20, 24.95);

    std::cout << "Item 1: " << item1.getDescription() << ", Units on Hand: " << item1.getUnitsOnHand() << ", Price: $" << item1.getPrice() << std::endl;
    std::cout << "Item 2: " << item2.getDescription() << ", Units on Hand: " << item2.getUnitsOnHand() << ", Price: $" << item2.getPrice() << std::endl;
    std::cout << "Item 3: " << item3.getDescription() << ", Units on Hand: " << item3.getUnitsOnHand() << ", Price: $" << item3.getPrice() << std::endl;

    return 0;
}