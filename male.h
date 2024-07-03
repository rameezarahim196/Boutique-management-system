#ifndef PROJECT_MALE_H
#define PROJECT_MALE_H

#include <iostream>
#include "nlohmann/json.hpp"
#include "product.h"
#include <vector>
#include <string>
using namespace std;
using json = nlohmann::json;

class MaleProduct : public Product {

public:
    MaleProduct();
    MaleProduct(const string& name, double price, const string& type, Inventory* inventory);
    // Implementations of abstract methods
    void addSuit(const Product& p);
    void addCoat(const Product& p);
    void removeSuit(const Product& p);
    void removeCoat(const Product& p);
    void updateSuit(const Product& p);
    void updateCoat(const Product& p);
    void displayFromJsonFile(const string& filename) override;

    // Other methods specific to male products
};
#endif //PROJECT_MALE_H
