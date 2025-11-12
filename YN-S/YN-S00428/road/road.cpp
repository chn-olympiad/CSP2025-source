#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, sum = 0;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		sum += z;
	}
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		for (int i = 0; i < n; i++) {
			int y;
			cin >> y;
		}
	}
	cout << sum;
	return 0;
}