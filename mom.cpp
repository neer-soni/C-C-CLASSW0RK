#include<iostream>
using namespace std;
void fun(int &x){
    x+=10;
}
int main() {
    int a=5;
    fun(a);
    cout<<a;
    return 0;
}