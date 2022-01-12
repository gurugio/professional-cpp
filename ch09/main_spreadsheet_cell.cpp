#include "spreadsheet_cell.h"

int main()
{
    SpreadsheetCell cell{4};
    SpreadsheetCell cell_default; // default ctor
    cell.show();
    cell_default.show();
    cell_default = cell; // copy
    cell_default.show();
    SpreadsheetCell cell_string{"123.456"};
    cell_string.show();

    SpreadsheetCell cell_sum{cell + cell_string};
    cell_sum.show();

    SpreadsheetCell cell_add;
    cell_add = 1.11 + cell_sum + 1.11;
    cell_add.show();
}