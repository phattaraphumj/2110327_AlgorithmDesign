#include <iostream>
#include <algorithm>

using namespace std;

int recur(int Count,int x){
    if(x == 0)return Count;
    if(Count > 26){
        return Count;
    }
    int l = (x + 1)% 16777216;
    int r = (x *2)% 16777216;
    return min(recur(Count+1,l),recur(Count+1,r));
}
int main() {
    int x;
    cin >> x;
    cout<<recur(0,x);
}