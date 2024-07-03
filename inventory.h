
#ifndef PROJECT_INVENTORY_H
#define PROJECT_INVENTORY_H
#include <iostream>
#include "boutique.h"
#include <vector>
#include "nlohmann/json.hpp"
using namespace std;
#include<sstream>
using json = nlohmann::json;
class Inventory {
private:
    string itemName;
    int quantity;
    double totalPrice;
    Boutique boutique; // Boutique object as a member variable

public:
    Inventory();
    Inventory(const string& itemName, int quantity, double totalPrice, const Boutique& boutique);

    string getItemName() const;
    int getQuantity() const;
    double getTotalPrice() const;
    const Boutique& getBoutique() const; // Return a reference to the Boutique object

    void setItemName(const string& name);
    void setQuantity(int qty);
    void setTotalPrice(double price);
    void setBoutique(const Boutique& boutique);

    void addInventoryInJSONArray(const Inventory& newInventory);
    void updateInventoryInJSONArray(const Inventory& updatedInventory);
    bool findInventoryItemByName(const string &itemName);
    void removeInventoryByName(const string& itemNameToRemove);

    friend ostream& operator<<(ostream& os, const Inventory& inventory);
    friend istream& operator>>(istream& is, Inventory& inventory);
};


#endif //PROJECT_INVENTORY_H
