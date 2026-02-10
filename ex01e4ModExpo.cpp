#include <bits/stdc++.h>
using namespace std;

int modExpo(int X,int n,int k){
    if(n==1){
        return X%k;
    }
    int tmp = modExpo(X,n/2,k);
    tmp = (tmp*tmp)%k;
    if(n%2==1){
        return (tmp*(X%k))%k;
    }else{
        return tmp;
    }
}
int main(){
    int X,n,k;
    cin >> X >> n >>k;
    cout << modExpo(X,n,k);
}