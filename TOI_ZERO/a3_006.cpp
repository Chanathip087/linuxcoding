#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> dis(n);
    for(int i = 0; i < n; i++) {
        cin >> dis[i];
    }
    sort(dis.begin(), dis.end(), greater<int>());

    long long total_energy = 0;
    for(int i = 0; i < n; i++) {
        long long drone_id = (i / 10) + 1;

        if (i % 10 == 0) {   
            total_energy += drone_id * 1 * dis[i];
        }else {
            total_energy += drone_id * 2 * dis[i];
        }
    }

    cout << total_energy << endl;
    return 0;
}