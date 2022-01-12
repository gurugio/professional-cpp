#include <string>
#include <string_view>
#include <fmt/core.h>

using namespace std;
class Person
{
public:
    Person(string firstname, string lastname) : m_firstname{move(firstname)},
                                                m_lastname{move(lastname)}
    {
    }
    Person() = default;

    Person(const Person &right) : m_firstname{right.m_firstname},
                                  m_lastname{right.m_lastname}
    {
        cout << fmt::format("copy-con: {} {}\n", m_firstname, m_lastname);
    }

    // for ex9-1
    Person(Person &&src) noexcept
    {
        cout << fmt::format("move-ctor: {}-{}",
                            src.m_firstname, src.m_lastname);
        m_firstname = move(src.m_firstname);
        m_lastname = move(src.m_lastname);
    }

    Person &operator=(const Person &rhs)
    {
        cout << fmt::format("assign-const: {} {}\n", rhs.m_firstname, rhs.m_lastname);
        if (this == &rhs)
        {
            return *this;
        }
        m_firstname = rhs.getFirstName();
        m_lastname = rhs.getLastName();
        return *this;
    }

    // for ex9-1
    Person &operator=(Person &&src) noexcept
    {
        cout << fmt::format("move-assignment: old={}-{}, new={}-{}\n",
                            m_firstname, m_lastname,
                            src.m_firstname, src.m_lastname);
        if (this == &src)
            return *this;

        m_firstname = move(src.m_firstname);
        m_lastname = move(src.m_lastname);
        return *this;
    }

    ~Person()
    {
        cout << fmt::format("destructor: {} {}\n", m_firstname, m_lastname);
    }
    string getFirstName(void) const
    {
        return m_firstname;
    }
    void setFirstName(string name)
    {
        cout << "use move to set m_firstname\n";
        m_firstname = move(name);
    }

    string getLastName(void) const
    {
        return m_lastname;
    }
    void setLastName(string name)
    {
        cout << "use move to set m_lastname\n";
        m_lastname = move(name);
    }

private:
    string m_firstname;
    string m_lastname;
};