#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    while (m--) {

        int type;
        cin >> type;

        if (type == 1) {
            int i, v = 0;
            cin >> i >> v;
            a[i] = v;
        }
        else if (type == 2) {
            int L, R, k;
            cin >> L >> R >> k;

            int min_diff = 2e9;
            int best_skill = 2e9;

            for (int i = L; i <= R; i++) {

                int current_skill = a[i];
                int diff = abs(current_skill - k);

                if (diff < min_diff) {
                    min_diff = diff;
                    best_skill = current_skill;
                }
                else if (diff == min_diff) {
                    if (current_skill < best_skill) {
                        best_skill = current_skill;
                    }
                }
            }
            cout << best_skill << "\n";
        }
    }
    return 0;
}