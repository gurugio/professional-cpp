#include <iostream>
#include <string>
#include <string_view>

using namespace std;

string str_replace(string_view haystack, string_view needle, string_view repl)
{
    auto start = 0;
    auto end = 0;
    string ret;

    while (start < haystack.size())
    {
        end = haystack.find(needle, start);
        if (end == string::npos)
        {
            break;
        }
        // cout << "substr:" << haystack.substr(start, (end == start) ? 0 : (end - start)) << endl;
        ret.append(haystack.substr(start, (end == start) ? 0 : (end - start)));
        ret.append(repl);
        start = end + needle.size();
    }
    ret.append(haystack.substr(start, haystack.size() - start));
    return ret;
}

int main()
{
    string haystack{"aaabbbaaacccaaadddaaaa"};
    string needle{"aa"};
    string replacement{"XX"};
    string rep{str_replace(haystack, needle, replacement)};
    cout << haystack << "->" << rep << endl;
}