#include <iostream>
#include <string>
#include <memory>
#include "person.h"

#include <vector>

using namespace std;

int main()
{
    Person aaa; // default constructor
    string fname{"fff"};
    string lname{"lll"};
    aaa.setFirstName(fname);
    aaa.setLastName(lname);
    cout << "pass copy-of-string\n";
    cout << "new person:" << aaa.getFirstName() << "-" << aaa.getLastName() << '\n';
    cout << "source strings are not removed :" << fname << lname << '\n'; // source string is ok

    Person bbb{move(aaa)};
    cout << "move constructor\n";
    cout << "moved-out:" << aaa.getFirstName() << "-" << aaa.getLastName() << '\n';
    cout << "new person:" << bbb.getFirstName() << "-" << bbb.getLastName() << '\n';

    Person ccc;
    ccc.setFirstName("cfcfcf");
    ccc.setLastName("clclcl");
    ccc = move(bbb);
    cout << "move assignment\n";
    cout << "moved-out:" << bbb.getFirstName() << "-" << bbb.getLastName() << '\n';
    cout << "new person:" << ccc.getFirstName() << "-" << ccc.getLastName() << '\n';
}