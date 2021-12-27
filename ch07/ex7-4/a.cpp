#include <string>
#include <iostream>

using namespace std;

void fillWithM(char *text)
{
    int i{0};
    while (text[i] != '\0')
    {
        text[i] = 'm';
        i++;
    }
}

void modernFillWithM(string &text)
{
    for (auto &c : text)
    {
        c = 'm';
    }
}

int main()
{
    string empty{"Hello world"};
    modernFillWithM(empty);
    cout << empty << '\n';
}