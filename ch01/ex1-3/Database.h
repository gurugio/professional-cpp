#include <string>
//#include <vector>
#include <array>
#include "Employee.h"

namespace HR
{
    const int FirstEmployeeNumber{1'000};

    class Database
    {
    public:
        Employee &addEmployee(const std::string &firstName,
                              const std::string &lastName,
                              const std::string &title);
        Employee &getEmployee(int employeeNumber);
        Employee &getEmployee(const std::string &firstName,
                              const std::string &lastName);
        void displayAll() const;
        void displayCurrent() const;
        void displayFormer() const;

    private:
        // ex 1-3) use std::array
        // std::vector<Employee> m_employees;
        std::array<Employee, 5> m_employees;
        int m_arrIndex{0};
        int m_nextEmployeeNumber{FirstEmployeeNumber};
    };
};
