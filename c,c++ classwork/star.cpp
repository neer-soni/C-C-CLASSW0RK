#include<iostream>
using namespace std;

void star() {
int rows = 5;
for (int i = 0; i<=rows;i++){
    for (int space =1; space<=rows-i;space++){
        cout<<" ";
    }
    for (int j = 1; j <= (2 * i + 1); ++j) {
            cout <<"*";
        }

    
    cout<<endl;
}




}


int main () {

star();












}