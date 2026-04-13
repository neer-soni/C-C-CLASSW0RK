#include <iostream>
using namespace std;

class Student {
private :
    static int  marks;
public:
    Student(){
        marks = 90;
    }
    friend void display();

/*static is a friend of the class and it can access 
the private members of the class without creating an object of the class.*/

};
int Student::marks;  // Add this line to define the static member

void display(){
    cout<<"the marks of the student is "<<Student::marks;
}
int main(){
    Student s1;
    display();
    return 0;
}