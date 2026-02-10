#include <bits/stdc++.h>
using namespace std;

int c = 0;

template <typename T>
void merge(vector<T> &v, int start, int m, int stop, vector<T> &tmp)
{
    int bi = start; // index of B
    int ci = m + 1; // index of C
    for (int i = start; i <= stop; i++)
    {
        if (ci > stop)
        {
            tmp[i] = v[bi++];
            continue;
        }
        if (bi > m)
        {
            tmp[i] = v[ci++];
            continue;
        }
        if(v[bi] <= v[ci]){
            tmp[i] =  v[bi++];
        }else{
            tmp[i] = v[ci++];
            c+= m-bi+1;
        }
    }
    for (int i = start; i <= stop; i++)
        v[i] = tmp[i];
}
template <typename T>
void merge_sort(vector<T> &v, int start, int stop, vector<T> &tmp)
{
    if (start < stop)
    {
        int m = (start + stop) >> 1;
        merge_sort(v, start, m, tmp);
        merge_sort(v, m + 1, stop, tmp);
        merge(v, start, m, stop, tmp);
    }
}

int main()
{
    int N;
    cin >> N;
    vector<int> v(N);
    vector<int> tmp(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    merge_sort(v,0,N-1,tmp);
    cout << c;
}