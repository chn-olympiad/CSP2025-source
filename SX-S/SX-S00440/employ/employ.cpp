#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
ll n, m, a[100005], b[100005], tmp, ans;
int c[100005], vis[100005], op;

ll qpow(ll x, ll y) {
	ll mul = 1;
	while (y) {
		if (y & 1)
			mul = mul * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return mul;
}

void dfs(int d) {
	if (d == n + 1) {
		int ct1 = 0, ct2 = 0;
		for (int i = 1; i <= n; i ++)
			if (!c[b[i]] || ct1 >= a[b[i]])
				ct1 ++;
			else
				ct2 ++;
		if (ct2 >= m)
			ans ++;
		return;
	}
	for (int i = 1; i <= n; i ++)
		if (!vis[i]) {
			vis[i] = 1;
			b[d] = i;
			dfs(d + 1);
			vis[i] = 0;
			b[d] = 0;
		}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i ++) {
		scanf("%1d", &c[i]);
		if (!c[i])
			op = 0;
	}
	for (int i = 1; i <= n; i ++) {
		scanf("%lld", &a[i]);
		if (a[i])
			tmp ++;
	}
	if (op) {
		if (tmp >= m)
			cout << qpow(2ll, tmp - m);
		else
			cout << 0;
		return 0;
	}
	dfs(1);
	cout << ans;
	return 0;
}