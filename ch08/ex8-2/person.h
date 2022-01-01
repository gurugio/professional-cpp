#include <string>
#include <string_view>

using namespace std;
class Person
{
public:
    Person(string firstname, string lastname) : m_firstname{move(firstname)},
                                                m_lastname{move(lastname)}
    {
    }
    Person() = default;

    ~Person()
    {
        cout << "destructor:" << m_firstname << endl;
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

private:
    string m_firstname;
    string m_lastname;
};