#include<iostream>
using namespace std;

int main() {
    int value;
int pos_value;
int neg_value;
int total = 0;
while(true){
    cout<<"enter 0 to exit\n";
cout<<"enter the number\n";
cin>>value;

if (value == 0){
    break;
}
 if (value<0) {
    value = neg_value;
    continue;
 }
 if (value >0) {
total+=value;
 }
}

cout<<total;
}