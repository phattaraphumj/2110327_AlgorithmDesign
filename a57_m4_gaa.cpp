#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    ll len = 3;
    ll gaalen = 3;
    ll oldlen;
    while (true)
    {
        while (len < N)
        {
            oldlen = len;
            len = 2 * len + (gaalen + 1);
            gaalen++;
        }
        if (N > (oldlen + gaalen))
        {
            N -= (oldlen + gaalen);
            len = 3;
            gaalen = 3;
            continue;
        }
        if(N>oldlen){
            N-=oldlen;
            if (N != 1){
                cout << "a";
                break;}
            else{
                cout << "g";
                break;}
        }
        if (N <= 3)
        {
            if (N != 1){
                cout << "a";
                break;}
            else{
                cout << "g";
                break;}
        }
    }
}