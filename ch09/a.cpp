#include <iostream>
#include <string>
#include <fmt/core.h>

using namespace std;

class TextHolder
{
public:
    TextHolder(string text) : m_text{move(text)} {}
    const string &getText() const & { return m_text; }
    string &&getText() && { return move(m_text); }

    string m_text;
};

int main()
{
    TextHolder h{"world"};
    cout << move(h).getText() << endl;
    // string ttt = move(h).getText();
    cout << h.getText().size() << endl;
    cout << fmt::format("{:p}\n", h.m_text.c_str());

    // cout << ttt.size() << endl;
    // cout << fmt::format("{:p}\n", ttt.c_str());
}