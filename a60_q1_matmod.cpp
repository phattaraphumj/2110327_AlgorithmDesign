#include <bits/stdc++.h>
using namespace std;

struct matrix{
    int a;
    int b;
    int c;
    int d;
};

matrix MNmodK(matrix M,matrix N,int k){
    M.a %= k;M.b %= k;M.c %= k;M.d %= k;
    N.a %= k;N.b %= k;N.c %= k;N.d %= k;

    matrix tmp;
    tmp.a = M.a*N.a + M.b*N.c;
    tmp.b = M.a*N.b + M.b*N.d;
    tmp.c = M.c*N.a + M.d*N.c;
    tmp.d = M.c*N.b + M.d*N.d;

    tmp.a %= k;tmp.b %= k;tmp.c %= k;tmp.d %= k;
    return tmp;
}

matrix powerMod(matrix M,int n,int k){
    if(n==1){
        matrix a;
        a.a = M.a%k; a.b = M.b%k; a.c = M.c%k; a.d = M.d%k;
        return a;
    }
    if(n==2){
        return MNmodK(M,M,k);
    }
    if(n%2==0){
        matrix tmp = powerMod(M,n/2,k);
        return MNmodK(tmp,tmp,k);
    }else{
        matrix tmp = powerMod(M,n/2,k);
        tmp = MNmodK(tmp,tmp,k);
        matrix a;
        a.a = M.a%k; a.b = M.b%k; a.c = M.c%k; a.d = M.d%k;
        return MNmodK(tmp,a,k);
    }
}

int main(){
    int n,k;
    cin >> n >> k;
    matrix A;
    cin >> A.a;cin >> A.b;cin >> A.c;cin >> A.d;
    matrix ans = A;
    ans = powerMod(A,n,k);
    cout << ans.a << " "<< ans.b << " "<< ans.c << " "<< ans.d << " ";
}