//polymorphism says that a function can behave differently with different scenario 
//compile time check whcih function to called by data types
//abstraction hiding unnecessary data / irrelevant details and showing only relevent data
#include<iostream>
using namespace std;
class rent{
  public:
void RentalCost(double dailyRate) {
  double rate = dailyRate;
  cout<<"your total amount is : "<<rate<<endl;
}

void RentalCost(double dailyRate, int days) {
  double rate = dailyRate*days;
  cout<<"your total amount is : "<<rate<<endl;
}

void RentalCost(double dailyRate, int days, double taxRate){
double rate = dailyRate*days;
double tax = rate*(1+(taxRate/100));
cout<<"your total amount is : "<<tax<<endl;

}};
int main() {

rent car1;
car1.RentalCost(1000.0);
car1.RentalCost(1000.0,5);
car1.RentalCost(1000.0,5,10);
  return 0;
}