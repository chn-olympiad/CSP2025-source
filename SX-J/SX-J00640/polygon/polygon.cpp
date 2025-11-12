#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10, M = 998244353;
long long n, a[N], m, path[N], vis[N], maxn, cnt;

void dfs(long long k, long long sum, long long last) {
	if (k > m) {
		if ( sum / maxn >= 2) {
			cnt = (cnt + 1) % M;
		}
		return;
	}
	for (int i = last + 1; i <= n; i++) {
		if (vis[i] == 0) {
			if (a[i] > maxn) {
				maxn = a[i];
			}
			path[k] = a[i];
			vis[i] = 1;
			dfs(k + 1, sum + a[i], i);
			vis[i] = 0;
		}
	}
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 3; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		m = i;
		maxn = 0;
		dfs(1, 0, 0);
		vis[i] = 0;
	}
	cout << cnt - 2;
	return 0;
}