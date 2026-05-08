#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public :
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
int total_cost = 0;
int total_gas = 0;
int start_station = 0;
int current = 0;

for (int i = 0; i<gas.size() ; i++){
    if (gas[i]>cost[i]){
        start_station = gas[i];
    }
}








}
};