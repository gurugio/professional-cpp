// build: g++ -std=c++2a a.cpp -lfmt

#include <iostream>
#include <fmt/core.h>
#include "Employee.h"

using namespace std;
using namespace fmt;

namespace HR
{
    /* aggregate type does not have a user-declared constructor.
    Employee::Employee(const string &firstName, const string &lastName)
        : m_firstName{firstName}, m_lastName{lastName}
    {
    }
    */

    void Employee::promote(int raiseAmount)
    {
        setSalary(getSalary() + raiseAmount);
    }

    void Employee::demote(int demeritAmount)
    {
        setSalary(getSalary() - demeritAmount);
    }

    void Employee::hire() { m_hired = true; }
    void Employee::fire() { m_hired = false; }

    void Employee::display() const
    {
        cout << format("Employee: {}, {}", getLastName(), getFirstName()) << endl;
        cout << "------------------------------" << endl;
        cout << (isHired() ? "Current Employee" : "Former Employee") << endl;
        cout << format("Employee Number: {}", getEmployeeNumber()) << endl;
        cout << format("Salary: ${}", getSalary()) << endl;
        cout << format("Title: {}", getTitleDisplay()) << endl;
        cout << endl;
    }

    void Employee::setFirstName(const string &firstName)
    {
        m_firstName = firstName;
    }

    const string &Employee::getFirstName() const
    {
        return m_firstName;
    }

    void Employee::setLastName(const std::string &lastName)
    {
        m_lastName = lastName;
    }
    const std::string &Employee::getLastName() const
    {
        return m_lastName;
    }

    void Employee::setEmployeeNumber(int employeeNumber)
    {
        m_employeeNumber = employeeNumber;
    }
    int Employee::getEmployeeNumber() const
    {
        return m_employeeNumber;
    }

    void Employee::setSalary(int newSalary)
    {
        m_salary = newSalary;
    }
    int Employee::getSalary() const
    {
        return m_salary;
    }

    void Employee::setTitle(EmployeeTitle t)
    {
        m_title = t;
    }

    void Employee::setTitleStr(const string &t)
    {
        if (t == "Engineer")
        {
            setTitle(EmployeeTitle::Engineer);
        }
        else if (t == "SeniorEngineer")
        {
            setTitle(EmployeeTitle::SeniorEngineer);
        }
        else if (t == "Manager")
        {
            setTitle(EmployeeTitle::Manager);
        }
        else
        {
            setTitle(EmployeeTitle::Unknown);
        }
    }

    EmployeeTitle Employee::getTitle() const
    {
        return m_title;
    }

    const std::string Employee::getTitleDisplay() const
    {
        switch (getTitle())
        {
        case EmployeeTitle::SeniorEngineer:
            return "Senior Engineer";
        case EmployeeTitle::Engineer:
            return "Engineer";
        case EmployeeTitle::Manager:
            return "Manager";
        default:
            return "Unknown";
        }
    }

    bool Employee::isHired() const
    {
        return m_hired;
    }
}