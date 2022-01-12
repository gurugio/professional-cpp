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
        cout << "aaa < bbb\n";
    }

    if (bbb > aaa)
    {
        cout << "bbb > aaa\n";
    }

    if (bbb >= aaa)
    {
        cout << "aaa >= bbb\n";
    }

    if (bbb <= ccc)
    {
        cout << "bbb <= ccc\n";
    }

    if (bbb == ccc)
    {
        cout << "bbb == ccc\n";
    }

    if (aaa != bbb)
    {
        cout << "aaa != bbb\n";
    }
}