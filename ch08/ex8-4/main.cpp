#include <iostream>
#include <string>
#include <memory>
#include "person.h"

#include <vector>

using namespace std;

int main()
{
    Person aaa; // default constructor
    aaa.setFirstName("a");
    aaa.setLastName("aaa");
    cout << aaa.getFirstName() << "-" << aaa.getLastName() << '\n';
    cout << aaa.getInitial() << '\n'; // empty because it uses default constructor
    // copy constructor
    Person bbb{"bbb", "ccc"};
    cout << bbb.getInitial() << '\n';

    Person ccc{bbb};
    cout << ccc.getInitial() << '\n';
}