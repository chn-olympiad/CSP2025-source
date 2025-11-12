#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 500, MOD = 998244353;

int n, m;
string s;
int c[MAX_N + 1];
bitset<MAX_N + 1> vis;
int p[MAX_N + 1];
int ans = 0;

void dfs(int idx) {
	if (idx == n + 1) {
		int cnt1 = 0, cnt2 = 0;
		for (int i = 1; i <= n; ++i) {
			if (s[i] == '0') ++cnt2;
			else if (cnt2 < c[p[i]]) ++cnt1;
			else ++cnt2;
		}
		if (cnt1 >= m) ++ans;
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue;
		vis[i] = 1;
		p[idx] = i;
		dfs(idx + 1);
		vis[i] = 0;
	}
}

int main() {
	freopen("empoly.in", "r", stdin);
	freopen("empoly.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; ++i) cin >> c[i];
	dfs(1);
	cout << ans << "\n";
	return 0;
}
