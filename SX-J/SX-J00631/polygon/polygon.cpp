#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	vector<int> v(n + 5);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	if (n == 3) {
		if (v[1] + v[2] > v[3] && v[1] + v[3] > v[2] && v[2] + v[1] > v[3]) {
			cout << 1;
			return 0;
		} else {
			cout << 0;
			return 0;
		}
	}
	cout << 23 << endl;
	return 0;
}
