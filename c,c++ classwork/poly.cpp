//polymorphism says that same name with different functionality 

#include<iostream>
using namespace std;

void plus(int x, int y) {
  return x + y;
}

void plus(double x, double y, double z) {
  return x + y + z;
}

int main() {
  int result1 = plus(3, 7);
  int result2 = plus(1.2, 2.4, 3.8);

  cout << "Sum of 2 numbers: " << result1 <<endl;
  cout << "Sum of 3 numbers: " << result2<<endl;
  return 0;
}