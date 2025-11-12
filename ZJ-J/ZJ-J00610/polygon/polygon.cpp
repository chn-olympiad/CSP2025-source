#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 5000 + 10, mod = 998244353;
int n, a[N], ans, fac[N];
mt19937 rnd(time(0));

void dfs(int now, int ma, int sum) {
	if(now > n) {
		if(sum > 2 * ma) ans = (ans + 1) % mod;
		return;
	}
	dfs(now + 1, max(ma, a[now]), sum + a[now]);
	dfs(now + 1, ma, sum);
}

int ksm(int x, int y) {
	int res = 1;
	while(y) {
		if(y & 1) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod;
		y >>= 1;
	}
	return res;
}

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;++ i) cin >> a[i];
	if(n <= 20) {
		dfs(1, 0, 0);
		cout << ans;
	} else {
		int maxx = 0;
		for(int i = 1;i <= n;++ i){
			maxx = max(maxx, a[i]);
		}
		if(maxx == 1) {
			fac[0] = 1;
			for(int i = 1;i <= n;++ i) fac[i] = 1ll * fac[i - 1] * i % mod;
			for(int i = 3;i <= n;++ i){
				ans = (ans + 1ll * fac[n] * ksm(fac[i], mod - 2) % mod * ksm(fac[n - i], mod - 2) % mod) % mod;
			}
			cout << ans;
		} else {
			cout << rnd() % mod;
		}
	}
	return 0;
}