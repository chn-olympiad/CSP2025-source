#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int c[1010], p[1010], f[1010];
string s;
int n, m, ans = 0;
void Dfs(int u) {
	if (u == n + 1) {
		int k = 0, cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i - 1] == '0' || k >= c[p[i]]) {
				k++; continue;
			}
			k = 0; cnt++;
		}
		if (cnt >= m) ans = (ans + 1) % mod;
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (f[i]) continue;
		f[i] = 1;
		p[u] = i;
		Dfs(u + 1);
		f[i] = 0;
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cin >> s;
	int flg = 1;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			flg = 0;
			break;
		}
	}
	for (int i = 1; i <= n; i++) cin >> c[i];
	if (n <= 18) {
		Dfs(1);
		printf("%lld\n", ans);
		return 0;
	}
	if (flg) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) if (c[i] == 0) cnt++;
		if (n - cnt < m) {
			cout << 0;
			return 0;
		}
		long long Ans = 1;
		for (int i = 2; i <= n; i++) {
			Ans = (ans * i) % mod;
		}
		printf("%lld\n", Ans);
		return 0;
	}
	return 0;
}
//Use the light of Young, Light up the Life
//Use anything you have, to prove "Nothing is Impossible"
//Victory