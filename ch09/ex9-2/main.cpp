#include <iostream>
#include <string>
#include <memory>
#include "person.h"

#include <vector>

using namespace std;

int main()
{
    Person aaa; // default constructor
    aaa.setFirstName("aaa");
    aaa.setLastName("aaa");
    // copy constructor
    Person bbb{"aaa", "bbb"};
    Person ccc{"aaa", "bbb"};

    if (aaa < bbb)
    {
        cout << "aaa is less than bbb\n";
    }

    if (bbb >= aaa)
    {
        cout << "aaa is less or equal to bbb\n";
    }

    if (bbb <= ccc)
    {
        cout << "bbb is less or equal to ccc\n";
    }

    if (bbb == ccc)
    {
        cout << "bbb is equal to ccc\n";
    }
}