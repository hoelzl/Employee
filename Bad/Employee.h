// Created by Matthias Hölzl on 2019-05-28.
//

#ifndef EMPLOYEE_EMPLOYEE_H
#define EMPLOYEE_EMPLOYEE_H

#include <ctime>
#include <ostream>

class Name
{
public:
    explicit Name(int id);

private:
    friend std::ostream& operator<<(std::ostream& Stream, const Name& Name);
    friend class Employee;
    std::string first_name_;
    std::string last_name_;
};

std::ostream& operator<<(std::ostream& stream, const Name& name);

class Employee
{
public:
    explicit Employee(int id);

private:
    friend std::ostream& operator<<(std::ostream& stream, const Employee& employee);
    int id_;
    Name name_;
    std::tm birthday_;
    bool IsBirthday() const;
    double GetSalary() const;
};

std::ostream& operator<<(std::ostream& stream, const Employee& employee);

#endif // EMPLOYEE_EMPLOYEE_H
