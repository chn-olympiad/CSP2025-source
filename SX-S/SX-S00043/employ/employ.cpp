#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-')	f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int n, m, C[505][505], tmp[505], a[505], c[505], f[505][505][505], cnt0, cnt1, sum0[505], sum1[505], ans, jc[505];
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read(); m = read();
	for(int i = 1; i <= n; ++i) {
		char ch;
		cin>>ch;
		a[i] = ch - '0';
		if(a[i] == 0) {
			sum0[i] = 1;
			++cnt0;
		}
		else {
			sum1[i] = 1;
			++cnt1;
		}
	}
	jc[0] = 1;
	for(int i = 1; i <= n; ++i) {
		sum0[i] += sum0[i - 1];
		sum1[i] += sum1[i - 1];
		jc[i] = jc[i - 1] * i % mod;
	}
	for(int i = 1; i <= n; ++i) {
		c[i] = read();
		tmp[c[i]]++;
	}
	for(int i = 1; i <= n; ++i) {
		tmp[i] += tmp[i - 1];
	}
	C[0][0] = 1;
	C[1][0] = C[1][1] = 1;
	for(int i = 2; i <= n; ++i) {
		C[i][0] = 1;
		for(int j = 1; j <= i; ++j) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			C[i][j] %= mod;
		}
	}
	f[0][0][0] = 1;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j <= sum1[i]; ++j) {
			for(int k = 0; k <= sum1[i]; ++k) {
				int pre = sum0[i] + j, now = sum0[i + 1] + j;
				if(a[i + 1] == 0) {
					for(int l = 0; l <= min(k, tmp[now] - tmp[pre]); ++l) {
						f[i + 1][j][k - l] = (f[i + 1][j][k - l] + f[i][j][k] * C[tmp[now] - tmp[pre]][l] % mod * C[k][l] % mod * jc[l]) % mod;
					}
				}
				else {
					f[i + 1][j][k + 1] += f[i][j][k];
					f[i + 1][j][k + 1] %= mod;
					now++;
					if(tmp[max(now - 1, 0ll)] - sum1[i] + k > 0) {
						for(int l = 0; l <= min(k, tmp[now] - tmp[pre]); ++l) {
							f[i + 1][j + 1][k - l] = (f[i + 1][j + 1][k - l] + f[i][j][k] * C[tmp[now] - tmp[pre]][l] % mod * C[k][l] % mod * jc[l] % mod * (tmp[max(now - 1, 0ll)] - sum1[i] + k)) % mod;
						}
					}
				}
			}
		}
	}
	for(int j = 0; j <= n - cnt0 - m; ++j) {
		for(int k = 0; k <= cnt1; ++k) {
			int pre = cnt0 + j;
			ans += f[n][j][k] * C[tmp[n] - tmp[pre]][k] % mod * jc[k] % mod;
			ans %= mod;
		}
	}
	for(int i = 1; i <= cnt0; ++i) {
		ans = ans * i % mod;
	}
	printf("%lld", ans);
	return 0;
}
