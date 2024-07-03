
#ifndef PROJECT_PRODUCT_H
#define PROJECT_PRODUCT_H
#include <iostream>
#include "nlohmann/json.hpp"
#include "inventory.h"
#include <vector>
using namespace std;
#include<string>
using json = nlohmann::json;
class Product {
private:
    string name;
    double price;
    string type;
    Inventory* inventory; // Aggregation with Inventory class

public:
    // Constructors

    Product();
    Product(const string& name, double price,string type, Inventory* inventory);

    // Destructor
    ~Product();

    // Getter methods
    string getName() const;
    double getPrice() const;
    string getType() const;
    const Inventory* getInventory() const;

    // Methods for JSON file operations
     void addProductToJsonFile(const string& filename);
     void updateProductInJsonFile(const string& filename);
     void removeProductFromJsonFile(const string& filename);
    virtual void displayFromJsonFile(const string& filename);
};

#endif //PROJECT_PRODUCT_H
