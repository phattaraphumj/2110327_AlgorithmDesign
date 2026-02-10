#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n, m;
ll k;
vector<ll> qs_grass;
vector<ll> qs_cost;

// ฟังก์ชันตรวจสอบค่าใช้จ่ายในช่วง [start, end] ว่าเกิน budget หรือไม่
// ใช้ Prefix Sum ช่วยให้เช็คได้ใน O(1)
bool can_afford(int start, int end, ll budget) {
    if (end < start) return true; // กรณีไม่ได้ตัดเลย
    ll cost = qs_cost[end] - qs_cost[start - 1];
    return cost <= budget;
}

// ฟังก์ชัน Divide and Conquer (Recursive Binary Search)
// ค้นหาตำแหน่ง 'end' ที่ไกลที่สุด ในช่วง [L, R] ที่งบยังพอจ่าย
int find_max_r(int L, int R, int start_origin, ll budget) {
    // Base Case: ถ้าช่วงค้นหาหมดแล้ว
    if (L > R) {
        return R; // คืนค่า R ซึ่งจะเป็นตำแหน่งล่าสุดที่เป็นไปได้ (valid)
    }

    int mid = L + (R - L) / 2;

    // Conquer: เช็คตรงกลาง
    if (can_afford(start_origin, mid, budget)) {
        // ถ้าตรงกลางเงินพอจ่าย แปลว่าเราอาจจะไปได้ไกลกว่านี้
        // ให้เก็บค่า mid นี้ไว้ในใจ แล้วลองไปค้นหาต่อในฝั่งขวา (Divide Right)
        // สังเกตว่าเรา return ผลจากฝั่งขวา เพราะเราต้องการค่ามากที่สุด
        return find_max_r(mid + 1, R, start_origin, budget);
    } else {
        // ถ้าตรงกลางเงินไม่พอ แปลว่าเรามาไกลเกินไป
        // ต้องถอยกลับไปค้นหาในฝั่งซ้าย (Divide Left)
        return find_max_r(L, mid - 1, start_origin, budget);
    }
}

int main() {
    // เร่งความเร็ว I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m >> k)) return 0;

    // เตรียม Prefix Sum (ขนาด n+1 เพื่อให้ index เริ่มที่ 1 ง่ายต่อการคำนวณ)
    qs_grass.resize(n + 1, 0);
    qs_cost.resize(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        ll grass;
        cin >> grass;
        // Prefix Sum ของปริมาณหญ้า
        qs_grass[i] = qs_grass[i - 1] + grass;
        // Prefix Sum ของราคา (ค่าหญ้า + ค่าแรง k)
        qs_cost[i] = qs_cost[i - 1] + (grass + k);
    }

    // Process แต่ละคำถาม
    for (int i = 0; i < m; i++) {
        int start_idx;
        ll budget;
        cin >> start_idx >> budget;

        // start_idx ในโจทย์เริ่มที่ 0 แต่ Prefix sum เราเริ่มที่ 1
        // ดังนั้นจุดเริ่มต้นจริงคือ start_idx + 1
        int actual_start = start_idx + 1;

        // เรียกใช้ฟังก์ชัน Divide and Conquer เพื่อหาจุดจบ (r) ที่ดีที่สุด
        // ค้นหาตั้งแต่จุดเริ่มต้น (actual_start) ไปจนถึงท้ายสนาม (n)
        int best_end = find_max_r(actual_start, n, actual_start, budget);

        // คำนวณปริมาณหญ้าที่ได้จากช่วงที่ดีที่สุด
        // ถ้า best_end < actual_start แปลว่าตัดไม่ได้เลยสักช่อง
        if (best_end < actual_start) {
            cout << "0\n";
        } else {
            ll total_grass = qs_grass[best_end] - qs_grass[actual_start - 1];
            cout << total_grass << "\n";
        }
    }

    return 0;
}