#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // ช่วยให้ทำงานเร็วขึ้น
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }

    // 1. เรียง X จากน้อยไปมาก
    sort(v.begin(), v.end());

    int count = 0;
    int maxYSoFar = -1; // เก็บค่า Y ที่สูงที่สุดที่เจอจากทางขวา

    // 2. วนจากขวามาซ้าย (จากคนที่มี X มาก ไปหาคนที่มี X น้อย)
    for (int i = N - 1; i >= 0; i--) {
        // ถ้าค่า Y ของจุดปัจจุบัน สูงกว่า Y ทุกตัวทางขวาที่ผ่านมา
        // แสดงว่าไม่มีใครทางขวาครอบงำมันได้ (เพราะ X มันก็น้อยลงเรื่อยๆ อยู่แล้ว)
        if (v[i].second > maxYSoFar) {
            count++;
            maxYSoFar = v[i].second; // อัปเดตกำแพงความสูง Y
        }
    }

    cout << count << endl;
    return 0;
}