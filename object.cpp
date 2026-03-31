#include<iostream>
using namespace std;
//abstraction hiding unnecessary data / irrelevant details and showing only relevent data
class area{

public:

 area(int r, int n) {
    float areatri = r*n*0.5;
    cout << areatri << endl;
 }
 area(double r, double n) {
   float areatri = r*n*0.5;
    cout << areatri << endl;
 }
};

area a1(10,30);
area a3(10.5,15.6);
 
int main() {

area a2(29,45);
}