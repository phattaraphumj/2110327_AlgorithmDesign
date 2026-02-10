#include <bits/stdc++.h>
using namespace std;

int get_sum(vector<int> &S,int a,int b){
    if(a==0)return S[b];
    return S[b] - S[a-1];
}

int mss(vector<int> &A,int start,int stop,vector<int> &S){
    if (start == stop)return A[start];
    int m = (start+stop) / 2;
    int r1 = mss(A,start,m,S);
    int r2 = mss(A,m+1,stop,S);
    // #find max of B[start..m][m]
    int max_sum_left = get_sum(S,m,m);
    for(int i = start;i<=m-1;i++){
        max_sum_left = max(max_sum_left,get_sum(S,i,m));
    }
    // #find max of B[m+1..stop][stop]
    int max_sum_right = get_sum(S,m+1,m+1);
    for(int j = m+2;j<=stop;j++){
        max_sum_right = max(max_sum_right,get_sum(S,m+1,j));
    }
    int r3 = max_sum_left + max_sum_right;
    return max({r1,r2,r3});
}

int find_max(vector<vector<int>> &ans,vector<vector<int>> &S){
    int MAX = -1e9;
    for(auto v:ans){ // v = vector<int>
        MAX = max(mss(v,0,v.size()-1,v),MAX);
    }
    return MAX;
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> v(N, vector<int>(N, 0));
    vector<vector<int>> S(N, vector<int>(N, 0));
    vector<vector<int>> ans;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> v[i][j];
        }
    }

    int i = 0;
    for (int j = 0; j < N; j++)
    {
        int sum = 0;
        vector<int> tmp;
        for (int k = 0; k < N; k++)
        {
            if (i + k >= N || j + k >= N)
                break;
            sum += v[i + k][j + k];
            S[i + k][j + k] = sum;
            tmp.push_back(sum);
        }
        ans.push_back(tmp);
    }

    int j = 0;
    for (int i = 1; i < N; i++)
    {
        int sum = 0;
        vector<int> tmp;
        for (int k = 0; k < N; k++)
        {
            if (i + k >= N || j + k >= N)
                break;
            sum += v[i + k][j + k];
            S[i + k][j + k] = sum;
            tmp.push_back(sum);
        }
        ans.push_back(tmp);
    }
    cout << find_max(ans,ans);

    //
    // for (auto i : S)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // for (auto i : ans)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
}