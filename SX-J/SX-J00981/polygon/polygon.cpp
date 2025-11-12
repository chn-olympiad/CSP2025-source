#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
long long a[N], ans, n, path[N];
bool used[N];

void pr(long long k) {
	long long s = 0, maxn = -1;
	for (int i = 1; i <= k; i++) {
		s += path[i];
		maxn = max(maxn, path[i]);
	}
	maxn = maxn * 2;
	if (s > maxn) {
		ans++;
	}
}

void dfs(long long k, long long m, long long l) {
	if (k > m) {
		pr(m);
		return;
	}
	for (int i = l; i <= n; i++) {
		if (used[i] == 0) {
			used[i] = 1;
			path[k] = a[i];
			dfs(k + 1, m, i + 1);
			used[i] = 0;
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
	sort(a + 1, a + n + 1);
	for (int i = 3; i <= n; i++) {
		dfs(1, i, 1);
	}
	cout << ans;
	return  0;
}
