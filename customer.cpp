//
// Created by Hoor Ul Ain on 5/8/2024.
//

#include "customer.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "nlohmann/json.hpp"
using namespace std;
using json = nlohmann::json;
Customer::Customer()
{
    customer_id=0;
    name="";
    age=0;
    gender="";
}
Customer::Customer(int customer_id,string name,int age,string gender)
{
    this->customer_id=customer_id;
    this->name=name;
    this->gender=gender;
    this->age=age;
}
//void operator+=(vector<Customer>& customers, const Customer& customer) {
//    customers.push_back(customer);
//}
//
//// Overloading the -= operator to remove a customer by their ID from the vector
//void operator-=(vector<Customer>& customers, int customer_id) {
//    for (auto it = customers.begin(); it != customers.end(); ++it) {
//        if (it->customer_id == customer_id) {
//            customers.erase(it);
//            break; // Once the customer is removed, exit the loop
//        }
//    }
//}
//
//void addCustomer(const Customer &p1){ // function for add person
//
//    json pp1 ={{"name",p1.name},{"age",p1.age},{"salaries",p1.salaries}};
//    fstream file("person.json",ios::out);
//    if(file.is_open())
//    {
//        file<<pp1;       //write in file
//        file.close();           //close the file
//        cout<<"Person was added successfully"<<endl;
//    }
//    else{
//        cout<<"Error opening file"<<endl;
//    }
//}



void addCustomer(const Customer &newCustomer) { // function to add customer
    ifstream file("customers.json");
    json existingData;
    if (file.is_open()) {
        file >> existingData;
        file.close();
    }

// If the file doesn't exist or is empty, initialize existingData as an array
    if (!existingData.is_array()) {
        existingData = json::array();
    }

    for (const auto &customer : existingData) {
        if (customer["customer_id"] == newCustomer.customer_id) {
            cout << "Customer with ID " << newCustomer.customer_id << " already exists. Not adding again." << endl;
            return;
        }
    }

// Create a new JSON object for the new customer
    json newCustomerJson = {
            {"customer_id", newCustomer.customer_id},
            {"name", newCustomer.name},
            {"age", newCustomer.age},
            {"gender", newCustomer.gender}
    };

    existingData.push_back(newCustomerJson);

// Open the same file for writing
    ofstream outFile("customers.json", ios::out);
    if (!outFile.is_open()) {
        cout << "Error: Unable to open file for writing." << endl;
        return;
    }

// Write the updated customers array to the file
    outFile << setw(4) << existingData; // The '4' is for pretty printing with indentation
    outFile.close();

    cout << "Customer with ID " << newCustomer.customer_id << " added successfully." << endl;
}





void Customer::removeCustomerFromJSONArray(const string& customerNameToRemove) {
    // Read the existing data from the JSON file
    ifstream file("customers.json");
    json existingData;
    if (file.is_open()) {
        file >> existingData;
        file.close();
    } else {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }

    // Iterate through the existing data and remove the customer with the specified name
    for (auto it = existingData.begin(); it != existingData.end(); ++it) {
        if ((*it)["name"] == customerNameToRemove) {
            existingData.erase(it); // Remove the customer from the array
            cout << "Customer \"" << customerNameToRemove << "\" removed successfully." << endl;
            break;
        }
    }

    // Write the updated array back to the JSON file
    ofstream outFile("customers.json");
    if (outFile.is_open()) {
        outFile << existingData.dump(4); // Dump JSON to file with indentation
        outFile.close();
        cout << "Customer file updated successfully." << endl;
    } else {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}

void Customer::updateCustomerInJSONArray(const Customer& updatedCustomer) {
    // Read the existing data from the JSON file
    ifstream file("customers.json");
    json existingData;
    if (file.is_open()) {
        file >> existingData;
        file.close();
    } else {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }

    // Iterate through the existing data and update the customer with the specified ID
    bool customerUpdated = false;
    for (auto& customer : existingData) {
        if (customer["customerId"] == updatedCustomer.customer_id) {
            customer["name"] = updatedCustomer.name;
            customer["age"] = updatedCustomer.age;
            customer["gender"] = updatedCustomer.gender;
            customerUpdated = true;
            cout << "Customer with ID \"" << updatedCustomer.customer_id << "\" updated successfully." << endl;
            break;
        }
    }

    // Write the updated array back to the JSON file
    ofstream outFile("customers.json");
    if (outFile.is_open()) {
        outFile << existingData.dump(4); // Dump JSON to file with indentation
        outFile.close();
        cout << "Customer file updated successfully." << endl;
    } else {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}
