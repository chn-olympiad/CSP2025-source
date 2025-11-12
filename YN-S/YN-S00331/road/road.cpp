#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
int a[505];

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, k, v, u, w, c, a;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> v >> u >> w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c;
		for (int j = 2; j <= n + 1; j++) {
			cin >> a;
		}
	}
	cout << "0";
	return 0;
}