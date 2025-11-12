#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int p = 998244353;
int n, m, a[511];
char s[511];

inline void solve() {
	memset(a, 0, sizeof(a));
	scanf("%d%d%s", &n, &m, s + 1);
	int cnt = n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		if (s[i] == '0')
			--cnt;
	if (m == n) {
		for (int i = 1; i <= n; i++)
			if (s[i] == '0') {
				printf("0\n");
				return;
			}
		for (int i = 1; i <= n; i++)
			if (a[i] != 1) {
				printf("0\n");
				return;
			}
		ll cnt = 1;
		for (int i = 1; i <= n; i++)
			cnt *= i, cnt %= p;
		cnt %= p;
		printf("%lld\n", cnt);
		return;
	} 
	if (cnt < m) {
		printf("0\n");
		return;
	}
	ll ans = 1;
	for (int i = 1, j = cnt; i <= m; i++, j--)
		ans *= j, ans %= p;
	ans %= p;
	printf("%lld\n", ans);
	return;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	
	int test = 1;
	while (test--) {
		solve();
	}
}
