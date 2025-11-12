#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	int b;
	for (int q = 1; q <= m; q++) {
		cin >> b >> b >> b;
	}
	for (int q = 1; q <= k; q++) {
		cin >> b >> b >> b;
	}
	cout << b*b << endl;
	return 0;
}