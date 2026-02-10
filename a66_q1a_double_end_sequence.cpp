#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// กำหนดค่า Infinity ให้มากพอ
const long long INF = 1e18;

int main() {
    // เพิ่มความเร็วในการรับส่งข้อมูล
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // สร้าง array เก็บค่า min_prefix ของแต่ละเลข
    // โจทย์บอกเลขอยู่ระหว่าง -999 ถึง 999 
    // เราใช้ Offset 1000 เพื่อ mapping ลง array (0 ถึง 1999)
    vector<long long> min_prefix(2500, INF);
    
    long long current_prefix_sum = 0;
    long long max_sum = -INF; // เริ่มต้นด้วยค่าต่ำสุดๆ

    for (int i = 0; i < n; i++) {
        int val = A[i];
        int mapped_val = val + 1000; // แปลง index ให้เป็นบวก
        
        long long prev_prefix_sum = current_prefix_sum; // P[i-1]
        current_prefix_sum += val; // P[i]

        // 1. อัปเดตค่า Min Prefix ของเลขนี้ก่อน
        // สาเหตุที่ต้องทำก่อนคำนวณ max_sum เพื่อรองรับกรณี Sequence มีตัวเดียว (p == q)
        if (prev_prefix_sum < min_prefix[mapped_val]) {
            min_prefix[mapped_val] = prev_prefix_sum;
        }

        // 2. คำนวณผลรวมที่เป็นไปได้สูงสุด ณ จุดนี้
        if (min_prefix[mapped_val] != INF) {
            long long current_double_end_sum = current_prefix_sum - min_prefix[mapped_val];
            if (current_double_end_sum > max_sum) {
                max_sum = current_double_end_sum;
            }
        }
    }

    cout << max_sum << endl;

    return 0;
}