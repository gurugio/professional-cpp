#include <iostream>
#include <string>
#include <memory>
#include "person.h"

#include <vector>

using namespace std;

int main()
{
    Person aaa; // default constructor
    aaa.setFirstName("Michael");
    aaa.setLastName("Jacson");
    cout << aaa.getFirstName() << "-" << aaa.getLastName() << '\n';
    aaa.setInitial("MJ");
    cout << aaa.getInitial() << '\n';
    // copy constructor
    Person bbb{"bbb", "ccc"};
    cout << bbb.getFirstName() << "-" << bbb.getLastName() << '\n';
    cout << bbb.getInitial() << '\n';

    Person ccc{"AAA", "BBB", "AB"};
    cout << ccc.getFirstName() << "-" << ccc.getLastName() << '\n';
    cout << ccc.getInitial() << '\n';
}