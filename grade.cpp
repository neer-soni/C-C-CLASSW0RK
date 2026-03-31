#include<iostream>
using namespace std;
int main() {
    int marks;

cout<<"enter marks: ";
cin >> marks;
    if(marks<0 || marks>100){
        cout<<"invalid marks...";
     }

     switch(marks/10){
        case 10: cout<<"GRADE A+\n";
        break;
        case 9:  cout<<"GRADE A\n";
        break;
        case 8:  cout<<"GRADE A-\n";
        break;
        case 7:  cout<<"GRADE B+\n";
        break;
        case 6:  cout<<"GRADE B\n";
        break;
        case 5:  cout<<"GRADE B-\n";
        break;
        case 4:  cout<<"GRADE C\n";
        break;
        case 3: cout<<"GRADE D\n";
        break;
        default: cout<<"GRADE F\n";
     }
     return 0;
}