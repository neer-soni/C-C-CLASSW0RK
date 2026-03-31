#include<iostream>
using namespace std;
void test(){
      int a = 6;
    double b = 10;

int r;
r = a&&b;// non zero value comparioson 
    cout<<r;//operator presidency priority << over && without the bracket 
}
int main(){


  test();
   
    return 0;
}