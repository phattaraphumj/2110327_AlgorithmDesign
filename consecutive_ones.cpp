#include <bits/stdc++.h>
using namespace std;


void combi(string num,int len,vector<string>& sol,int n,int k,int count,bool adj){
    if(len<n){
        combi(num+"0",len+1,sol,n,k,count,adj);
        if(num.back() == '1') count++;
        else count = 1;
        if(count >= k) adj = true;
        combi(num+"1",len+1,sol,n,k,count,adj);
    }else if(adj){
        sol.push_back(num);
    }
}
int main(){
    int n,k;
    cin >> n >>k;
    vector<string> sol;
    combi("",0,sol,n,k,1,false);
    sort(sol.begin(),sol.end());
    for(auto x:sol){
        cout<< x << "\n";
    }
}