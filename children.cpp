#include <iostream>
#include "nlohmann/json.hpp"
#include"product.h"
#include "children.h"
using namespace std;
#include<string>
#include <vector>
using json = nlohmann::json;

KidsProduct::KidsProduct(const string& name, double price, const string& type, Inventory* inventory)
        : Product(name, price, type, inventory) {}

void KidsProduct::addShirt(const Product& p) {
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
    // Add new shirt to JSON data
    json shirtJson;
    shirtJson["name"] = getName();
    shirtJson["type"] = "shirt";
    shirtJson["price"] = getPrice();
    existingData.push_back(shirtJson);

    // Write updated JSON data back to file
    ofstream outFile("product.json");
    if (outFile.is_open()) {
        outFile << setw(4) << existingData << endl; // Pretty print with indentation
        cout << "Shirt added successfully." << endl;
        outFile.close();
    } else {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}

void KidsProduct::addPant(const Product& p) {
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
    // Add new shirt to JSON data
    json shirtJson;
    shirtJson["name"] = getName();
    shirtJson["type"] = "pant";
    shirtJson["price"] = getPrice();
    existingData.push_back(shirtJson);

    // Write updated JSON data back to file
    ofstream outFile("product.json");
    if (outFile.is_open()) {
        outFile << setw(4) << existingData << endl;
        cout << "pants added successfully." << endl;
        outFile.close();
    } else {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}

void KidsProduct::addSuit(const Product& p) {
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
    // Add new shirt to JSON data
    json shirtJson;
    shirtJson["name"] = getName();
    shirtJson["type"] = "suit";
    shirtJson["price"] = getPrice();
    existingData.push_back(shirtJson);

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

void KidsProduct::removeShirt(const Product& p) {
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
void KidsProduct::removePant(const Product& p) {
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
void KidsProduct::removeSuit(const Product& p) {
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
void KidsProduct::updateShirt(const Product& p) {
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
void KidsProduct::updatePant(const Product& p) {
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
void KidsProduct::updateSuit(const Product& p) {
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

void KidsProduct::displayFromJsonFile(const string &filename) {
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