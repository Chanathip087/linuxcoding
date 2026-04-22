#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Rod 
{
    int a, l, b, r;
};

int n;
vector<Rod> rods;

long long max_required_W = 0;
long long total_initial_W = 0;

void dfs(int u, int depth) {
    if (rods[u].a == 1) {
        long long weight = rods[u].l;
        total_initial_W += weight;

        long long required_W = weight * (1LL << (depth + 1));
        max_required_W = max(max_required_W, required_W);
    }else {
        dfs(rods[u].l, depth + 1);
    }
    
    if (rods[u].b == 1) {
        long long weight = rods[u].r;
        total_initial_W += weight;

        long long required_W = weight * (1LL << (depth + 1));
        max_required_W = max(max_required_W, required_W);
    }else {
        dfs(rods[u].r, depth + 1);
    }
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n)) return 0;

    rods.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> rods[i].a >> rods[i].l >> rods[i].b >> rods[i].r;
    }

    dfs(1, 0);

    cout << max_required_W - total_initial_W << "\n";

    return 0;
}
