#include <iostream>
using namespace std;
class CarRental
{
public:  
     CarRental(double dailyRate)
    {
        double rate = dailyRate;
        cout << "your total amount is : " << rate << endl;
    }

    CarRental(double dailyRate, int days)
    {
        double rate = dailyRate * days;
        cout << "your total amount is : " << rate << endl;
    }
    CarRental(double dailyRate, int days, double taxRate)
    {
        double rate = dailyRate * days;
        double tax = rate * (1 + (taxRate / 100));
        cout << "your total amount is : " << tax << endl;
    }
};
int main()
{

    CarRental car1(1000.0);
    CarRental car2(1000.0, 5);
    CarRental car3(1000.0, 5, 10);
    return 0;
}