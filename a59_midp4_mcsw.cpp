#include <bits/stdc++.h>
using namespace std;

int get_sum(vector<int> &S,int a,int b){
    if(a==0)return S[b];
    return S[b] - S[a-1];
}

int mss(vector<int> &A,int start,int stop,vector<int> &S,int &left,int &right,int maxLen){
    if (start == stop){
        return A[start];
        left = 0;
        right = A.size();
    }
    int m = (start+stop) / 2;
    int r1l = 0; int r1r = 0;
    int r1 = mss(A,start,m,S,r1l,r1r,maxLen);
    int r2l = 0; int r2r = 0;
    int r2 = mss(A,m+1,stop,S,r2l,r2r,maxLen);


    // #find max of B[start..m][m]
    int r3l = 0; int r3r = 0;
    int max_sum_left = get_sum(S,m,m);
    for(int i = start;i<=m-1;i++){
        if(get_sum(S,i,m) > max_sum_left ){
        max_sum_left = max(max_sum_left,get_sum(S,i,m));
        r3l = i;
        }
    }
    // #find max of B[m+1..stop][stop]
    int max_sum_right = get_sum(S,m+1,m+1);
    for(int j = m+2;j<=stop;j++){
        if(get_sum(S,m+1,j) > max_sum_right ){
        max_sum_right = max(max_sum_right,get_sum(S,m+1,j));
        r3r = j;
        }
    }
    int r3 = max_sum_left + max_sum_right;

    if((r1r-r1l+1) - maxLen >=0){
        for(int i =0;i<=(r1r-r1l+1) - maxLen;i++){
            
        }
    } 

    return max({r1,r2,r3});
}

int main(){

}