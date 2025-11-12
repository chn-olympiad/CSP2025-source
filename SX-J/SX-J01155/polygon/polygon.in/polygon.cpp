#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, i, m;
	cin >> n >> m;
	int n[5000];
	for (int i = 3; 1 <= m; i++) {
		cin >> n[i];
	}
	if (m >= 3 && (n + 3) / 2 > 2 * n) {
		m > 2 * i;
	}
	if (n >= 3) {
		i++;
	}
	cout << n[i];
	retur 0;
}
