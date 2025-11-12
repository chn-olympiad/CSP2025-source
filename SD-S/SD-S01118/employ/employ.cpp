#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 510, Mod = 998244353;
int n, p[N], c[N], ans, m;
char s[N];
bool vis[N];

void dfs(int u) {
	if (u == n + 1) {
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '1' && i - 1 - sum < p[c[i]])
				sum++;
		}
		ans += sum >= m;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		vis[i] = true;
		c[u] = i;
		dfs(u + 1);
		vis[i] = false;
	}
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	dfs(1);
	cout << ans << "\n";
	return 0;
}


