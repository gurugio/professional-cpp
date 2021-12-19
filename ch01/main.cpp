#include <iostream>
#include <stdexcept>
#include <exception>
#include <fmt/core.h>
#include <string>
#include "Database.h"

using namespace std;
using namespace Records;

int displayMenu();
void doHire(Database &db);
void doFire(Database &db);
void doPromote(Database &db);

int main()
{
    Database employeeDB;
    bool done{false};
    while (!done)
    {
        int selection{displayMenu()};
        switch (selection)
        {
        case 0:
            done = true;
            break;
        case 1:
            doHire(employeeDB);
            break;
        case 2:
            doFire(employeeDB);
            break;
        case 3:
            doPromote(employeeDB);
            break;
        case 4:
            employeeDB.displayAll();
            break;
        case 5:
            employeeDB.displayCurrent();
            break;
        case 6:
            employeeDB.displayFormer();
            break;
        default:
            cerr << "Unknown command." << endl;
            break;
        }
    }
}

int displayMenu()
{
    int selection;
    cout << "1) hire" << endl;
    cout << "2) fire" << endl;
    cout << "3) promote" << endl;
    cout << "4) list all" << endl;
    cout << "5) list current" << endl;
    cout << "6) list former" << endl;
    cout << "0) quit" << endl;
    cout << "---> ";
    cin >> selection;
    return selection;
}

void doHire(Database &db)
{
    string firstName;
    string lastName;

    cout << "First name? ";
    cin >> firstName;

    cout << "Last name? ";
    cin >> lastName;

    auto &emplyee{db.addEmployee(firstName, lastName)};
    cout << fmt::format("Hired employee {} {} with employee number {}",
                        firstName, lastName, emplyee.getEmployeeNumber())
         << endl;
}

void doFire(Database &db)
{
    int employeeNumber;
    cout << "Employee number? ";
    cin >> employeeNumber;

    try
    {
        auto &emp{db.getEmployee(employeeNumber)};
        emp.fire();
        cout << fmt::format("employee {} terminated", employeeNumber)
             << endl;
    }
    catch (const std::logic_error &exception)
    {
        cerr << fmt::format("Unable to terminate employee: {}",
                            exception.what())
             << endl;
    }
}

void doPromote(Database &db)
{
    int employeeNumber;
    cout << "Employee number? ";
    cin >> employeeNumber;

    int raiseAmount;
    cout << "How much of a raise? ";
    cin >> raiseAmount;

    try
    {
        auto &emp{db.getEmployee(employeeNumber)};
        emp.promote(raiseAmount);
    }
    catch (const std::logic_error &exception)
    {
        cerr << fmt::format("Unable to promote employee: {}", exception.what())
             << endl;
    }
}