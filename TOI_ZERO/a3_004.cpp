#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    
    vector<long long> U(n) , V(n);

    for (int i = 0; i < n; i++) {
        long long x, y; cin >> x >> y;
        U[i] = x + y;
        V[i] = x - y;
    }

    sort(U.begin(), U.end());
    sort(V.begin(), V.end());

    long long mid_u = U[n / 2];
    long long mid_v = V[n / 2];
    long long total_distance = 0;

    for (int i = 0; i < n; i++) {
        total_distance += abs(U[i] - mid_u) + abs(V[i] - mid_v);
    }

    cout << total_distance << "\n";

    return 0;
} 
