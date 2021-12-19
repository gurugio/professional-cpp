#include <string>
#include <iostream>

using namespace std;

class AirlineTicket
{
public:
    AirlineTicket();
    ~AirlineTicket() {}

    double calculatePriceInDollars() const;

    string &getPassengerName() { return m_passengerName; }
    void setPassengerName(const string &name) { m_passengerName = name; }

    int getNumberOfMiles() const { return m_numberOfMiles; }
    void setNumberOfMiles(int miles) { m_numberOfMiles = miles; }

    bool hasEliteSuperRewardsStatus() const { return m_hasEliteSuperRewardsStatus; }
    void setHasEliteSuperRewardsStatus(bool status)
    {
        m_hasEliteSuperRewardsStatus = status;
    }

private:
    string m_passengerName;
    int m_numberOfMiles;
    bool m_hasEliteSuperRewardsStatus;
};

AirlineTicket::AirlineTicket() : m_passengerName{"Unknown"},
                                 m_numberOfMiles{0},
                                 m_hasEliteSuperRewardsStatus{false}
{
}

double AirlineTicket::calculatePriceInDollars() const
{
    if (hasEliteSuperRewardsStatus())
    {
        return 0;
    }
    return getNumberOfMiles() * 0.1;
}

int main()
{
    AirlineTicket ticket;
    cout << ticket.getPassengerName() << ": " << ticket.getNumberOfMiles() << endl;

    ticket.setPassengerName("Gioh Kim");
    ticket.setNumberOfMiles(10'000);
    cout << ticket.getPassengerName() << ": " << ticket.getNumberOfMiles() << endl;

    // return lvalue
    ticket.getPassengerName() = "Gioh Kim2";
    cout << ticket.getPassengerName() << ": " << ticket.getNumberOfMiles() << endl;
}