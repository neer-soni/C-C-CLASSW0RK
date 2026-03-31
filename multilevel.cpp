#include <iostream>
using namespace std;

class A
{
public:
    A()
    {
        cout << "Constructor of A" << endl;
    }
    void show()
    {
        cout << "Show of A" << endl;
    }
};
class B
{
public:
    B()
    {
        cout << "Constructor of B" << endl;
    }
    void show()
    {
        cout << "Show of B" << endl;
    }
};
class C : public A, public B
{
public:
    C()
    {
        cout << "Constructor of C" << endl;
    }
};
int main()
{

    C myobj;
    // myobj.show();
    myobj.A::show();
    myobj.B::show();
}