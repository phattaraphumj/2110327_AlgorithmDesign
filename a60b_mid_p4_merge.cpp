#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int target_k;
int current_k = 1;

void count(int &current_k,int target_k,vector<int> &v,int l,int r){
    if(current_k >= target_k || r-l<= 1)return;

    int m = (l+r)/2;

    swap(v[m-1],v[m]); 
    current_k+=2;
    count(current_k,target_k,v,l,m);
    count(current_k,target_k,v,m,r);
}
int main(){
    int n,k;
    cin >> n >>k ;
    target_k = k;
    vector<int> v(n);
    if(target_k%2 == 0 || target_k > n*2-1){
        cout << -1;
        return 0;
    }
    for(int i = 1;i<=n;i++){
        v[i-1] = i;
    }
    count(current_k,target_k,v,0,n);
    for(auto x:v){
        cout << x << " ";
    }
}