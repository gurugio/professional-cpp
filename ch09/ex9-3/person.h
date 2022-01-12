#include <string>
#include <string_view>
#include <fmt/core.h>
#include <cctype>

using namespace std;
class Person
{
public:
    Person(string firstname, string lastname) : m_firstname{move(firstname)},
                                                m_lastname{move(lastname)}
    {
        m_initial = fmt::format("{:c}{:c}",
                                toupper(m_firstname[0]),
                                toupper(m_lastname[0]));
    }
    Person() = default;
    Person(string firstname,
           string lastname,
           string initial) : m_firstname{move(firstname)},
                             m_lastname{move(lastname)},
                             m_initial{move(initial)}
    {
    }

    string getFirstName(void) const
    {
        return m_firstname;
    }
    void setFirstName(string name)
    {
        m_firstname = move(name);
    }

    string getLastName(void) const
    {
        return m_lastname;
    }
    void setLastName(string name)
    {
        m_lastname = move(name);
    }

    string getInitial(void) const { return m_initial; }
    void setInitial(string name)
    {
        m_initial = move(name);
    }

    // for ex9-2
    bool operator==(const Person &rhs) const
    {
        return m_firstname == rhs.m_firstname && m_lastname == rhs.m_lastname;
    }

    // removed for ex9-3
    /*
    std::strong_ordering operator<=>(const Person &rhs) const
    {
        if (m_firstname != rhs.m_firstname)
        {
            return m_firstname <=> rhs.m_firstname;
        }
        return m_lastname <=> rhs.m_lastname;
    }
    */
    bool operator<(const Person &rhs) const
    {
        if (m_firstname != rhs.m_firstname)
        {
            return m_firstname < rhs.m_firstname;
        }
        return m_lastname < rhs.m_lastname;
    }

    bool operator!=(const Person &rhs) const
    {
        return !(*this == rhs);
    }

    bool operator>(const Person &rhs) const
    {
        return (*this != rhs) && !(*this < rhs);
    }

    bool operator>=(const Person &rhs) const
    {
        return (*this == rhs) || (*this > rhs);
    }

    bool operator<=(const Person &rhs) const
    {
        return (*this == rhs) || (*this < rhs);
    }

private:
    string m_firstname;
    string m_lastname;
    string m_initial;
};