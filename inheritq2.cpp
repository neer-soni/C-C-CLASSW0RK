#include <iostream>
using namespace std;

class Employee
{
public:
    string name = "Amit";
    int id = 5001;
};
class Manager : public Employee
{
public:
    int salary = 30000;
    int bonus = 5000;
    int total = salary + bonus;

    void displayinfo()
    {
        cout << "Name : " << name << endl;
        cout << "Id : " << id << endl;
        cout << "Salary : " << salary << endl;
        cout << "Bonus : " << bonus << endl;
        cout << "Total Salary : " << total << endl;  
    }
};
int main()
{

    Manager E1;
    E1.displayinfo();
}
