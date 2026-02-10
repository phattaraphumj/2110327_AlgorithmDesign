#include <bits/stdc++.h>
using namespace std;

struct p
{
    int x;
    int y;
};
int distance(p a, p b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
bool compareX(const p &a, const p &b)
{
    return a.x < b.x;
}
bool compareY(const p &a, const p &b)
{
    return a.y < b.y;
}

int stripClosest(vector<p> &strip, int d)
{
    int mindist = d;
    sort(strip.begin(), strip.end(), compareY);
    for (int i = 0; i < strip.size(); i++)
    {
        for (int j = i + 1; j < strip.size(); j++)
        {
            if ((strip[j].y - strip[i].y) * (strip[j].y - strip[i].y) >= mindist)
            {
                break;
            }
            mindist = min(mindist, distance(strip[i], strip[j]));
        }
    }
    return mindist;
}

int closest(vector<p> &v, int l, int r)
{
    int m = (l + r) / 2;
    if (r - l <= 1)
    {
        return 2e9; // หรือค่า Infinity อื่นๆ ห้ามคืน 0 เด็ดขาด
    }
    if (r - l == 2)
    {
        return distance(v[l], v[r - 1]);
    }
    int midx = v[m].x;

    int dl = closest(v, l, m);
    int dr = closest(v, m, r);
    int d = min(dl, dr);

    vector<p> strip;
    for (int i = l; i < r; i++)
    {
        if ((v[i].x - midx) * (v[i].x - midx) < d)
        {
            strip.push_back(v[i]);
        }
    }
    int stripdist = stripClosest(strip, d);
    return stripdist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // เพิ่มความเร็ว
    int N;
    cin >> N;
    vector<p> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i].x >> v[i].y;
    }
    sort(v.begin(), v.end(), compareX);
    cout << closest(v, 0, N);
}