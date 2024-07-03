#include <iostream>
#include "boutique.h"
#include "nlohmann/json.hpp"
using namespace std;
#include<sstream>
#include <iomanip>
using json = nlohmann::json;
Boutique::Boutique()
{

}
Boutique::Boutique(int id, const string& n, const string& loc)
        : boutiqueId(id), name(n), location(loc) {}

int Boutique::getId() const {
    return boutiqueId;
}
string Boutique::getName() const {
    return name;
}

string Boutique::getLocation() const {
    return location;
}

istream& operator>>(istream& is, Boutique& boutique) {
    cout << "Enter Boutique ID: ";
    is >> boutique.boutiqueId;
    cout << "Enter Boutique Name: ";
    is >> boutique.name;
    cout << "Enter Boutique Location: ";
    is >> boutique.location;
    return is;
}

