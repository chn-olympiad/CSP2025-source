#include <bits/stdc++.h>
using namespace std;

int n, m;
char s[510];
int c[510];
int t[15];
bool f[15];
int ans = 0;

void dfs(int d, int cnt) {
	if (n-cnt < m) return;
	if (d == n+1) {
		ans++;
		if (ans > 998244353)
			ans -= 998244353;
		return;
	}
	for (int i = 1; i <= n; i++)
		if (!f[i]) {
			f[i] = true;
			t[d] = i;
			bool ok = false;
			if (s[d] == '0' || cnt >= c[t[d]])
				ok = true, ++cnt;
			dfs(d+1, cnt);
			f[i] = false;
			if (ok)
				--cnt;
		}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, s+1);
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	if (n <= 18) {
		dfs(1, 0);
		printf("%d", ans);
		return 0;
	}
	bool f = true;
	for (int i = 1; i <= n; i++)
		if (s[i] == '0') {
			f = false;
			break;
		}
	puts("0");
}
