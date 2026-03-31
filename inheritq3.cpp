#include <iostream>
using namespace std;

class Person
{
public:
    string name;

    void showname(string n)
    {
        name = n;
        cout << "Name : " << name << endl;
    }
};

class Employee : public Person
{
public:
    int employeeID;

    void showdata(int id)
    {
        employeeID = id;
        cout << "ID : " << employeeID << endl;
    }
};
class Manager : public Employee
{
public:
    int salary;

    void showsalary(int s)
    {
        salary = s;
        cout << "Salary : " << salary << endl;
    }
};
int main()
{ 

    Manager u1;
    u1.showname("Neha");
    u1.showdata(1023);
    u1.showsalary(50000);
}