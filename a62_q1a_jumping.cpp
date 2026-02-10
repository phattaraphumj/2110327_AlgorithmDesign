#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int my_recur(int n,vector<int> &v,int pos){
    if(pos >=n)return 0;
    int sum = 0;
    sum += v[pos];
    int p1 = my_recur(n,v,pos+1);
    int p2 = my_recur(n,v,pos+2);
    int p3 = my_recur(n,v,pos+3);
    return sum+max({p1,p2,p3});
}
int main(){
    ll n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    cout << my_recur(n,v,0);
}