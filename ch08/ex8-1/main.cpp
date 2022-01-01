#include <iostream>
#include <string>
#include <memory>
#include "person.h"

using namespace std;

int main()
{
    Person aaa{"aaa", "bbb"};
    cout << aaa.getFirstName() << "-" << aaa.getLastName() << '\n';
    aaa.setFirstName("ccc");
    aaa.setLastName("ddd");
    cout << aaa.getFirstName() << "-" << aaa.getLastName() << '\n';

    unique_ptr<Person> bbb{make_unique<Person>("aaa", "bbb")};
    cout << bbb->getFirstName() << "-" << bbb->getLastName() << '\n';
    bbb->setFirstName("ccc");
    bbb->setLastName("ddd");
    cout << bbb->getFirstName() << "-" << bbb->getLastName() << '\n';
}