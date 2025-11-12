#include <bits/stdc++.h>
using namespace std;
const int maxn = 510, md = 998244353;
int n, m, c[maxn], fac[maxn], inv[maxn];
string s;
int qpow(int a, int b) {
	int ans = 1;
	while(b) {
		if(b & 1) ans = 1ll * ans * a % md;
		a = 1ll * a * a % md;
		b >>= 1;
	}
	return ans;
}
int C(int n, int m) {
	if(n < m || n < 0 || m < 0) return 0;
	return 1ll * fac[n] * inv[m] % md * inv[n - m] % md;
}
namespace Sub1 {
	vector <int> vec;
	int f[20][20], ans;
	void solve() {
		ans = 0;
		for(int S = 0; S < (1 << n); S++) {
			int sum = 0;
			vec.clear();
			for(int i = 1; i <= n; i++) {
				if(S & (1 << (i - 1))) sum++, vec.push_back(i);
			}
			if(sum < m) continue;
			f[0][0] = 1;
			for(int i = 1; i <= n; i++) {
				for(int j = 0; j <= min(i, sum); j++) {
					f[i][j] = 1ll * f[i - 1][j] * (n - i + 1 + j - sum) % md;
					if(s[i] == '1' && j >= 1) {
						int tmp = 0;
						for(int x : vec) {
							if(c[x] > (i - 1 - j)) tmp++;
						}
						if(tmp >= j) (f[i][j] += f[i - 1][j - 1] * (tmp - j + 1)) %= md;
					}
				}
			}
			(ans += f[n][sum]) %= md;
		}
		cout << ans << "\n";
	}
}
namespace Sub2 {
	void solve() {
		bool flg = 1;
		for(int i = 1; i <= n; i++) {
			if(s[i] != '1') flg = 0;
		}
		if(!flg) cout << "0\n";
		else cout << fac[n] << "\n";
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> s; s = " " + s;
	for(int i = 1; i <= n; i++) cin >> c[i];
	fac[0] = 1; for(int i = 1; i < maxn; i++) fac[i] = 1ll * fac[i - 1] * i % md;
	inv[maxn - 1] = qpow(fac[maxn - 1], md - 2);
	for(int i = maxn - 2; ~i; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % md; 	
	if(n <= 10) {
		Sub1::solve();
		return 0;
	}
	if(m == n) {
		Sub2::solve();
		return 0;
	}
	return 0;
}
