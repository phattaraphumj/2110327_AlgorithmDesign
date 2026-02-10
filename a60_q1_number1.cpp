#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int c = 0;
int findlen(int n){
    if(n<=1){
        return 1;
    }
    return 2*findlen(n/2)+1; 
}

void countOne(int n,int lCurrent ,int rCurrent,int llimit,int rlimit){
    int m = (lCurrent+rCurrent)/2;
    if(rCurrent <= llimit || lCurrent >= rlimit){
        return;
    }
    if(rCurrent - lCurrent <= 1){
        c+= n;
        return;
    }
    countOne(n/2,lCurrent,m,llimit,rlimit);
    if(m >= llimit && m<rlimit)c += (n % 2);
    countOne(n/2,m+1,rCurrent,llimit,rlimit);
}

int main()
{
    int n,l,r;
    cin >> n >> l >> r;
    l--;
    int lCurrent = findlen(n);
    countOne(n,0,lCurrent,l,r);
    cout << c;
}