#include "spreadsheet_cell.h"
#include <charconv>
using namespace std;

void SpreadsheetCell::set(double value)
{
    m_value = value;
}

double SpreadsheetCell::getValue() const
{
    m_numAccesses++;
    return m_value;
}

void SpreadsheetCell::set(string_view value)
{
    m_value = stringToDouble(value);
}

string SpreadsheetCell::getString() const
{
    m_numAccesses++;
    return doubleToString(m_value);
}

string SpreadsheetCell::doubleToString(double value)
{
    return to_string(value);
}

double SpreadsheetCell::stringToDouble(string_view value)
{
    double number{0};
    from_chars(value.data(), value.data() + value.size(), number);
    return number;
}

SpreadsheetCell operator+(const SpreadsheetCell &lhs,
                          const SpreadsheetCell &rhs)
{
    return SpreadsheetCell{lhs.getValue() + rhs.getValue()};
}

SpreadsheetCell operator-(const SpreadsheetCell &lhs,
                          const SpreadsheetCell &rhs)
{
    return SpreadsheetCell{lhs.getValue() - rhs.getValue()};
}

SpreadsheetCell operator*(const SpreadsheetCell &lhs,
                          const SpreadsheetCell &rhs)
{
    return SpreadsheetCell{lhs.getValue() * rhs.getValue()};
}

SpreadsheetCell operator/(const SpreadsheetCell &lhs,
                          const SpreadsheetCell &rhs)
{
    if (rhs.getValue() == 0)
    {
        __throw_invalid_argument("Divide by zero.");
    }
    return SpreadsheetCell{lhs.getValue() / rhs.getValue()};
}

SpreadsheetCell operator==(const SpreadsheetCell &lhs,
                           const SpreadsheetCell &rhs)
{
    return lhs.getValue() == rhs.getValue();
}