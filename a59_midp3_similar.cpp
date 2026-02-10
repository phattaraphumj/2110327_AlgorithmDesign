#include <bits/stdc++.h>
using namespace std;

bool similar(string a,string b){
    if(a == b){
        return true;
    }
    int len = a.size();
    if(len == 1){
        if(a == b)return true;
        else return false;
    }
    int m = len/2;
    string a1 = "";
    string a2 = "";
    string b1 = "";
    string b2 = "";
    for(int i = 0;i<m;i++){
        a1 += a[i];
        a2 += a[i+m];
        b1 += b[i];
        b2 += b[i+m];
    }
    return(similar(a1,b1) && similar(a2,b2))  || (similar(a1,b2) && similar(a2,b1));

}

int main(){
    string a,b;
    cin >> a >> b;

    if(similar(a,b)){
        cout << "YES";
    }else{
        cout << "NO";
    }


    /*aaba
    abaa*/
    
}