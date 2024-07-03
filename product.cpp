#include <iostream>
#include "nlohmann/json.hpp"
#include "product.h"
using namespace std;
#include <vector>
#include<string>
using json = nlohmann::json;

// Default constructor
Product::Product() : price(0.0),type(), inventory(nullptr) {}

// Parameterized constructor
Product::Product(const string& name, double price,string type, Inventory* inventory)
        : name(name), price(price),type(type), inventory(inventory) {}

// Destructor
Product::~Product() {
    delete inventory; // Deallocate memory
}

// Getter method for name
string Product::getName() const {
    return name;
}
//Getter method for type
string Product::getType() const{
    return type;
}
// Getter method for price
double Product::getPrice() const {
    return price;
}

// Getter method for inventory
const Inventory* Product::getInventory() const {
    return inventory;
}

// Method to add product to JSON file
void Product::addProductToJsonFile(const string& filename) {
    ifstream file(filename);
    json existingData;
    if (file.is_open()) {
        file >> existingData;
        file.close();
    } else {
        existingData = json::array();
    }

    bool productExists = false;
    for (const auto& product : existingData) {
        if (product["name"] == name) {
            productExists = true;
            break;
        }
    }

    if (!productExists) {
        json productJson;
        productJson["name"] = name;
        productJson["price"] = price;
        productJson["inventory"] = {
                {"itemName", inventory->getItemName()},
                {"quantity", inventory->getQuantity()},
                {"totalPrice", inventory->getTotalPrice()}
        };

        existingData.push_back(productJson);

        ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << existingData.dump(4);
            outFile.close();
            cout << "Product added successfully." << endl;
        } else {
            cerr << "Error: Unable to open file for writing." << endl;
        }
    } else {
        cerr << "Error: Product with name " << name << " already exists." << endl;
    }
}

// Method to update product in JSON file
void Product::updateProductInJsonFile(const string& filename) {
    ifstream file(filename);
    json existingData;
    if (file.is_open()) {
        file >> existingData;
        file.close();
    } else {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }

    bool productUpdated = false;
    for (auto& product : existingData) {
        if (product["name"] == name) {
            product["price"] = price;
            product["inventory"]["itemName"] = inventory->getItemName();
            product["inventory"]["quantity"] = inventory->getQuantity();
            product["inventory"]["totalPrice"] = inventory->getTotalPrice();
            productUpdated = true;
            cout << "Product \"" << name << "\" updated successfully." << endl;
            break;
        }
    }

    if (!productUpdated) {
        cerr << "Error: Product with name \"" << name << "\" not found. Unable to update." << endl;
        return;
    }

    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << existingData.dump(4);
        outFile.close();
        cout << "Product file updated successfully." << endl;
    } else {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}

// Method to remove product from JSON file
void Product::removeProductFromJsonFile(const string& filename) {
    ifstream file(filename);
    json existingData;
    if (file.is_open()) {
        file >> existingData;
        file.close();
    } else {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }

    bool productRemoved = false;
    for (auto it = existingData.begin(); it != existingData.end(); ++it) {
        if ((*it)["name"] == name) {
            existingData.erase(it);
            productRemoved = true;
            cout << "Product \"" << name << "\" removed successfully." << endl;
            break;
        }
    }

    if (!productRemoved) {
        cerr << "Error: Product with name \"" << name << "\" not found. Unable to remove." << endl;
        return;
    }

    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << existingData.dump(4);
        outFile.close();
        cout << "Product file updated successfully." << endl;
    } else {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}

// Method to display products from JSON file
void Product::displayFromJsonFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file." << endl;
        return;
    }
    json productsJson;
    file >> productsJson;
    file.close();
    if (productsJson.empty()) {
        cout << "No products in the file." << endl;
    } else {
        cout << "Displaying products from file:" << endl;
        for (const auto &productJson: productsJson) {
            string productName = productJson["name"];
            double productPrice = productJson["price"];
            string inventoryItemName = productJson["inventory"]["itemName"];
            int inventoryQuantity = productJson["inventory"]["quantity"];
            double inventoryTotalPrice = productJson["inventory"]["totalPrice"];

            cout << "Product Name: " << productName << endl;
            cout << "Price: $" << productPrice << endl;
        }
    }
}