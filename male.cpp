#include "male.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>
using namespace std;

using json = nlohmann::json;

MaleProduct::MaleProduct(){}

MaleProduct::MaleProduct(const std::string& name, double price, const string& type, Inventory* inventory) :
        Product(name, price, type, inventory) {}

void MaleProduct::addSuit(const Product& p) {
    // Open the file for reading
    ifstream file("product.json");
    if (!file.is_open()) {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }

    // Read existing JSON data from the file
    json existingData;
    file >> existingData;
    file.close();

    // If the file doesn't exist or is empty, initialize existingData as an array
    if (!existingData.is_array()) {
        existingData = json::array();
    }

    // Validate input data (e.g., ensure required fields are provided)

    // Create a new JSON object for the new suit
    json newSuitJson = {
            {"name", p.getName()},
            {"section", p.getType()},
            {"price", p.getPrice()} // Assuming price is a member variable in Product class
    };

    // Add the new suit to the existing JSON data
    existingData.push_back(newSuitJson);

    // Open the same file for writing
    ofstream outFile("product.json", ios::out);
    if (!outFile.is_open()) {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }

    // Write the updated suits array to the file with indentation for readability
    outFile << setw(4) << existingData;
    outFile.close();

    cout << "Suit added successfully." << endl;
}

void MaleProduct::addCoat(const Product& p) {
    ifstream file("product.json");
    json existingData;
    if (file.is_open()) {
        file >> existingData;
        file.close();
    }

    // If the file doesn't exist or is empty, initialize existingData as an array
    if (!existingData.is_array()) {
        existingData = json::array();
    }

    // Create a new JSON object for the new coat
    json newCoatJson = {
            {"name", p.getName()},
            {"section", p.getType()}, // Assuming getType() returns the coat section
            {"price", p.getPrice()}  // Assuming getPrice() returns the coat price

    };

    existingData.push_back(newCoatJson);

    // Open the same file for writing
    ofstream outFile("product.json", ios::out);
    if (!outFile.is_open()) {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }
    // Write the updated coats array to the file
    outFile << setw(4) << existingData; // The '4' is for pretty printing with indentation
    outFile.close();
    cout << "Coat added successfully." << endl;
}


void MaleProduct::removeSuit(const Product& p) {
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
    if (!productRemoved) {
        cerr << "Error: Product with name \"" << getName() << "\" not found. Unable to remove." << endl;
        return;
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


void MaleProduct::removeCoat(const Product& p) {
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
void MaleProduct::updateSuit(const Product& p) {
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
    ofstream outFile("maleProduct.json");
    if (outFile.is_open()) {
        outFile << setw(4) << existingData.dump(); // Dump JSON to file with indentation
        outFile.close();
        cout << "Product file updated successfully." << endl;
    } else {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}

void MaleProduct::updateCoat(const Product& p) {
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

void MaleProduct::displayFromJsonFile(const string &filename) {
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
