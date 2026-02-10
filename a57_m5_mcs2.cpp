#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll get_sum(vector<ll> &S,ll a,ll b){
    if(a==0)return S[b];
    return S[b] - S[a-1];
}

ll mss(vector<ll> &A,ll start,ll stop,vector<ll> &S,ll &MIN){
    if (start == stop){
        MIN = A[start];
        return A[start];
    }
    ll m = (start+stop) / 2;
    ll r1min = 1e18;
    ll r2min = 1e18;
    ll r1 = mss(A,start,m,S,r1min);
    ll r2 = mss(A,m+1,stop,S,r2min);
    // #find max of B[start..m][m]
    ll min_sum_left = get_sum(S,m,m);
    ll max_sum_left = get_sum(S,m,m);
    for(ll i = start;i<=m-1;i++){
        max_sum_left = max(max_sum_left,get_sum(S,i,m));
        min_sum_left = min(min_sum_left,get_sum(S,i,m));
    }
    // #find max of B[m+1..stop][stop]
    ll min_sum_right = get_sum(S,m+1,m+1);
    ll max_sum_right = get_sum(S,m+1,m+1);
    for(ll j = m+2;j<=stop;j++){
        max_sum_right = max(max_sum_right,get_sum(S,m+1,j));
        min_sum_right = min(min_sum_right,get_sum(S,m+1,j));
    }
    ll r3 = max_sum_left + max_sum_right;
    ll r3min = min_sum_left + min_sum_right;
    MIN = min({r1min,r2min,r3min});
    return max({r1,r2,r3});
}

int main(){
    ll N;
    cin >> N;
    vector<ll> v(N);
    vector<ll> S(N);
    ll sum = 0;
    for(ll i =0;i<N;i++){
        cin >> v[i];
        sum += v[i];
        S[i] = sum;
    }
    ll MIN = 1e18;
    ll MAX = mss(v,0,N-1,S,MIN);
    if (MAX < 0) { // กรณี - ทุกตัว เอาตัวมากสุด
        cout << MAX;
    } else {
        cout << max(MAX, sum - MIN);
    }
}