#include <iostream>
using namespace std;

class B;
class A {
private:
    int a;
public:
    A() {
        a = 10;
    }   
    friend void display(A, B);
};
class B {
private:
    int b;      
public:
    B() {
        b = 20;
    }
    friend void display(A, B);
};
void display(A obj1, B obj2) {
    cout << "the value of a is " << obj1.a << endl;
    cout << "the value of b is " << obj2.b << endl;
}
int main() {
    A obj1;
    B obj2;
    display(obj1, obj2);
    return 0;
}