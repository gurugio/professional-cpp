#include <string>
#include <string_view>
#include <fmt/core.h>
#include <cctype>
#include <memory>

using namespace std;

class Person
{
public:
    Person(string firstname, string lastname);
    Person();
    Person(string firstname,
           string lastname,
           string initial);
    ~Person() = default;

    string getFirstName(void) const;
    void setFirstName(string name);

    string getLastName(void) const;
    void setLastName(string name);

    string getInitial(void) const;
    void setInitial(string name);

private:
    class Impl;
    unique_ptr<Impl> m_impl;
};

class Person::Impl
{
public:
    Impl(string firstname, string lastname);
    Impl() = default;
    Impl(string firstname,
         string lastname,
         string initial);

    string getFirstName(void) const;
    void setFirstName(string name);

    string getLastName(void) const;
    void setLastName(string name);

    string getInitial(void) const;
    void setInitial(string name);

private:
    string m_firstname;
    string m_lastname;
    string m_initial;
};
