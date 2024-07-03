#include <iostream>
#include "nlohmann/json.hpp"
#include "inventory.h"
#include <vector>
using namespace std;
using json = nlohmann::json;

Inventory::Inventory() : quantity(0), totalPrice(0.0) {}

Inventory::Inventory(const string& itemName, int quantity, double totalPrice, const Boutique& boutique)
        : itemName(itemName), quantity(quantity), totalPrice(totalPrice), boutique(boutique) {}

string Inventory::getItemName() const {
    return itemName;
}

int Inventory::getQuantity() const {
    return quantity;
}

double Inventory::getTotalPrice() const {
    return totalPrice;
}

const Boutique& Inventory::getBoutique() const {
    return boutique;
}
void Inventory::setItemName(const string& name) {
    itemName = name;
}

void Inventory::setQuantity(int qty) {
    quantity = qty;
}

void Inventory::setTotalPrice(double price) {
    totalPrice = price;
}

//void Inventory::setBoutiqueId(int id) {
//    BoutiqueId = id;
//}

void Inventory::setBoutique(const Boutique& boutique) {
        this->boutique=boutique;
    }

void Inventory::addInventoryInJSONArray(const Inventory& newInventory) {
    ifstream file("inventory.json");
    json existingData;
    if (file.is_open()) {
        file >> existingData;
        file.close();
    }
    if (!existingData.is_array()) {
        existingData = json::array();
    }
    for (size_t i = 0; i < existingData.size(); ++i) {
        const auto& inventory = existingData[i];
        if (inventory["itemName"] == newInventory.getItemName()) {
            cout << "Inventory with item name " << newInventory.getItemName() << " already exists. Not adding again." << endl;
            return;
        }
    }
    json jsonInventory;
    jsonInventory["itemName"] = newInventory.getItemName();
    jsonInventory["quantity"] = newInventory.getQuantity();
    jsonInventory["totalPrice"] = newInventory.getTotalPrice();
    jsonInventory["boutique"] = {
            {"boutiqueId", newInventory.getBoutique().getId()},
            {"name", newInventory.getBoutique().getName()},
            {"location", newInventory.getBoutique().getLocation()}
    };
    existingData.push_back(jsonInventory);
    ofstream outFile("inventory.json");
    if (outFile.is_open()) {
        outFile << existingData.dump(4);
        outFile.close();
        cout << "Inventory added successfully." << endl;
    } else {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}

void Inventory::updateInventoryInJSONArray(const Inventory& updatedInventory) {
    ifstream file("inventory.json");
    json existingData;
    if (file.is_open()) {
        file >> existingData;
        file.close();
    } else {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }

    if (!existingData.is_array() || existingData.empty()) {
        cerr << "Error: Inventory file is empty or doesn't exist." << endl;
        return;
    }

    bool inventoryUpdated = false;

    for (auto& inventory : existingData) {
        if (inventory["itemName"] == updatedInventory.getItemName()) {
            inventory["quantity"] = updatedInventory.getQuantity();
            inventory["totalPrice"] = updatedInventory.getTotalPrice();
            inventory["boutique"] = {
                    {"boutiqueId", updatedInventory.getBoutique().getId()},
                    {"name", updatedInventory.getBoutique().getName()},
                    {"location", updatedInventory.getBoutique().getLocation()}
            };
            inventoryUpdated = true;
            cout << "Inventory item \"" << updatedInventory.getItemName() << "\" updated successfully." << endl;
            break;
        }
    }

    if (!inventoryUpdated) {
        cout << "Inventory item \"" << updatedInventory.getItemName() << "\" not found. Unable to update." << endl;
        return;
    }

    ofstream outFile("inventory.json");
    if (outFile.is_open()) {
        outFile << existingData.dump(4);
        outFile.close();
        cout << "Inventory file updated successfully." << endl;
    } else {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}

bool Inventory::findInventoryItemByName(const string &itemName) {
    ifstream inFile("inventory.json");
    json existingData;

    if (inFile.is_open()) {
        inFile >> existingData;
        inFile.close();
    }

    for (const auto &inventory : existingData) {
        if (inventory["itemName"] == itemName) {
            cout << "Item Name: " << inventory["itemName"] << endl;
            cout << "Quantity: " << inventory["quantity"] << endl;
            cout << "Total Price: " << inventory["totalPrice"] << endl;
            cout << "Boutique ID: " << inventory["boutique"]["boutiqueId"] << endl;
            cout << "Boutique Name: " << inventory["boutique"]["name"] << endl;
            cout << "Boutique Location: " << inventory["boutique"]["location"] << endl;
            return true;
        }
    }
    cout<<"inventory name does not exists."<<endl;
    return false;
}

void Inventory::removeInventoryByName(const string& itemNameToRemove) {
    ifstream file("inventory.json");
    json existingData;
    if (file.is_open()) {
        file >> existingData;
        file.close();
    } else {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }

    if (!existingData.is_array() || existingData.empty()) {
        cerr << "Error: Inventory file is empty or doesn't exist." << endl;
        return;
    }

    bool inventoryRemoved = false;

    for (auto it = existingData.begin(); it != existingData.end(); ++it) {
        if ((*it)["itemName"] == itemNameToRemove) {
            existingData.erase(it);
            inventoryRemoved = true;
            cout << "Inventory item \"" << itemNameToRemove << "\" removed successfully." << endl;
            break;
        }
    }

    if (!inventoryRemoved) {
        cout << "Inventory item \"" << itemNameToRemove << "\" not found. Unable to remove." << endl;
        return;
    }

    ofstream outFile("inventory.json");
    if (outFile.is_open()) {
        outFile << existingData.dump(4);
        outFile.close();
        cout << "Inventory file updated successfully." << endl;
    } else {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}

ostream& operator<<(ostream& os, const Inventory& inventory) {
    os << "Item Name: " << inventory.itemName << endl;
    os << "Quantity: " << inventory.quantity << endl;
    os << "Total Price: " << inventory.totalPrice << endl;
    os << "Boutique ID: " << inventory.boutique.getId() << endl;
    os << "Boutique Name: " << inventory.boutique.getName() << endl;
    os << "Boutique Location: " << inventory.boutique.getLocation() << endl;

    return os;
}

istream& operator>>(istream& is, Inventory& inventory) {
    cout << "Enter Item Name: ";
    is >> inventory.itemName;
    cout << "Enter Quantity: ";
    is >> inventory.quantity;
    cout << "Enter Total Price: ";
    is >> inventory.totalPrice;

    Boutique boutique;
    cout << "Enter Boutique ID: ";
    is >> boutique;
    inventory.setBoutique(boutique);

    return is;
}
