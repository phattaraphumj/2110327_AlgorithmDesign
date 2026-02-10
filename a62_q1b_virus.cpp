#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_divoc(vector<int> &v,int l,int r){
    int m = (l+r)/2;
    if(r-l <= 2){
        if(v[l] == 0 && v[l+1] == 1)return true;
        else return false;
    }
    bool left = is_divoc(v,l,m);
    bool right = is_divoc(v,m,r);
    if(left && right)return true;
    if( !left &&right){
        vector<int> tmp;
        for(int i = m-1;i>=l;i--){
            tmp.push_back(v[i]);
        }
        if(is_divoc(tmp,0,tmp.size())){
            return true;
        }
    }
    return false;
}

int main() {
    int n,k;
    cin >> n >> k;
    int twoK = 1<<k;
    vector<int> v(twoK);
    for(int i=0;i<n;i++){
        for(int j = 0;j<twoK;j++){
            cin >> v[j];
        }
        cout << (is_divoc(v,0,twoK)? "yes" : "no") <<endl;
    }
}