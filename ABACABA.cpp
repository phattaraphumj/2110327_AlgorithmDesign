#include <iostream>
#include <cmath>

using namespace std;

char solve(long long n) {
    // หาตำแหน่งของบิตที่เป็น 1 ตัวสุดท้าย (Rightmost set bit)
    // เพราะโครงสร้าง ABACABA สัมพันธ์กับเลขฐานสอง
    // n=1 (001) -> A, n=2 (010) -> B, n=3 (011) -> A, n=4 (100) -> C
    
    int count = 0;
    while (n % 2 == 0) {
        n /= 2;
        count++;
    }
    
    // คืนค่าตัวอักษรโดยใช้ % 26 เพื่อวนลูป A-Z
    return (char)('A' + (count % 26));
}

int main() {
    long long n;
    if (!(cin >> n)) return 0;
    
    cout << solve(n) << endl;
    return 0;
}