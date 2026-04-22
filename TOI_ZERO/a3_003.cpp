#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // เพิ่มประสิทธิภาพการอ่านข้อมูล
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> pt1(n), pt2(n);
    for(int i = 0; i < n; i++) cin >> pt1[i];
    for(int i = 0; i < n; i++) cin >> pt2[i];

    int count = 0;
    int curr1 = 1; // จุดเริ่มต้นชั่วโมงแรกของสาย 1 คือจุด 1
    int curr2 = 1; // จุดเริ่มต้นชั่วโมงแรกของสาย 2 คือจุด 1

    for (int t = 0; t < n; t++) {
        int a = curr1;   // ต้นทางสาย 1
        int b = pt1[t];  // ปลายทางสาย 1
        int c = curr2;   // ต้นทางสาย 2
        int d = pt2[t];  // ปลายทางสาย 2

        // กรณีที่ 1: วิ่งเส้นทางเดียวกัน (ทับกัน)
        // เช่น สายหนึ่งวิ่ง 1->2 อีกสายก็วิ่ง 1->2 หรือวิ่งสวนกัน 2->1
        if ((a == c && b == d) || (a == d && b == c)) {
            count++;
        }
        else {
            // กรณีที่ 2: เส้นทางตัดกันเป็นคอร์ด (แบบที่คุยกันตอนแรก)
            int temp_a = a, temp_b = b;
            if (temp_a > temp_b) swap(temp_a, temp_b);

            bool c_inside = (c > temp_a && c < temp_b);
            bool d_inside = (d > temp_a && d < temp_b);

            if (c_inside != d_inside) {
                count++;
            }
        }

        // อัปเดตตำแหน่งปัจจุบันสำหรับชั่วโมงถัดไป
        curr1 = b;
        curr2 = d;
    }

    cout << count << "\n";

    return 0;
}