#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    while (k--) {
        int type;
        cin >> type;

        if (type == 1) {
            int i, R, P;
            cin >> i >> R >> P;
            int start = max(1, i - R);
            int end = min(n, i + R);
            for (int j = start; j <= end; j++) {
                a[j] += P;
            }
        }
        else if (type == 2) {
            int L, Y;
            cin >> L >> Y;
            int max_energy = -1;
            int best_pos = -1;
            for (int i = L; i <= Y; i++) {
                if (a[i] > max_energy) {
                    max_energy = a[i];
                    best_pos = i;
                }
            }
            cout << best_pos << " " << max_energy << endl;
        }
    }
    return 0;
}