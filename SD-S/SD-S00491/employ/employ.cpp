#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 510, mod = 998244353;
char s[N];
int n, m, c[N], sum[N], inv[N], a[N], vis[N], ans;

void dfs(int p) {
	if(p > n) {
//		for(int i = 1; i <= n; i++) printf("%lld ", a[i]);
		int cnt = 0;
		for(int i = 1; i <= n; i++)
			cnt += (sum[i] < c[a[i]]) && (s[i] == '1');
//		printf("%lld\n", cnt);
		ans += cnt >= m;
	}
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			vis[i] = 1, a[p] = i;
			dfs(p + 1);
			vis[i] = 0;
		}
	}
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	scanf("%s", s + 1);
	bool tA = 1;
	inv[0] = 1;
	for(int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + (s[i] == '0');
		if(s[i] != '0') tA = 0;
		inv[i] = inv[i - 1] * i % mod;
	}
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &c[i]);
		a[i] = i;
	}
	if(tA) {
		printf("%lld\n", inv[n]);
		return 0;
	}
	dfs(1);
	printf("%lld\n", ans);
	return 0;
}
