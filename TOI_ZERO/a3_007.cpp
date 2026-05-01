#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long L, N;
    cin >> L >> N;

    for (long long k = 1; k <= N; k++) {
        long long S = k * L;
        long long area = S * (S + 1) / 2;
        if (area >= N) {
            cout << k << "\n";
            break;
        }
    }
    return 0;
    
}
