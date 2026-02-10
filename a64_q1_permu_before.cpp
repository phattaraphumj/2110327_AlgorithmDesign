#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void perm(int n, vector<int> &sol, int len, vector<bool> &used,vector<pair<int,int>> &order)
{
    if (len < n)
    {
        for (int i = 0; i < n; i++)
        {
            bool interupt = false;
            for(auto &[f,s]:order){
                if(i == s && !used[f]){
                    interupt = true;
                    break;
                }
            }
            if(interupt)continue;;
            if(used[i] == false){
                used[i] = true;
                sol[len] = i;
                perm(n,sol,len+1,used,order);
                used[i] = false;            
            }
        }
    }
    else
    {
        for (auto &x : sol)
            cout << x << " ";
        cout << endl;
    }
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    vector<bool> used(n,false);
    vector<pair<int,int>> order(m);
    for (size_t i = 0; i < m; i++)
    {
        cin >> order[i].first >> order[i].second;
    }
    perm(n,v,0,used,order);
    /*
3 2
1 2
0 1 

3 2
2 1
1 0
    */
}