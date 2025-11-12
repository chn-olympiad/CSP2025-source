#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct IO {
	IO() { freopen("employ.in", "r", stdin), freopen("employ.out", "w", stdout); }
	~IO() { fclose(stdin), fclose(stdout); }
} io;
const int P = 998244353;
int n, m, s[505], a[505], ar[505], zr[505], aC;
ll c[505][505], fac[505], ifac[505];
ll f[2][505][505], g[505];
int op;
ll QPow(ll a, ll b) {
	ll res = 1;
	for (; b; b >>= 1, a = a * a % P) if (b & 1) res = res * a % P;
	return res;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%1d", s + i), zr[i] = (!s[i]);
	for (int i = n; i; i--) zr[i] += zr[i + 1];
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % P;
	ifac[n] = QPow(fac[n], P - 2);
	for (int i = n; i; i--) ifac[i - 1] = ifac[i] * i % P;
	for (int i = 0; i <= n; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % P;
	}
	for (int i = 1, x; i <= n; i++) scanf("%d", &x), a[x]++;
	for (int i = n; i >= 0; i--) ar[i] = ar[i + 1] + a[i];
	for (int z = 0; z <= a[0]; z++) {
		int x = a[0], R = z - (n - zr[1]) + ar[1];
		f[0][0][z] = c[x][z] * fac[z] % P * fac[x - z + R] % P;
	}
	for (int i = 1; i <= n; i++) {
		op ^= 1;
		memset(f[op], 0, sizeof(f[op]));
		for (int l = 0; l <= i; l++) {
			if (l) {
				for (int p = 0; p <= n; p++) g[p] = f[!op][l - 1][p + s[i]] * ifac[p] % P;
				for (int z = 0; z <= n - i; z++) {
					int R = z - (n - i - zr[i + 1]) + ar[l + 1];
					for (int p = 0; p <= min(z, a[l]); p++) f[op][l][z] += g[z - p] * c[a[l]][p] % P;
					f[op][l][z] = f[op][l][z] % P * fac[z] % P;
				}
			}
			for (int z = 0; z <= n - i; z++) {
				int R = z - (n - i - zr[i + 1]) + ar[l + 1];
				if (s[i] && R) f[op][l][z] += f[!op][l][z] * R % P;
				f[op][l][z] %= P;
			}
		}
	}
	ll res = 0;
	for (int i = 0; i <= n - m; i++) res += f[op][i][0];
	printf("%lld\n", res % P);
	return 0;
}