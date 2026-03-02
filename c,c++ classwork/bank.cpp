//class named BankAccount
//accountHolderName
//balance
//rewardPoints
//constructor - account details and balance
//fnc withdraw (-500 points and -20 rewards points)
//fnc displayAccount( update account details)

//main function (constructor withdrwar())

#include<iostream>
using namespace std;

class BankAccount{  

private:
string accountHolderName;
int balance;
int rewardPoints;

public:
BankAccount(string name, double initialbalance, int reward) {
accountHolderName = name;
balance = initialbalance;
rewardPoints = reward;
}
void withdraw(double amount, int point){
    balance -= amount;
    rewardPoints -= point;
    cout<<"withdraw hogya"<<endl;
}
void displayAccount(){
cout<<"NAME "<<accountHolderName<<endl;
cout<<"Balance "<<balance<<endl;
cout<<"REWARD POINTS "<<rewardPoints;
}};

int main(){

BankAccount user1("neer",15000.0,1000);

user1.withdraw(500.0,20);
user1.displayAccount();
}

















