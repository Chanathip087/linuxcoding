#include <iostream>
#include <vector>
using namespace std;

int n;
int k;
vector <int> skill_l;

void update(int i, int v) {
    skill_l[i] = v;
}
void Query(int l, int r) {
    int max_skill = 0;
    for (int i = l; i <= r; i++) {
        if (skill_l[i] > max_skill) {
            max_skill = skill_l[i];
        }
    }
    cout << max_skill << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;

    skill_l.push_back(0); 

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        skill_l.push_back(x);
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
