#include <bits/stdc++.h>
using namespace std;

string mulStr(const string &s,const int &k){
    string ans;
    for(int i=0;i<k;i++){
        ans += s;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> vMax(n);

    int max =0;
    for(int i =0;i<n;i++){
        cin >> v[i];
        vMax[i] = v[i];
        if(v[i] > max) max = v[i];
    }
    vector<string> output(max);

    while(max>0){
        string s = "";
        for(int i =0;i<n;i++){
            if(v[i] == 0){
                s+= mulStr(" ",vMax[i]*2);
                continue;
            }
            s+= mulStr(" ",(vMax[i]-v[i]));
            s+="/";
            s+= mulStr(" ",v[i]*2-2);
            s+= "\\";
            s+= mulStr(" ",(vMax[i]-v[i]));
            v[i]--;
        }
        output[max-1] = s;
        max--;
    }

    for(auto &x:output){
        cout << x << endl;
    }
}