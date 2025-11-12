#include <bits/stdc++.h>
using namespace std;

int main () {
	freopen("road.out", "w", stdout);
	freopen("road.in", "r", stdin);
	int n, m, k;
	cin >> n >> m >> k;
	long long ans = 0;
	int a;
	for (int i = 1; i <= m; i++) {
		cin >> a;
		ans += a;
	}
	for (int i = 1; i <= k; i++) {
		for (int i = 1; i <= n + 1; i++) {
			cin >> a;
		}
	}
	cout << a << endl;
	return 0;
}