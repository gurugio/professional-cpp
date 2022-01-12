#include <string>
#include <string_view>
#include <iostream>
#include <fmt/core.h>

class SpreadsheetCell
{
public:
    SpreadsheetCell() = default;
    SpreadsheetCell(double initialValue) : m_value{initialValue}
    {
    }
    SpreadsheetCell(std::string_view initialValue)
        : SpreadsheetCell{stringToDouble(initialValue)}
    {
    }
    SpreadsheetCell(const SpreadsheetCell &src) : m_value{src.m_value}
    {
        std::cout << "spreadsheelcell  copy-ctor\n";
    }
    SpreadsheetCell &operator=(const SpreadsheetCell &rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }
        std::cout << "spreadsheelcell assign\n";
        m_value = rhs.m_value;
        return *this;
    }

    ~SpreadsheetCell()
    {
        std::cout << fmt::format("Destructor called: val={} this={:p}\n",
                                 m_value, (void *)this);
    }

    void set(double value);
    double getValue() const;

    void set(std::string_view value);
    std::string getString() const;

    void set(int value) = delete;

    void show() const
    {
        std::cout << "val:" << m_value << std::endl;
    }

    SpreadsheetCell &operator+=(const SpreadsheetCell &rhs)
    {
        set(getValue() + rhs.getValue());
        return *this;
    }
    SpreadsheetCell &operator-=(const SpreadsheetCell &rhs)
    {
        set(getValue() - rhs.getValue());
        return *this;
    }
    SpreadsheetCell &operator*=(const SpreadsheetCell &rhs)
    {
        set(getValue() * rhs.getValue());
        return *this;
    }
    SpreadsheetCell &operator/=(const SpreadsheetCell &rhs)
    {
        if (m_value == 0)
        {
            std::__throw_invalid_argument("Divide by zero");
        }
        set(getValue() / rhs.getValue());
        return *this;
    }

private:
    static std::string doubleToString(double value);
    static double stringToDouble(std::string_view value);
    double m_value{0};
    mutable size_t m_numAccesses{0};
};

SpreadsheetCell operator+(const SpreadsheetCell &lhs,
                          const SpreadsheetCell &rhs);
SpreadsheetCell operator-(const SpreadsheetCell &lhs,
                          const SpreadsheetCell &rhs);
SpreadsheetCell operator*(const SpreadsheetCell &lhs,
                          const SpreadsheetCell &rhs);
SpreadsheetCell operator/(const SpreadsheetCell &lhs,
                          const SpreadsheetCell &rhs);

SpreadsheetCell operator==(const SpreadsheetCell &lhs,
                           const SpreadsheetCell &rhs);