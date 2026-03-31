#include <iostream>

using namespace std;

class Person
{
public:
    int age = 19;
    string name = "jake";

    void displayPerson()
    {
        cout << "AGE : " << age << endl;
        cout << "NAME : " << name << endl;
    }
};
class Student : public Person
{

public:
    int roll = 367;
    int marks = 99;

    void displayStudent()
    {
        cout << "AGE : " << age << endl;
        cout << "NAME : " << name << endl;
        cout << "ROLL NO. : " << roll << endl;
        cout << "MARKS : " << marks << endl;
    }
};
int main()
{
    Student st1;
    st1.displayPerson();
    st1.displayStudent();
}