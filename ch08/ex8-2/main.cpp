#include <iostream>
#include <string>
#include <memory>
#include "person.h"

#include <vector>

using namespace std;

int main()
{
    Person aaa[3]{{"111", "111"}, {"222", "222"}, {"333", "333"}};
    cout << aaa[0].getFirstName() << "-" << aaa[0].getLastName() << '\n';
    Person ddd[3];                                                        // compiled with default consructor
    cout << ddd[0].getFirstName() << "-" << ddd[0].getLastName() << '\n'; // empty

    unique_ptr<Person> bbb{make_unique<Person>("aaa", "bbb")};
    cout << bbb->getFirstName() << "-" << bbb->getLastName() << '\n';

    vector<unique_ptr<Person>> table;
    table.push_back(move(bbb));
    cout << "before reset\n";
    bbb.reset(); // do nothing because it's already moved out
    cout << "after reset\n";

    cout << table[0]->getFirstName() << '\n';
}