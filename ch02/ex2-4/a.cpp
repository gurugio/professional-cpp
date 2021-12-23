#include <iostream>
#include <vector>
#include <string.h>
#include <fmt/core.h>

using namespace std;
using namespace fmt;

int main()
{
    string s;
    vector<string> store;
    array<string, 3> formats{"{:12g}", "{:12.2}", "{:12e}"};
    int i = 0;

    do
    {
        cout << "input two strings: ";
        getline(cin, s);
        store.push_back(s);
        cout << "input: " << s << endl;
    } while (s != "0");

    for (auto e : store)
    {
        cout << e << endl;
    }

    cout << "|";
    for (auto str : store)
    {
        if (str == "0")
        {
            break;
        }
        double d{stod(str)};
        cout << format(formats[i++ % 3], d);
        cout << "|";
        if ((i % 3) == 0)
        {
            cout << endl;
            cout << "|";
        }
    }
    cout << endl;
}