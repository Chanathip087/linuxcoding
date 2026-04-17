#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n ;
	if (!(cin >> n)) return 0;
	vector <int> v;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end(), greater<int>());
	cout << v.front() << "\n";
	cout << v.back() << "\n";
	return 0;
}
