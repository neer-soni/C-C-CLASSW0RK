//polymorphism says that same name with different functionality 
//:: scope resolution operator
#include<iostream>
using namespace std;

void plus(int x, int y) {
  return x + y;
}

void plus(double p, double q, double r) {
  return p + q + r;
}

int main() {
  int result1 = plus(3, 7);
  float result2 = plus(1.2, 2.4, 3.8);

  cout << "Sum of 2 numbers: " << result1 <<endl;
  cout << "Sum of 3 numbers: " << result2<<endl;
  return 0;
}