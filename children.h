
#ifndef PROJECT_CHILDREN_H
#define PROJECT_CHILDREN_H
#include <iostream>
#include "nlohmann/json.hpp"
#include"product.h"
#include <vector>
using namespace std;
#include<string>
using json = nlohmann::json;

class KidsProduct : public Product {
    public:
        KidsProduct(const string& name, double price, const string& type, Inventory* inventory);

        void addShirt(const Product& p);
        void addPant(const Product& p);  // Method for adding pants
        void addSuit(const Product& p);  // Method for adding suits
        void updateShirt(const Product& p);
        void updatePant(const Product& p);  // Method for updating pants
        void updateSuit(const Product& p);  // Method for updating suits
        void removeShirt(const  Product& p);
        void removePant(const Product& p);  // Method for removing pants
        void removeSuit(const Product& p);  // Method for removing suits
        void displayFromJsonFile(const string& filename) override;
    };


#endif //PROJECT_CHILDREN_H
