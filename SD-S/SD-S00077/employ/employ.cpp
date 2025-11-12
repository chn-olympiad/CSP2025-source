#include <bits/stdc++.h>
using namespace std;
const int N = 510, mod = 998244353;
int n, m, c[N], a[N], f[N], ans;
char s[N];
void dfs (int now) {
	if (now > n) {
		int cnt = 0, res = 0;
		for (int i = 1; i <= n; ++i) {
			if (cnt >= c[a[i]] || s[i] == '0')
				++cnt;
			else
				++res;
		}
		if (res >= m)
			ans = (ans + 1) % mod; 
		return;
	}
	for (int i = 1; i <= n; ++i)
		if (!f[i])
			f[i] = 1, a[now] = i, dfs(now + 1), f[i] = 0;
}
int main () {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> (s + 1);
	for (int i = 1; i <= n; ++i)
		cin >> c[i];
	dfs(1), cout << ans;
	return 0;
}
