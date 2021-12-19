#include "Database.h"
#include <stdexcept>

using namespace std;

namespace HR
{
    Employee &Database::addEmployee(const string &firstName,
                                    const string &lastName,
                                    const string &title)
    {
        Employee theEmployee{
            .m_firstName = firstName,
            .m_lastName = lastName,
        };
        theEmployee.setEmployeeNumber(m_nextEmployeeNumber++);
        theEmployee.hire();
        theEmployee.setTitleStr(title);
        // m_employees.push_back(theEmployee);
        if (m_arrIndex < m_employees.max_size())
        {
            m_employees[m_arrIndex++] = theEmployee;
        }
        else
        {
            // re-alloc or throw error
            throw logic_error{"overflow"};
        }
        // return m_employees.back();
        return m_employees[m_arrIndex - 1];
    }

    Employee &Database::getEmployee(int employeeNumber)
    {
        for (auto &employee : m_employees)
        {
            if (employee.getEmployeeNumber() == employeeNumber)
            {
                return employee;
            }
        }
        throw logic_error{"No employee found."};
    }

    void Database::displayAll() const
    {
        /*for (const auto &employee : m_employees)
        {
            employee.display();
        }*/
        for (auto i = 0; i < m_arrIndex; i++)
        {
            m_employees[i].display();
        }
    }

    void Database::displayCurrent() const
    {
        for (auto i = 0; i < m_arrIndex; i++)
        {
            if (m_employees[i].isHired())
            {
                m_employees[i].display();
            }
        }
    }

    void Database::displayFormer() const
    {
        for (auto i = 0; i < m_arrIndex; i++)
        {
            if (!m_employees[i].isHired())
            {
                m_employees[i].display();
            }
        }
    }
};