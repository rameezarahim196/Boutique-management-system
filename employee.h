//
// Created by Hoor Ul Ain on 5/8/2024.
//
#ifndef SPRING2024_CE101_OOP_PROJECT_GROUP_AAA_EMPLOYEE_H
#define SPRING2024_CE101_OOP_PROJECT_GROUP_AAA_EMPLOYEE_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "nlohmann/json.hpp"
using namespace std;
using json = nlohmann::json;
#include"boutique.h"

class Employee{

public:
    int id;
    string name;
    string section;
    int age;
    Boutique b;
    Employee();
    Employee(int id,string name,string section,int age);
    int getId() const;
    void setId(int id);
    string getName() const;
    void setName(const string& name);
    string getSection() const;
    void setSection(const string& section);
    int getAge() const;
    void setAge(int age);
    virtual void addEmployee(const Employee& e1);
    virtual void removeEmployeeFromJSONArray(const string& employeeNameToRemove);
    virtual void updateEmployeeInJSONArray(const Employee& updatedEmployee);
    friend ostream& operator<<(ostream& os, const Employee& emp) ;
    friend istream& operator>>(istream& is, Employee& emp);
};
#endif //SPRING2024_CE101_OOP_PROJECT_GROUP_AAA_EMPLOYEE_H
