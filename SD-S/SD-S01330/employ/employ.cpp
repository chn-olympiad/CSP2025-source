#include<bits/stdc++.h>
using namespace std;

const int N = 500 + 10;
const int MOD = 998244353;
int INT_INF = 0x3f3f3f3f;
long long LL_INF = 0x3f3f3f3f3f3f3f3f;
// ---------------------------

// ---------------------------
bool vis[N];
int c[N], a[N], ans = 0;
// ---------------------------
void dfs(int u, string s, int n, int m) {
	if (u > n) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0' || cnt >= a[i + 1]) cnt++;
		}
		if (n - cnt >= m) ans++;
		ans %= MOD;
		return;
	}
	
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		vis[i] = true;
		a[u] = c[i];
		dfs(u + 1, s, n, m);
		vis[i] = false;
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m; cin >> n >> m;
	string s; cin >> s;
	for (int i = 1; i <= n; i++) cin >> c[i];
	// ---------------------------
	dfs(1, s, n, m);
	// ---------------------------
	cout << ans << '\n';
	return 0;
}

