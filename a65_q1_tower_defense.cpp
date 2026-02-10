#include <bits/stdc++.h>
using namespace std;
int n,m,k,w;
void recur(int turretNum,vector<int> &h,vector<int> &p,vector<int> &t,int CurrentHp,int &minHp){
    if(turretNum<k){
        bool shot = false;
        for(int i =0;i<m;i++){
            if(h[i]> 0 && abs(t[turretNum]-p[i]) <= w ){
                h[i]--;
                CurrentHp--;
                shot = true;
                recur(turretNum+1,h,p,t,CurrentHp,minHp);
                h[i]++;
                CurrentHp++;
            }
        }
        if(!shot){
            recur(turretNum+1,h,p,t,CurrentHp,minHp);
        }
    }else{
        minHp = min(CurrentHp,minHp);
        return;
    }
}

int main()
{
    cin >> n >> m >> k >> w;
    vector<int> p(m);
    vector<int> h(m);
    vector<int> t(k);
    vector<bool> used(k,false);
    int CurrentHp = 0;
    int minHp = 1e9;
    for (size_t i = 0; i < m; i++)
    {
        cin >> p[i];
    }
    for (size_t i = 0; i < m; i++)
    {
        cin >> h[i];
        CurrentHp += h[i];
    }
    for (size_t i = 0; i < k; i++)
    {
        cin >> t[i];
    }
    recur(0,h,p,t,CurrentHp,minHp);
    cout<< minHp;
    /*
10 1 2 1
1
10
2 5


    */
}