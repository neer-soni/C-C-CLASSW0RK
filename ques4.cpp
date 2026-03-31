#include<iostream>
using namespace std;
int main() {

int item;
int quantity;
int price;
float final;

cout<<"ENTER THE ITEM NO.\n";
cin>>item;

cout<<"ENTER THE QUANTITY\n";
cin>>quantity;

cout<<"ENTER THE PRICE OF THE UNIT\n";
cin>>price;

final= (quantity*price)-((quantity*price)*0.20);

cout<<"THANKS FOR SHOPPING\n";
cout<<"ITEM NO.\n";
cout<<item<<endl;
cout<<"QUANITY OF THE ITEM\n";
cout<<quantity<<endl;
cout<<"PRICE PER UNIT\n";
cout<<price<<endl;
cout<<"DICOUNT OF 20%\n";
cout<<"FINAL AMOUNT AFTER DISCOUNT\n";
cout<<final<<endl;













}