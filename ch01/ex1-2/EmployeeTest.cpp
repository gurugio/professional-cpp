#include <iostream>
#include "Employee.h"

using namespace std;
using namespace HR;

int main()
{
    cout << "Testing the Employee class." << endl;
    Employee emp{
        .m_firstName = "Jane",
        .m_lastName = "Doe",
    };
    emp.setFirstName("John");
    emp.setLastName("Doe");
    emp.setEmployeeNumber(71);
    emp.setSalary(50'000);
    emp.promote();
    emp.promote(50);
    emp.hire();
    emp.setTitle(EmployeeTitle::SeniorEngineer);
    emp.display();
}