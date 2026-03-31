#include<iostream>
using namespace std;

int main(){

    int inventory[2][2], reward[2][2], final[2][2];

for (int i = 0; i<2; i++){
    for (int j = 0; j<2; j++){
        cin>>inventory[i][j];
    }
}
for (int i = 0; i<2; i++){
    for (int j = 0; j<2; j++){
        cin>>reward[i][j];
    }
}
for (int i = 0; i<2; i++){
    for (int j = 0; j<2; j++){
        final[i][j]= inventory[i][j] + reward[i][j];
        }
}


for (int i = 0; i<2; i++){
    cout<<"[";
    for (int j = 0; j<2; j++){
        cout<<final[i][j]<<" ";
        
    }
    cout<<"]";
}




}











