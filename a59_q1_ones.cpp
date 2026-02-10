#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// ฟังก์ชันสร้างเลข 1 ล้วน (Repunit)
// เช่น len=3 -> return 111
long long get_rep(int len) {
    long long res = 0;
    for (int i = 0; i < len; i++) res = res * 10 + 1;
    return res;
}

// ฟังก์ชันหาคำตอบ (ไม่มี memo)
long long solve(long long n, int len) {
    // Base Case: ถ้าเศษเป็น 0 ไม่ต้องบวกอะไรเพิ่มแล้ว
    if (n == 0) return 0;
    
    // Base Case: ถ้าความยาวเป็น 0 (ต่ำกว่าหลักหน่วย) คืนค่า Infinity ไปเลย (ทางตัน)
    if (len == 0) return 2e9; 

    long long rep = get_rep(len);
    long long m = n / rep;      // จำนวนเท่า (Quotient)
    long long r = n % rep;      // เศษ (Remainder)

    // ทางเลือกที่ 1: เอาแบบไม่เกิน (Floor)
    // ใช้ m ตัว แล้วแก้ปัญหาเศษ r ในระดับถัดไป (len-1)
    long long cost1 = (m * len) + solve(r, len - 1);

    // ทางเลือกที่ 2: เอาแบบเกินไป 1 ตัว (Ceil) แล้วลบออก
    // ใช้ m+1 ตัว แล้วแก้ปัญหาส่วนต่าง (rep - r) ในระดับถัดไป
    // เช่น อยากได้ 7 (len=2, rep=11) -> 7/11 ได้ 0 เศษ 7
    // ทางนี้คือใช้ 11 หนึ่งตัว (m+1) แล้วแก้ส่วนต่าง (11-7 = 4)
    long long cost2 = ((m + 1) * len) + solve(rep - r, len - 1);

    // เลือกทางที่ใช้น้อยที่สุด
    return min(cost1, cost2);
}

int main() {
    long long N;
    while (cin >> N) {
        // เริ่มต้นที่ len = 11 หรือ 12 ก็พอสำหรับ 10^9
        // (เพราะ 11,111,111,111 มันเกินพันล้านไปแล้ว ครอบคลุมแน่นอน)
        cout << solve(abs(N), 12) << endl;
    }
    return 0;
}