#include <iostream>
#include "Database.h"

using namespace std;
using namespace HR;

int main()
{
     Database myDB;
     Employee &emp1{myDB.addEmployee("Greg", "Wallis", "Engineer")};
     emp1.fire();

     Employee &emp2{myDB.addEmployee("Marc", "White", "SeniorEngineer")};
     emp2.setSalary(100'000);

     Employee &emp3{myDB.addEmployee("John", "Doe", "Manager")};
     emp3.setSalary(10'000);
     emp3.promote();

     cout << "all employees: " << endl
          << endl;
     myDB.displayAll();

     cout << endl
          << "current employees: " << endl
          << endl;
     myDB.displayCurrent();

     cout << endl
          << "former employees:" << endl
          << endl;
     myDB.displayFormer();
}