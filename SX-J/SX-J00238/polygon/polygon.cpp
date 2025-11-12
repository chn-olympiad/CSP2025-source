#include <bits/stdc++.h>
using namespace std;
int n;
long long cnt = 0, sum = 0;
int a[5005], b[5005], vis[5005];

void dfs(int k, int s) {
	int h = 0, maxx = 0;
	if (k == s + 1) {

		for (int i = 1; i <= k - 1; i++) {
			h += a[b[i]];
			maxx = max(maxx, a[b[i]]);
		}
		if (h > maxx * 2) {
			cnt++;
			return;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			b[k] = i;
			vis[i] = 1;
			dfs(k + 1, s);
			b[k] = 0;
			vis[i] = 0;
		} else {
			continue;
		}
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 3; i <= n; i++) {
		cnt = 0;
		dfs(1, i);
		cnt /= (i - 1) * i;
		cout << cnt;
		sum += cnt;
	}
	cout << sum	% 998244353;;

	return 0;
}
