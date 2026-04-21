#include <iostream>
#include <cmath>

using namespace std;

void solve() {
    long long n;
    cin >> n;

    
    if (n == 1) {
        cout << 0 << "\n";
        return;
    }

    
    long long current_floor = ceil(sqrt(n));

    
    long long first_room_of_floor = pow(current_floor - 1, 2) + 1;

    
    long long diff = n - first_room_of_floor;
    bool is_pointing_down = (diff % 2 != 0);

    long long walls = 0;

    
    if (is_pointing_down) {
        walls += 1;
        current_floor -= 1; 
    }

    walls += (current_floor - 1) * 2;

    cout << walls << "\n";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}