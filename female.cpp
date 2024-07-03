#include "female.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>

using json = nlohmann::json;


FemaleProduct::FemaleProduct(const string& name, double price, const string& type,Inventory* inventory)
        : Product(name, price,type, inventory) {}

void FemaleProduct::addSuit(const Product& p) {
    ifstream file("product.json");
    json existingData;
    if (file.is_open()) {
        file >> existingData;
        file.close();
    } else {
        existingData = json::array();
    }

    // Check if product with the same name already exists
    for (const auto& product : existingData) {
        if (product["name"] == getName()) {
            cerr << "Error: Product with name \"" << getName() << "\" already exists." << endl;
            return;
        }
    }

    // Add new suit to JSON data
    json suitJson;
    suitJson["name"] = getName();
    suitJson["type"] = "suit";
    suitJson["price"] = getPrice();
    existingData.push_back(suitJson);

    // Write updated JSON data back to file
    ofstream outFile("product.json");
    if (outFile.is_open()) {
        outFile << setw(4) << existingData << endl; // Pretty print with indentation
        cout << "Suit added successfully." << endl;
        outFile.close();
    } else {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}

void FemaleProduct::addScarf(const Product& p){
    ifstream file("product.json");
    json existingData;
    if (file.is_open()) {
        file >> existingData;
        file.close();
    } else {
        existingData = json::array();
    }

    // Check if product with the same name already exists
    for (const auto& product : existingData) {
        if (product["name"] == getName()) {
            cerr << "Error: Product with name \"" << getName() << "\" already exists." << endl;
            return;
        }
    }

    // Add new scarf to JSON data
    json scarfJson;
    scarfJson["name"] = getName();
    scarfJson["type"] = "scarf";
    scarfJson["price"] = getPrice();
    existingData.push_back(scarfJson);

    // Write updated JSON data back to file
    ofstream outFile("product.json");
    if (outFile.is_open()) {
        outFile << setw(4) << existingData << endl; // Pretty print with indentation
        cout << "Scarf added successfully." << endl;
        outFile.close();
    } else {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}

void FemaleProduct::removeSuit(const Product& p) {
    ifstream file("product.json");
    json existingData;
    if (file.is_open()) {
        file >> existingData;
        file.close();
    } else {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }

    // Check if the file is empty or doesn't exist
    if (!existingData.is_array() || existingData.empty()) {
        cerr << "Error: Product file is empty or doesn't exist." << endl;
        return;
    }

    // Iterate through the existing data and remove the product with the specified name
    bool productRemoved = false;
    for (auto it = existingData.begin(); it != existingData.end(); ++it) {
        if ((*it)["name"] == p.getName()) {
            existingData.erase(it);
            productRemoved = true;
            cout << "Product \"" << p.getName() << "\" removed successfully." << endl;
            break;
        }
    }

    // Write the updated array to file
    ofstream outFile("product.json");
    if (outFile.is_open()) {
        outFile << existingData.dump(4); // Dump JSON to file with indentation
        outFile.close();
        cout << "Product file updated successfully." << endl;
    } else {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}


void FemaleProduct::removeScarf(const Product& p) {
    ifstream file("product.json");
    json existingData;
    if (file.is_open()) {
        file >> existingData;
        file.close();
    } else {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }

    // Check if the file is empty or doesn't exist
    if (!existingData.is_array() || existingData.empty()) {
        cerr << "Error: Product file is empty or doesn't exist." << endl;
        return;
    }

    // Iterate through the existing data and remove the product with the specified name
    bool productRemoved = false;
    for (auto it = existingData.begin(); it != existingData.end(); ++it) {
        if ((*it)["name"] == p.getName()) {
            existingData.erase(it);
            productRemoved = true;
            cout << "Product \"" << p.getName() << "\" removed successfully." << endl;
            break;
        }
    }
    // Write the updated array to file
    ofstream outFile("product.json");
    if (outFile.is_open()) {
        outFile << existingData.dump(4); // Dump JSON to file with indentation
        outFile.close();
        cout << "Product file updated successfully." << endl;
    } else {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}

void FemaleProduct::updateSuit(const Product& p) {
    ifstream file("product.json");
    json existingData;
    if (file.is_open()) {
        file >> existingData;
        file.close();
    } else {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }

    // Check if the file is empty or doesn't exist
    if (!existingData.is_array() || existingData.empty()) {
        cerr << "Error: Product file is empty or doesn't exist." << endl;
        return;
    }

    bool suitUpdated = false;

    // Iterate through the existing data and update the suit with the specified name
    for (auto &suit : existingData) {
        if (suit["name"] == p.getName()) {
            suit["section"] = p.getType();
            suit["price"] = p.getPrice();
            suitUpdated = true;
            cout << "Suit \"" << p.getName() << "\" updated successfully." << endl;
            break;
        }
    }

    if (!suitUpdated) {
        cout << "Suit \"" << p.getName() << "\" not found. Unable to update." << endl;
        return;
    }
    // Write the updated array to file
    ofstream outFile("product.json");
    if (outFile.is_open()) {
        outFile << setw(4) << existingData.dump(); // Dump JSON to file with indentation
        outFile.close();
        cout << "Product file updated successfully." << endl;
    } else {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}

void FemaleProduct::updateScarf(const Product& p) {
    ifstream file("product.json");
    json existingData;
    if (file.is_open()) {
        file >> existingData;
        file.close();
    } else {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }

    // Check if the file is empty or doesn't exist
    if (!existingData.is_array() || existingData.empty()) {
        cerr << "Error: Product file is empty or doesn't exist." << endl;
        return;
    }

    bool coatUpdated = false;
    // Iterate through the existing data and update the coat with the specified name
    for (auto &coat : existingData) {
        if (coat["name"] == p.getName()) {
            coat["section"] = p.getType();
            coat["price"] = p.getPrice();
            coatUpdated = true;
            cout << "Coat \"" << p.getName() << "\" updated successfully." << endl;
            break;
        }
    }

    if (!coatUpdated) {
        cout << "Coat \"" << p.getName() << "\" not found. Unable to update." << endl;
        return;
    }
    // Write the updated array to file
    ofstream outFile("product.json");
    if (outFile.is_open()) {
        outFile << setw(4) << existingData.dump(); // Dump JSON to file with indentation
        outFile.close();
        cout << "Product file updated successfully." << endl;
    } else {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}

void FemaleProduct::displayFromJsonFile(const string &filename) {
    ifstream file(filename);
    json jsonData;

// Attempt to open and read the JSON file
    if (file.is_open()) {
        file >> jsonData;
        file.close();
    } else {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }
// Check if the file is empty or doesn't exist
    if (!jsonData.is_array() || jsonData.empty()) {
        cerr << "Error: File is empty or doesn't contain valid JSON data." << endl;
        return;
    }

// Display each product in the JSON array
    for (const auto &product: jsonData) {
        cout << "Name: " << product["name"] << endl;
        cout << "Price: " << product["price"] << endl;
        cout << "type: " << product["type"] << endl;
        cout << "-----------------------------------" << endl;
    }
}
