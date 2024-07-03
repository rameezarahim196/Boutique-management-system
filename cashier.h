//
// Created by Hoor Ul Ain on 5/8/2024.
//

#ifndef SPRING2024_CE101_OOP_PROJECT_GROUP_AAA_CASHIER_H
#define SPRING2024_CE101_OOP_PROJECT_GROUP_AAA_CASHIER_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "nlohmann/json.hpp"
using namespace std;
#include"employee.h"
using json = nlohmann::json;

class Cashier:public Employee{
public :
    Cashier();
    Cashier(int id, const string& name, const string& section, int age);
    void addEmployee(const Employee& e1) override;
    void removeEmployeeFromJSONArray(const string& employeeNameToRemove) override;
    void updateEmployeeInJSONArray(const Employee& updatedEmployee) override;

};
#endif //SPRING2024_CE101_OOP_PROJECT_GROUP_AAA_CASHIER_H
