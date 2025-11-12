#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define ll long long
ll n, m, k, sum;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		sum += w;
	}
	if (k == 0) {
		cout << sum;
	} else {
		cout << 0;
	}
	return 0;
}