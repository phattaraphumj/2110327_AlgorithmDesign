#include <bits/stdc++.h>
using namespace std;

bool is_divoc(vector<int> &v,int l,int r){
    int size = r-l;
    int m = (l+r)/2;
    if(size <= 2)return true;
    if(!is_divoc(v,l,m)) return false;
    if(!is_divoc(v,m,r)) return false;
    int bi = l;
    int ci = m;
    int countb = 0;
    int countc = 0;
    for(int i = 0;i<size/2;i++){
        if(v[bi+i] == 1)countb++;
        if(v[ci+i] == 1)countc++;
    }
    int countAbs = abs(countb - countc);
    if(countAbs<=1)return true;
    return false;
}

int main(){
    int n,k;
    cin >> n >> k;
    int len = 1<<k; //2**k
    while(n--){
        vector<int> v(len);
        for(int i =0;i<len;i++){
            cin >> v[i];
        }
        cout<<( (is_divoc(v,0,len))? "yes": "no" ) << endl;
    }
    cout << endl;
}