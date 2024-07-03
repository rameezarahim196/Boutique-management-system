#include <iostream>
#include "BoutiqueManager.h"
#include <iomanip>
#include "nlohmann/json.hpp"
using namespace std;
#include<sstream>

using json = nlohmann::json;

BoutiqueManager* BoutiqueManager::instance = nullptr; // Initialize Singleton instance

//constructor
BoutiqueManager::BoutiqueManager() {
}

BoutiqueManager* BoutiqueManager::getInstance() {
    if (instance == nullptr) {
        instance = new BoutiqueManager();
    }
    return instance;
}

void BoutiqueManager::addBoutique(const Boutique& boutique) {
    boutiques.push_back(boutique);
}

void BoutiqueManager::removeBoutique(int id) {
    for (auto it = boutiques.begin(); it != boutiques.end(); ++it) {
        if (it->getId() == id) {
            boutiques.erase(it);
            break;
        }
    }
}

void BoutiqueManager::displayBoutiques() const {
    ifstream file("boutique.json");
    if (!file.is_open()) {
        cout << "Error: Unable to open file." << endl;
        return;
    }
    json boutiquesJson;
    file >> boutiquesJson;
    file.close();
    if (boutiquesJson.empty()) {
        cout << "No boutiques entered in the file." << endl;
    } else {
        cout << "Displaying boutiques from file:" << endl;
        for (const auto &boutiqueJson : boutiquesJson) {
            int id = boutiqueJson["boutiqueId"];
            string name = boutiqueJson["name"];
            string location = boutiqueJson["location"];
            cout << "ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Location: " << location << endl;
            cout << endl;
        }
    }
}

void BoutiqueManager::saveToFile(const string& filename) const {
    json json;
    for (const auto& boutique : boutiques) {
        json.push_back({
                               {"boutiqueId", boutique.getId()},
                               {"name", boutique.getName()},
                               {"location", boutique.getLocation()}
                       });
    }
    ofstream file(filename);
    if (file.is_open()) {
        file << json.dump(4); // Dump JSON to file with indentation
        file.close();
    } else {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}

void BoutiqueManager::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        json json;
        file >> json;
        file.close();

        boutiques.clear(); // Clear existing boutiques
        for (const auto& boutiqueJson : json) {
            int id = boutiqueJson["boutiqueId"];
            string name = boutiqueJson["name"];
            string location = boutiqueJson["location"];
            boutiques.push_back(Boutique(id, name, location));
        }
    } else {
        cerr << "Error: Unable to open file for reading." <<endl;
    }
}

