#include <bits/stdc++.h>
using namespace std;

// ใช้ long long เพื่อป้องกัน overflow
struct p {
    long long x, y;
};

// คืนค่าระยะทางกำลังสอง
long long distSq(p a, p b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool compareX(const p &a, const p &b) {
    return a.x < b.x;
}

bool compareY(const p &a, const p &b) {
    return a.y < b.y;
}

long long stripClosest(vector<p> &strip, long long d) {
    long long min_d = d;
    sort(strip.begin(), strip.end(), compareY);

    for (int i = 0; i < strip.size(); ++i) {
        for (int j = i + 1; j < strip.size(); ++j) {
            // จุดแก้ที่ 3: ถ้าแกน Y ห่างเกินค่า min_d แล้ว ให้หยุดทันที (Optimization)
            if ((strip[j].y - strip[i].y) * (strip[j].y - strip[i].y) >= min_d) {
                break; 
            }
            min_d = min(min_d, distSq(strip[i], strip[j]));
        }
    }
    return min_d;
}

long long closest(vector<p> &v, int l, int r) {
    // จุดแก้ที่ 1: Base Case ถ้าจุดน้อยกว่าหรือเท่ากับ 3 ให้ Brute force
    if (r - l <= 3) {
        long long min_val = LLONG_MAX; // ค่า Infinity
        for (int i = l; i < r; ++i) {
            for (int j = i + 1; j < r; ++j) {
                min_val = min(min_val, distSq(v[i], v[j]));
            }
        }
        return min_val;
    }

    int m = (l + r) / 2;
    long long midx = v[m].x;

    long long dl = closest(v, l, m);
    long long dr = closest(v, m, r);
    long long d = min(dl, dr);

    vector<p> strip;
    // จุดแก้ที่ 2: เทียบระยะแกน X แบบกำลังสอง
    for (int i = l; i < r; i++) {
        long long dx = v[i].x - midx;
        if (dx * dx < d) { 
            strip.push_back(v[i]);
        }
    }

    return min(d, stripClosest(strip, d));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); // เพิ่มความเร็ว
    int N;
    if (!(cin >> N)) return 0;
    
    vector<p> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].x >> v[i].y;
    }
    
    sort(v.begin(), v.end(), compareX);
    cout << closest(v, 0, N) << endl;
    
    return 0;
}