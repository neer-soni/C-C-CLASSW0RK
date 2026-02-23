#include<iostream>
using namespace std;

int main() {

int a;

cout<<"WELCOME TO WEATHER APP\n";
cout<<"CELSIUS TO FAHRENHEIT ENTER 1\n";
cout<<"FARGENHEIT TP CELSIUS ENTER 2\n";
cout<<"ENTER THE FUNCTION CODE";
cin>>a;

if (a==1) {
 int celsius;
 float far;
 cout<<"enter the value\n";
 cin>>celsius;
far = (celsius*1.8)+32;

cout<<"IN FARHENHEIT\n";
cout<<far;
}

if (a==2) {
float celsius;
 float far;
 cout<<"enter the value\n";
 cin>>far;
celsius = (far-32)/1.8;

cout<<"IN CELSIUS\n";
cout<<celsius;
}


}