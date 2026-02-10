#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void recur(vector<vector<ll>> &v,ll r,ll c,ll n,ll t,ll neg){ //t = 1 ..T;neg = 1 ..-1;
    ll size = 1LL<<n;
    ll mid = size/2;
    if(t == 1) {
        swap(r,c);
        t=0;
    }
    if(n==1){
        if(neg == 1){
            cout << v[r-1][c-1] * -1 << "\n";
            return;
        }
        cout << v[r-1][c-1] << "\n";
        return;
    }

    if(r<=mid && c<= mid){
        return recur(v,r,c,n-1,t,neg);
    }
    else if (r<=mid && c> mid){
        return recur(v,r,c-mid,n-1,1-t,neg);
    }
    else if (r>mid && c<= mid){
        return recur(v,r-mid,c,n-1,t,1-neg);
    }
    else if (r>mid && c>mid){
        return recur(v,r-mid,c-mid,n-1,1-t,1-neg);
    }
    
}

int main(){
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> v(2,vector<ll>(2));
    for(ll i=0;i<=1;i++){
        for(ll j =0;j<=1;j++){
            cin >> v[i][j];
        }
    }
    while(m--){
        ll r,c;
        cin >> r >> c;
        recur(v,r,c,n,0,0);
    }


}