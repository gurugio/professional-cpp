#include "person.h"

using namespace std;

Person::Impl::Impl(string firstname, string lastname) : m_firstname{move(firstname)},
                                                        m_lastname{move(lastname)}
{
    m_initial = fmt::format("{:c}{:c}",
                            toupper(m_firstname[0]),
                            toupper(m_lastname[0]));
}
Person::Impl::Impl(string firstname,
                   string lastname,
                   string initial) : m_firstname{move(firstname)},
                                     m_lastname{move(lastname)},
                                     m_initial{move(initial)}
{
}

string Person::Impl::getFirstName(void) const
{
    return m_firstname;
}
void Person::Impl::setFirstName(string name)
{
    m_firstname = move(name);
}

string Person::Impl::getLastName(void) const
{
    return m_lastname;
}
void Person::Impl::setLastName(string name)
{
    m_lastname = move(name);
}

string Person::Impl::getInitial(void) const
{
    return m_initial;
}
void Person::Impl::setInitial(string name)
{
    m_initial = move(name);
}

Person::Person(string firstname, string lastname)
    : m_impl{make_unique<Impl>(move(firstname),
                               move(lastname))}
{
}
Person::Person()
    : m_impl{make_unique<Impl>()}
{
}
Person::Person(string firstname,
               string lastname,
               string initial)
    : m_impl{make_unique<Impl>(move(firstname),
                               move(lastname),
                               move(initial))}
{
}

string Person::getFirstName(void) const
{
    return m_impl->getFirstName();
}
void Person::setFirstName(string name)
{
    m_impl->setFirstName(move(name));
}

string Person::getLastName(void) const
{
    return m_impl->getLastName();
}
void Person::setLastName(string name)
{
    m_impl->setLastName(move(name));
}

string Person::getInitial(void) const
{
    return m_impl->getInitial();
}
void Person::setInitial(string name)
{
    m_impl->setInitial(move(name));
}
