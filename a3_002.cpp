#include <iostream>
#include <cmath>

using namespace std;

void solve() {
    long long n;
    cin >> n;

    // ถ้าอยู่ที่ห้อง 1 อยู่แล้ว ไม่ต้องพังกำแพง
    if (n == 1) {
        cout << 0 << "\n";
        return;
    }

    // 1. หาว่าอยู่ชั้นที่เท่าไหร่ (ถอดรูทปัดขึ้น)
    long long current_floor = ceil(sqrt(n));

    // 2. หาว่าห้องแรกสุดฝั่งซ้ายของชั้นนี้คือหมายเลขอะไร
    // (เอาชั้นก่อนหน้ามายกกำลังสอง แล้วบวก 1)
    long long first_room_of_floor = pow(current_floor - 1, 2) + 1;

    // 3. เช็คว่าเป็นห้องชี้ขึ้น (▲) หรือ ชี้ลง (▼)
    // ห้องแรกจะเป็นชี้ขึ้นเสมอ (ส่วนต่างเป็น 0) ถ้าส่วนต่างเป็นเลขคี่จะเป็นชี้ลง
    long long diff = n - first_room_of_floor;
    bool is_pointing_down = (diff % 2 != 0);

    long long walls = 0;

    // 4. คำนวณจำนวนกำแพงที่ต้องพัง
    if (is_pointing_down) {
        // ถ้าเป็นห้องชี้ลง พัง 1 กำแพงเพื่อขึ้นชั้นบน จะกลายเป็นห้องชี้ขึ้นเสมอ
        walls += 1;
        current_floor -= 1; 
    }

    // ตอนนี้สถานะของเราคืออยู่ "ห้องชี้ขึ้น" เสมอแล้ว
    // จากชั้นปัจจุบัน ขึ้นไปถึงชั้น 1 จะใช้ 2 กำแพงต่อ 1 ชั้น
    walls += (current_floor - 1) * 2;

    cout << walls << "\n";
}

int main() {
    // ปรับความเร็ว I/O ของ C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}