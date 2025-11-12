#include <bits/stdc++.h>
using namespace std;
struct Node {
	long long u, v, w;
} road[1000005];
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> road[i].u >> road[i].v >> road[i].w;
	}
	long long ans = 0;
	for (int j = 1; j <= k; j++) {
		int t;
		cin >> t;
		long long sum = 0;
		for (int i = 1; i <= n; i++) {
			long long p;
			cin >> p;
			sum += p;
		}
		ans = max(sum, ans);
	}
	cout << ans;
	return 0;
}
//
