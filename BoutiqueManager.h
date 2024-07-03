
#ifndef PROJECT_BOUTIQUEMANAGER_H
#define PROJECT_BOUTIQUEMANAGER_H
#include <iostream>
#include<fstream>
#include <iomanip>
#include "boutique.h"
#include<vector>
#include "nlohmann/json.hpp"
using namespace std;
#include<string>
class BoutiqueManager {
private:
    static BoutiqueManager* instance; // Singleton instance
    vector<Boutique> boutiques;
    ofstream logFile;
    BoutiqueManager();     // Private constructor for Singleton

public:
    static BoutiqueManager* getInstance(); // Get Singleton instance
    void addBoutique(const Boutique& boutique);
    void removeBoutique(int id);
    void displayBoutiques() const;
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};
#endif //PROJECT_BOUTIQUEMANAGER_H
