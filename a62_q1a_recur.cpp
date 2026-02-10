#include <bits/stdc++.h>
using namespace std;

void recur(vector<vector<int>> &v, int a, int b,int top,int bottom,int left,int right){
    if(a==0){
        v[top][left] = b;
        return;
    }
    int mx = (left+right)/2;
    int my = (top+bottom)/2;
    recur(v,a-1,b,top,my,left,mx);
    recur(v,a-1,b-1,top,my,mx,right);
    recur(v,a-1,b+1,my,bottom,left,mx);
    recur(v,a-1,b,my,bottom,mx,right);
}

int main(){
    int a,b;
    cin >> a >> b;
    int r = 1<<a;
    vector<vector<int>> v(r,vector<int>(r));
    recur(v,a,b,0,r,0,r);
    // cout << r;
    for(auto &x:v){
        for(int i:x){
            cout << i << " ";
        }
        cout << "\n";
    }
}