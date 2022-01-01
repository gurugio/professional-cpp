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

#if 0
    Person(const Person &right) : m_firstname{right.m_firstname},
                                  m_lastname{right.m_lastname}
    {
        cout << fmt::format("copy-con: {} {}\n", m_firstname, m_lastname);
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
    ~Person()
    {
        cout << "destructor:" << m_firstname << endl;
    }
#endif
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

private:
    string m_firstname;
    string m_lastname;
    string m_initial;
};