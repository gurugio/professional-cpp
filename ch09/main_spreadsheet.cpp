#include <iostream>
#include "spreadsheet.h"
using namespace std;

void show(Spreadsheet &s)
{
    for (size_t i{0}; i < s.getWidth(); i++)
    {
        for (size_t j{0}; j < s.getHeight(); j++)
        {
            cout << s.getCellAt(i, j).getString() << ' ';
        }
        cout << '\n';
    }
}

Spreadsheet create(SpreadsheetApplication &app)
{
    cout << "create\n";
    return Spreadsheet{2, 2, app};
}

int main()
{
    SpreadsheetApplication app;
    Spreadsheet s1{2, 2, app}, s2{2, 2, app};
    cout << "-----------------------------\n";
    // s1.pointers();
    // s2.pointers();
    // cout << s1.getCellAt(0, 0).getString() << endl;
    // cout << s2.getCellAt(0, 0).getString() << endl;
    // cout << "-----------------------------\n";
    // s2 = s1;
    // cout << "-----------------------------\n";
    // s1.pointers();
    // s2.pointers();
    // cout << s1.getCellAt(0, 0).getString() << endl;

    Spreadsheet s3{2, 2, app};
    s3 = move(s1);
    cout << "-----------------------------\n";

    s3 = create(app);
    cout << s3.getCellAt(0, 0).getString() << endl;
    cout << "-----------------------------\n";
}