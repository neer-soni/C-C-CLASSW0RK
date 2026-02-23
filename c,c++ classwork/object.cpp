#include<iostream>
using namespace std;

class area{

public:

 area(int r, int n) {
    float areatri = r*n*0.5;
    cout << areatri << endl;
 }
};

area a1(10,30);

int main() {

area a2(50,80);
}