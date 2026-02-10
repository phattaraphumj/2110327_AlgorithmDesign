#include <bits/stdc++.h>
using namespace std;
int all0(int n,vector<vector<int>> &v,int rb,int cb){
    for(int i = rb;i<rb+n;i++){
        for(int j = cb;j<cb+n;j++){
            if(v[i][j] != 0)return 0; // 0 : ไม่tri
        }
    }
    return 1; // 1 : tri
}

int triforce(int n,vector<vector<int>> &v,int rb,int cb){
    int m = n/2;
    if(n==1){ 
        return v[rb][cb];
    }
    int s = all0(m,v,rb+m,cb+m);
    int p = triforce(m,v,rb,cb);
    int q = triforce(m,v,rb,cb+m);
    int r = triforce(m,v,rb+m,cb);

    if(s == 1){
        if (p == 0 || q == 0 || r == 0) return 0;
        if(p == q)return p;
        if(q == r)return q;
        if(r == p)return r;
        return 0;
    }else{
        return 0;
    }
}

int main()
{
    int N = 3; 
    int n;

    while (N--){
        cin >> n;

        vector<vector<int>> v(n, vector<int>(n));

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> v[i][j];
            }
        }
        cout << triforce(n,v,0,0) << endl;
    }
}