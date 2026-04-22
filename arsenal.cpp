#include <iostream>
#include <vector>
using namespace std;

int n;
int k;
vector <int> dmg;

void update(int i, int v) {
    dmg[i] = v;
}
void Query(int l, int r) {
    int max_dmg = 0;
    for (int i = l; i <= r; i++) {
        if (dmg[i] > max_dmg) {
            max_dmg = dmg[i];
        }
    }
    cout << max_dmg << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;

    dmg.push_back(0); 

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        dmg.push_back(x);
    }
    int q;
    for (int i = 0; i < k; i++) {
        cin >> q;
        if (q == 1) {
        int i, v;
        cin >> i >> v;
        update(i, v);
        } else if (q == 2) {
        int l, r;
        cin >> l >> r;
        Query(l, r);
        }
    }
    

    return 0;
}