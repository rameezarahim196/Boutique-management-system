//
// Created by Hoor Ul Ain on 5/8/2024.
//

#ifndef SPRING2024_CE101_OOP_PROJECT_GROUP_AAA_CUSTOMER_H
#define SPRING2024_CE101_OOP_PROJECT_GROUP_AAA_CUSTOMER_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "nlohmann/json.hpp"
using namespace std;
using json = nlohmann::json;

class Customer{
private:
    int customer_id;
    string name;
    int age;
    string gender;
public:
    Customer();
    Customer(int customer_id,string name,int age,string gender);
//    friend void operator+=(vector<Customer>& customers, const Customer& customer);
//    friend void operator-=(vector<Customer>& customers, int customer_id);
    friend void addCustomer(const Customer &c1);
    void removeCustomerFromJSONArray(const string& customerNameToRemove);
   void  updateCustomerInJSONArray(const Customer& updatedCustomer);
};

#endif //SPRING2024_CE101_OOP_PROJECT_GROUP_AAA_CUSTOMER_H
