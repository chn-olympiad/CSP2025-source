#include <bits/stdc++.h>
#define int long long
#define rep(i, l, r) for(int i = l; i <= r; ++i)
#define per(i, r, l) for(int i = r; i >= l; --i)
using namespace std;
const int N = 5005, mod = 998244353;
int qpow(int a, int n){
	if (n == 0) return 1;
	if (n & 1) return qpow(a, n - 1) * a % mod;
	int tmp = qpow(a, n >> 1);
	return tmp * tmp % mod;
}
int n, a[N], f[N], ans;
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	++f[a[1] + a[2]];
	++f[a[1]];
	++f[a[2]];
	f[0] = 1;
	rep(i, 3, n){
		(ans += (qpow(2, i - 1) + mod) % mod) %= mod;
		rep(j, 0, a[i]) (ans -= f[j] - mod) %= mod;
		per(j, 5000, 0)
			if (f[j] && j + a[i] <= 5000)
				(f[j + a[i]] += f[j]) %= mod;
	}
	cout << ans << '\n';
	return 0;
}

