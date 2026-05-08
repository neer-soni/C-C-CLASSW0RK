#include<iostream>
using namespace std;
class Students{
    public:
    int roll_no;
    string name;
    
    void display()
    {
        cout<<"Roll No: "<<roll_no<<endl;
        cout<<"Name: "<<name<<endl;
    }
};
int main()
{
    Students s1[5];
    
    for(int i=0;i<5;i++)
    {
        cout<<"Enter Roll No and Name of Student "<<i+1<<": ";
        cin>>s1[i].roll_no>>s1[i].name;
    }
}