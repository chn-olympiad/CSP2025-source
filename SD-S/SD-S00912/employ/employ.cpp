#include <bits/stdc++.h>
using namespace std;

const int N = 505, mod = 998244353;
typedef long long ll;
#define rep(i, a, b) for (int i(a); i <= (b); ++i) 
#define repr(i, a, b) for (int i(a); i < (b); ++i)
#define per(i, a, b) for (int i(a); i >= (b); --i)
template <class T> inline void ckmn(T &a, T b) { (a > b) && (a = b); }
template <class T> inline void ckmx(T &a, T b) { (a < b) && (a = b); }

int n, m, s[N], t[N], p[N], x, f[N][N][N];
int fac[N], fiv[N]; 

inline void rd(int &a, int c = 0) {
	while (!isdigit(c = getchar()));
	for (a = 0; isdigit(c); c = getchar()) a = (a << 3) + (a << 1) + (c ^ 48);
}
void wrt(int x) {
	if (x > 9) wrt(x / 10);
	putchar(x % 10 ^ 48);
}
int qpw(int a, int b) {
	int R = 1;
	for (; b; b >>= 1) {
		if (b & 1) R = 1ll * R * a % mod;
		a = 1ll * a * a % mod; 
	}
	return R;
}
void init() {
	rep(i, fac[0] = 1, 500) fac[i] = 1ll * fac[i - 1] * i % mod;
	fiv[500] = qpw(fac[500], mod - 2);
	per(i, 499, 0) fiv[i] = fiv[i + 1] * (i + 1ll) % mod;
}
inline void ad(int &a, ll b) { a = (a + b) % mod; } 
inline int C(int n, int m) {
	if (n < m || n < 0 || m < 0) return 0;
	return 1ll * fac[n] * fiv[m] % mod * fiv[n - m] % mod;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	init();
	rd(n), rd(m);
	rep(i, 1, n) {
		while (isspace(x = getchar()));
		s[i] = x ^ 48;
	}
	rep(i, 1, n) rd(x), t[x]++;
	p[0] = t[0];
	rep(i, 1, n) p[i] = p[i - 1] + t[i];
//	rep(i, 0, n) cout << t[i] << " "; cout << endl;
//	rep(i, 0, n) cout << p[i] << " "; cout << endl;

//	#define cha(a, b, c) ((a) == 3 && (b) == 2 && (c) == 0)

	f[0][0][0] = 1;
	repr(i, 0, n) {
		rep(j, 0, i) {
			rep(k, 0, i) {
				if (!f[i][j][k]) continue;
//				cout << i << " " << j << " " << k << " " << f[i][j][k] << endl;
				if (s[i + 1] == 0) {
					// lose men count: j + 1
					rep(l, 0, min(t[j + 1], k)) {
						// c <= j:
						// count: p[j] - (i - k)
//						if (cha(i + 1, j + 1, k - l)) cout << i << " " << j << " " << k << " " << f[i][j][k] << " " << (p[j] - j) % mod * fac[t[j + 1]] % mod * fiv[t[j + 1] - l] % mod * C(k, l) % mod << endl;
						ad(f[i + 1][j + 1][k - l], 1ll * f[i][j][k] * (p[j] - (i - k)) % mod * fac[t[j + 1]] % mod * fiv[t[j + 1] - l] % mod * C(k, l));
						// c = j+1, s.t. l != t[j+1]
						if (l != t[j + 1]) {
//							if (cha(i + 1, j + 1, k - l)) cout << i << " " << j << " " << k << " " << f[i][j][k] << " " << fac[t[j + 1]] % mod * fiv[t[j + 1] - l - 1] % mod * C(k, l) % mod << endl;
							ad(f[i + 1][j + 1][k - l], 1ll * f[i][j][k] * fac[t[j + 1]] % mod * fiv[t[j + 1] - l - 1] % mod * C(k, l));
						}
						// c > j+1
//						if (cha(i + 1, j + 1, k - l + 1)) cout << i << " " << j << " " << k <<" " << f[i][j][k] << " " << fac[t[j + 1]] % mod * fiv[t[j + 1] - l] % mod * C(k, l) % mod << endl;
						ad(f[i + 1][j + 1][k - l + 1], 1ll * f[i][j][k] * fac[t[j + 1]] % mod * fiv[t[j + 1] - l] % mod * C(k, l));
					}
				} else {
					// c <= j
					// count: p[j] - (i - k)
					rep(l, 0, min(t[j + 1], k)) {
//						if (cha(i + 1, j + 1, k - l)) cout << i << " " << j << " " << k << " " << f[i][j][k] << " " << (p[j] - j) % mod * fac[t[j + 1]] % mod * fiv[t[j + 1] - l] % mod * C(k, l) % mod <<endl;
						ad(f[i + 1][j + 1][k - l], 1ll * f[i][j][k] * (p[j] - (i - k)) % mod * fac[t[j + 1]] % mod * fiv[t[j + 1] - l] % mod * C(k, l));
					}
					// c > j
//					if (cha(i + 1, j, k + 1)) cout << i << " " << j << " " << k << " " << f[i][j][k] << " " << 1 << endl;
					ad(f[i + 1][j][k + 1], f[i][j][k]);
				}
			}
		}
	}
//	cout << "  " << f[3][2][0] << endl;
	int ans = 0;
	rep(j, 0, n - m) {
		rep(k, 0, n) {
			if (f[n][j][k]) {
				if (p[j] + k == n) ad(ans, 1ll * f[n][j][k] * fac[k]);
			}
		}
	}
	wrt(ans);
	return 0;
}

