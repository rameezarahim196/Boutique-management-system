#ifndef PROJECT_FEMALE_H
#define PROJECT_FEMALE_H

#include <iostream>
#include "nlohmann/json.hpp"
#include "product.h"
#include <vector>
#include <string>

using json = nlohmann::json;

class FemaleProduct : public Product {
public:
    FemaleProduct(const string& name, double price, const string& type,Inventory* inventory);

    void addSuit(const Product& p);
    void addScarf(const Product& p);
    void updateSuit(const Product& p);
    void updateScarf(const Product& p);
    void removeSuit(const Product& p);
    void removeScarf(const Product& p);
    void displayFromJsonFile(const string& filename) override;

};

#endif // PROJECT_FEMALE_H
