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

    // copy constructor
    Person bbb{aaa};
    bbb.setFirstName("b");
    bbb.setLastName("bbb");
    // assignment
    Person ccc;
    ccc = bbb;
    ccc.setFirstName("c");
}