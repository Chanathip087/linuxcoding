#include <bits/stdc++.h>
using namespace std;

struct Event {
    int pos;
    int type;

    bool operator<(const Event& other) const {
        if (pos != other.pos) return pos < other.pos;
        return type > other.type;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;

    vector<Event> events;
    for(int i = 0; i < m; i++) {
        int s, t; cin >> s >> t;
        events.push_back({s, 1});
        events.push_back({t, -1});
    }

    sort(events.begin(), events.end());

    int max_overlap = 0;
    int current_overlap = 0;

    for (auto &e : events) {
        current_overlap += e.type;
        if (current_overlap > max_overlap) {
            max_overlap = current_overlap;
        }
    }

    cout << max_overlap << "\n";

    return 0;
}