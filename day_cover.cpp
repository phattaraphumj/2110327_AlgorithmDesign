#include <bits/stdc++.h>
using namespace std;



void day_cover(){

}



int main(){
    int n,m,dateav;
    vector<vector<int>> A;
    cin >> n >>m;
    for(int i = 0;i<m;i++){
        cin >> dateav;
        vector<int> S;
        for(int j = 0;j<dateav;j++){
            int a;
            cin >> a;
            S.push_back(a);
        }
        A.push_back(S);
    }

    
}