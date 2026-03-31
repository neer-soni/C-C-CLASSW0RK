#include<iostream>
using namespace std;

class Base{
    public:
    Base(int x){
        cout<<"pagak h "<<x;
    }
};
class Derived : public Base{
    public:
    Derived(int a, int b){
        cout << "ghochu h"<<b<<endl;
    }
};
int main(){

    Derived d(10,20);
}