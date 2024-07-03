//
// Created by Hoor Ul Ain on 5/8/2024.
//

#ifndef SPRING2024_CE101_OOP_PROJECT_GROUP_AAA_SALESMAN_H
#define SPRING2024_CE101_OOP_PROJECT_GROUP_AAA_SALESMAN_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "nlohmann/json.hpp"
using namespace std;
#include"employee.h"
using json = nlohmann::json;

class Salesman:public Employee{
public:
    Salesman(){}
    Salesman(int id, const std::string& name, const std::string& section, int age)
            : Employee(id, name, section, age){}
    void addEmployee(const Employee& e1) override;
    void removeEmployeeFromJSONArray(const std::string& employeeNameToRemove) override;
    void updateEmployeeInJSONArray(const Employee& updatedEmployee) override;
};
#endif //SPRING2024_CE101_OOP_PROJECT_GROUP_AAA_SALESMAN_H

