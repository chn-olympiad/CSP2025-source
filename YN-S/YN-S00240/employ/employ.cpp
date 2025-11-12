#include <bits/stdc++.h>
#define int long long
#define MOD 998244353
using namespace std;
int n, m;
string s;
int c[505];
bool vis[505];

int dfs(int step, int cnt) {
	if (n - step + cnt + 1 < m) {
		return 0;
	}
	if (step == n + 1) {
		return 1;
	}
	int ccnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (vis[i])
			continue;
		vis[i] = 1;
		int f = s[step - 1] - '0';
		if (c[i] <= step - cnt - 1) {
			f = 0;
		}
		ccnt += dfs(step + 1, cnt + f) % MOD;
		ccnt %= MOD;
		vis[i] = 0;
	}
	return ccnt;
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	cin >> s;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &c[i]);
	}
	printf("%lld", dfs(1, 0));
	return 0;
}