
#include <iostream>
using namespace std;
class rent
{
    public:
    double dailyRate;
    int days;
    double taxRate;
public:
    int RentalCost( dailyRate)
    {
        double rate = dailyRate;
        cout << "your total amount is : " << rate << endl;
    }

    int RentalCost( dailyRate,  days)
    {
        double rate = dailyRate * days;
        cout << "your total amount is : " << rate << endl;
    }

    int RentalCost( dailyRate,  days, taxRate)
    {
        double rate = dailyRate * days;
        double tax = rate * (1 + (taxRate / 100));
        cout << "your total amount is : " << tax << endl;
    }
};
int main()
{
 
    rent car1;
    car1.RentalCost(1000.0);
    car1.RentalCost(1000.0, 5);
    car1.RentalCost(1000.0, 5, 10);
    return 0;
}