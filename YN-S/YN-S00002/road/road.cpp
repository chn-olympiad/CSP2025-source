#include <bits/stdc++.h>
using namespace std;

int n, m, k, a[N];

int main() {
	freopen("road.in", "r", stdin);
	froepen("road.out", "w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> a[i];
	}
	
	for (int i = 1; i <= k; i++) {
		int x;
		cin >> x;
	}
	
	sort(a + 1, a + 1 + m);
	int sum = 0;
	for (int i = 1; i <= n - 1; i++) sum += a[i];
	cout << sum;
	
	return 0;
}
