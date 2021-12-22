#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cout << "input two strings: ";
    getline(cin, s);
    cout << "input: " << s << endl;

    auto del = s.find(' ', 0);
    string first = s.substr(0, del);
    cout << "first:[" << first << "]\n";
    string second = s.substr(del + 1, s.size());
    cout << "second:[" << second << "]\n";

    auto result{first <=> second};
    if (is_gt(result))
    {
        cout << first << ">" << second << endl;
    }
    else if (is_lt(result))
    {
        cout << second << ">" << first << endl;
    }
    else
    {
        cout << first << "==" << second << endl;
    }
}