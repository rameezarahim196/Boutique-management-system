#ifndef PROJECT_BOUTIQUE_H
#define PROJECT_BOUTIQUE_H


#include <iostream>
#include<fstream>
#include <iomanip>
#include "nlohmann/json.hpp"
using namespace std;
#include<string>
class Boutique {
private:
    int boutiqueId;
    string name;
    string location;

public:
    Boutique();
    Boutique(int id, const string& n, const string& loc);
    int getId() const;
    string getName() const;
    string getLocation() const;
    friend istream& operator>>(istream& is, Boutique& boutique);
};
#endif //PROJECT_BOUTIQUE_H
