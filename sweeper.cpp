//
// Created by Hoor Ul Ain on 5/8/2024.
//

#include "sweeper.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "nlohmann/json.hpp"
using namespace std;
using json = nlohmann::json;


void Sweeper:: addEmployee(const Employee& e1) {
    ifstream file("sweeper.json");
    json existingData;
    if (file.is_open())
    {
        file >> existingData;
        file.close();
    }

    // If the file doesn't exist or is empty, initialize existingData as an array
    if (!existingData.is_array()) {
        existingData = json::array();
    }

    // Check if the employee already exists in the array
    for (const auto& employee : existingData) {
        if (employee["id"] == e1.id) {
            cout << "Employee with ID " << e1.id << " already exists. Not adding again." << endl;
            return;
        }
    }

    // Create a new JSON object for the new employee
    json newEmployeeJson = {
            {"id", e1.id},
            {"name", e1.name},
            {"section", e1.section},
            {"age", e1.age}
    };

    existingData.push_back(newEmployeeJson);

    // Open the same file for writing
    ofstream outFile("sweeper.json",ios::out);
    if (!outFile.is_open()) {
        cerr << "Error: Unable to open file for writing." <<endl;
        return;
    }

    // Write the updated employees array to the file
    outFile << setw(4) << existingData; // The '4' is for pretty printing with indentation
    outFile.close();

    cout << "Employee with ID " << e1.id << " added successfully." << endl;
}

void Sweeper::removeEmployeeFromJSONArray(const string& employeeNameToRemove) {
    ifstream file("sweeper.json");
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
        cerr << "Error: Employee file is empty or doesn't exist." << endl;
        return;
    }

    // Iterate through the existing data and remove the employee with the specified name
    for (auto it = existingData.begin(); it != existingData.end(); ++it) {
        if ((*it)["name"] == employeeNameToRemove) {
            existingData.erase(it); // Remove the employee from the array
            cout << "Employee \"" << employeeNameToRemove << "\" removed successfully." << endl;
            break;
        }
    }

    // Write the updated array to file
    ofstream outFile("sweeper.json");
    if (outFile.is_open()) {
        outFile << existingData.dump(4); // Dump JSON to file with indentation
        outFile.close();
        cout << "Employee file updated successfully." << endl;
    } else {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}

void Sweeper::updateEmployeeInJSONArray(const Employee& updatedEmployee) {
    ifstream file("sweeper.json");
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
        cerr << "Error: Employee file is empty or doesn't exist." << endl;
        return;
    }

    bool employeeUpdated = false;

    // Iterate through the existing data and update the employee with the specified name
    for (auto &employee: existingData) {
        if (employee["name"] == updatedEmployee.name) {
            employee["id"] = updatedEmployee.id;
            employee["section"] = updatedEmployee.section;
            employee["age"] = updatedEmployee.age;
            employeeUpdated = true;
            cout << "Employee \"" << updatedEmployee.name << "\" updated successfully." << endl;
            break;
        }
    }

    if (!employeeUpdated) {
        cout << "Employee \"" << updatedEmployee.name << "\" not found. Unable to update." << endl;
        return;
    }

    // Write the updated array to file
    ofstream outFile("sweeper.json");
    if (outFile.is_open()) {
        outFile << existingData.dump(4); // Dump JSON to file with indentation
        outFile.close();
        cout << "Employee file updated successfully." << endl;
    } else {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}