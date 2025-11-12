#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define FOR(i, l, r, x) for (int i = l; i <= r; i = x)
#define DEFOR(i, l, r, x) for (int i = l; i >= r; i = x)
using namespace std;
const ll mod = 998244353;
int a[5005], n; 
ll f[5005], ans = 0;
ll ksm(ll x, ll y) {
	ll cnt = 1;
	while (y) {
		if (y & 1) {
			cnt *= x;
			cnt %= mod;
		}
		x *= x;
		x %= mod;
		y >>= 1;
	}
	return cnt;
}
void dfs(int k, int maxx, int sum) {
	if (k > n) {
		if (sum > maxx * 2) {
			ans++;
			ans %= mod;
		}
		return ;
	}
	dfs(k + 1, max(maxx, a[k]), sum + a[k]);
	dfs(k + 1, maxx, sum);
	return ;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	FOR(i, 1, n, ++i) {
		cin >> a[i];
	}
	if (n <= 20) {
		dfs(1, 0, 0);
		cout << ans << endl;
	} else {
		f[0] = 1;
		FOR(i, 1, n, ++i) {
			f[i] = f[i - 1] * i;
			f[i] %= mod;
			cout << i << " " << f[i - 1] * i % mod << endl;
		}
		FOR(i, 3, n, ++i) {
			ans = (ans + (f[n] * ksm(f[i], mod - 2) % mod * ksm(f[n - i], mod - 2))) % mod;
		}
		cout << ans << endl;
	}
	return 0;
}