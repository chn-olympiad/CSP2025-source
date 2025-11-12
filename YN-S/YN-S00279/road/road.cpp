#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, a, b, c;
	int sum = 0;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		sum += c;
	}
	int s;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n + 1; j++) {
			cin >> s;
		}
	}
	cout << sum;
	return 0;
}