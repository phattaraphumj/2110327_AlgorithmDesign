#include <bits/stdc++.h>
using namespace std;

int BSD(int start,int stop,vector<int> &v,int num){
    int m = (start + stop)/2;
    if(start == stop){
        if(num < v[0])return -1;
        if(num < v[start])return start-1;
        if(num == v[start])return start;
        if(num > v[v.size()-1])return v.size()-1;
    }

    if(v[m] > num){
        return BSD(start,m,v,num);
    }else{
        return BSD(m+1,stop,v,num);
    }
}

int main(){
    int N,M,xi;
    cin >> N >> M;
    vector<int> v(N);
    for(int i = 0;i<N;i++)cin >> v[i];
    for(int i = 0;i<M;i++){
        cin >> xi;
        cout << BSD(0,N-1,v,xi)<< "\n";
    }
}