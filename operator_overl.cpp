#include<iostream>
using namespace std;
class add{
    public:
    int weight;
 
    add operator+(add w)
    {
        weight=weight+w.weight;
        return *this;
    }
};
int main()
{
    add a1,a2,a3;
    cout<<"Enter weight of first object: ";
    cin>>a1.weight;
    cout<<"Enter weight of second object: ";
    cin>>a2.weight;
    
    a3=a1+a2;
    
    cout<<"Total weight: "<<a3.weight<<endl;
}