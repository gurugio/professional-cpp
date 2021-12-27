#include <iostream>
#include <memory>

using namespace std;

int main()
{
    const size_t numberOfElements{10};
    // int *values{new int[numberOfElements]};
    array<int, numberOfElements> values;

    for (int index{0}; index < numberOfElements; ++index)
    {
        values[index] = index;
    }

    // values[10] = 99;
    values[9] = 99;

    // for (int index{0}; index <= numberOfElements; ++index)
    for (int index{0}; index < numberOfElements; ++index)
    {
        cout << values[index] << " ";
    }
    cout << endl;
}