#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll thanos(vector<ll> &v,ll l,ll r,ll B,ll A){

    auto it_start = lower_bound(v.begin(), v.end(), l);
    auto it_end = lower_bound(v.begin(), v.end(), r);
    ll m = distance(it_start, it_end);
    
    ll rightTree = A;
    if(m!=0)rightTree = B*m*(r-l);
    

    ll mid = (r+l)/2;
    if(r - l == 1 || m == 0)
    {
        return rightTree;
    }
    ll leftTree = thanos(v,l,mid,B,A) + thanos(v,mid,r,B,A);

    return min(leftTree,rightTree);
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll p, k, A, B;
    cin >> p >> k >> A >> B;

    ll l = 1LL<<p;
    vector<ll> v(k);
    for(ll i =0;i<k;i++){
        cin >> v[i];
        v[i]--;
    }
    sort(v.begin(), v.end());
    cout << thanos(v,0,l,B,A);

    // for(auto x:v)cout << x;
}