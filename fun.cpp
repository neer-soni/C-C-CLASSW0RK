#include<iostream>
using namespace std;



void swap(int x, int y) {

cout<<"X and Y before Swap "<<x<<y<<endl;
int temp=x;
x=y;
y=temp;
cout<<"X and Y after Swap "<<x<<y<<endl;

} 
int main()
{

int num1,num2;
cout<<"Provide 2 values"<<endl;
cin>>num1>>num2;
cout<<"Values of num1 and num2 before function call"<<num1<<num2<<endl;
swap(num1,num2);
cout<<"values of num1 and num2 before function call"<<num1<<num2<<endl;
return 0;


}