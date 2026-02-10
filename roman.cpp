#include <bits/stdc++.h>
using namespace std;

int main(){

    std::unordered_map<char, int> romanValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    string in;
    cin >> in;
    int sum = 0;
    for(int i= in.size()-1;i >=0;i--){
        if(i==in.size()-1) {
            sum+=romanValues[in[i]];
            continue;
        }
        if(romanValues[in[i]] < romanValues[in[i+1]] ) sum-=romanValues[in[i]]; 
        else sum+= romanValues[in[i]];
    }
    cout << sum;
}