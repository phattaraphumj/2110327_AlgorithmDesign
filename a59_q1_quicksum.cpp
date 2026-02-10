#include <bits/stdc++.h>
using namespace std;

int sum(int r1, int c1, int r2, int c2,vector<vector<int>> &p)
{
    if (r1 < 0 || c1 < 0)
        return 0;
    return p[r2][c2]- p[r1 - 1][ c2]- p[r2][c1 - 1] + p[r1 - 1][ c1 - 1];
}

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> A(N, vector<int>(M));
    vector<vector<int>> p(N, vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> A[i][j];
        }
    }
    p[0][0] = A[0][0];
    for(int j = 1;j<M-1;j++){
        p[0][j] = p[0][j-1] + A[0][j];
    }
    for(int i = 1;i<N-1;i++){
        p[i][0] = p[i-1][0] + A[i][0];
        for (int j = 1;j<M-1;j++){
            p[i][j] = p[i-1][j] + p[i][j-1]-p[i-1][j-1] + A[i][j];
        }
    }

    for(int i = 0;i<K;i++)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout<< sum(r1,c1,r2,c2,p) << endl;
    }
}