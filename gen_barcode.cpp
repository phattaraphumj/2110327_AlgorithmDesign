#include <bits/stdc++.h>
using namespace std;



void barcode(int len,int count1,int B,int A,string word){
    if(len==B){
        if(count1 == A){
        cout << word << "\n";}
        
        return;
    }
    barcode(len+1,count1,B,A,"0"+word);
    if(count1 < A){
        barcode(len+1,count1+1,B,A,"1"+word);
    }
}


int main(){
    int A,B;
    cin >> A >>B;
    barcode(0,0,B,A,"");
}