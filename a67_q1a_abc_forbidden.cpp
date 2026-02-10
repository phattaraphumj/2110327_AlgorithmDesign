#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ตัวแปร Global สำหรับเก็บค่าจากโจทย์
int N, limitA, limitB, limitC; // จำนวน N และโควตา i, j, k
int M;
bool bad[3][3]; // ตารางเก็บคู่ต้องห้าม (0=A, 1=B, 2=C)
vector<string> ans_list; // เก็บคำตอบทั้งหมดไว้ก่อน (เพราะโจทย์ให้พิมพ์จำนวนบรรทัดก่อน)

// ฟังก์ชันแปลงตัวอักษรเป็นตัวเลข (A=0, B=1, C=2) เพื่อใช้เช็คตาราง bad
int toInt(char c) {
    if (c == 'A') return 0;
    if (c == 'B') return 1;
    return 2;
}

// ฟังก์ชันแปลงเลขเป็นตัวอักษร
char toChar(int i) {
    if (i == 0) return 'A';
    if (i == 1) return 'B';
    return 'C';
}

// sol: เก็บผลลัพธ์ปัจจุบัน
// len: ความยาวปัจจุบัน
// ca, cb, cc: จำนวน A, B, C ที่ใช้ไปแล้ว
void perm(vector<char> &sol, int len, int ca, int cb, int cc) {
    // เงื่อนไขจบ (Base Case)
    if (len < N) {
        // วนลูป 3 รอบ แทน A, B, C (0, 1, 2)
        for (int i = 0; i < 3; i++) {
            char currentChar = toChar(i);
            
            // 1. เช็คโควตา (แทนการเช็ค used[i] == false)
            bool canUse = false;
            if (i == 0 && ca < limitA) canUse = true;
            else if (i == 1 && cb < limitB) canUse = true;
            else if (i == 2 && cc < limitC) canUse = true;

            if (canUse) {
                // 2. เช็คคู่ต้องห้าม (Forbidden)
                // ถ้าไม่ใช่ตัวแรก (len > 0) ให้เช็คกับตัวก่อนหน้า (sol[len-1])
                if (len > 0) {
                    int prevCharIdx = toInt(sol[len-1]);
                    if (bad[prevCharIdx][i]) {
                        continue; // ถ้าเป็นคู่ต้องห้าม ให้ข้ามรอบนี้ไปเลย
                    }
                }

                // ทำเหมือนโค้ดเดิมของคุณ
                sol[len] = currentChar; 
                
                // เรียก Recursive โดยเพิ่มจำนวนตัวที่ใช้ไป
                if (i == 0) perm(sol, len + 1, ca + 1, cb, cc);
                else if (i == 1) perm(sol, len + 1, ca, cb + 1, cc);
                else perm(sol, len + 1, ca, cb, cc + 1);
                
                // Backtracking: ในกรณีนี้ไม่ต้องเขียน used[i] = false 
                // เพราะเราส่งค่า ca, cb, cc ผ่าน function argument แทน
            }
        }
    } else {
        // เมื่อครบ N ตัวแล้ว ให้เก็บคำตอบใส่ vector ไว้ก่อน
        string s = "";
        for (int i = 0; i < N; i++) s += sol[i];
        ans_list.push_back(s);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    // รับค่า
    cin >> N >> limitA >> limitB >> limitC;
    cin >> M;

    // รับคู่ต้องห้าม
    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        bad[toInt(s[0])][toInt(s[1])] = true;
    }

    // เตรียมตัวแปรสำหรับเรียกฟังก์ชัน
    vector<char> sol(N); // จองที่ไว้ N ตัวเหมือนเดิม
    
    // เรียกฟังก์ชัน (เริ่มที่ len=0, และใช้ A,B,C ไปแล้ว 0 ตัว)
    perm(sol, 0, 0, 0, 0);

    // แสดงผล
    cout << ans_list.size() << "\n"; // พิมพ์จำนวนคำตอบก่อน
    for (string s : ans_list) {
        cout << s << "\n";
    }

    return 0;
}