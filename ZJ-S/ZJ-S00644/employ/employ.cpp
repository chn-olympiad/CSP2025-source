#include <bits/stdc++.h>

using namespace std;

const int N = 550, mod = 998244353;

int n, m, c[N];
char s[N];

int ppc(int x) {
	int res = 0;
	while (x) res ++ , x -= (x & -x);
	return res;
}

void bf() {
	static int f[1 << 18][18];
	f[0][0] = 1;
	for (int S = 0; S < (1 << n) - 1; S ++ ) {
		int x = ppc(S);
		for (int i = 0; i <= x; i ++ ) {
			if (!f[S][i]) continue ;
			for (int j = 1; j <= n; j ++ ) {
				if (S >> (j - 1) & 1) continue ;
				if (c[j] <= i || s[x + 1] == '0') {
					//cout << i << ' ' << j << ' ' << x << ' ' << S << endl;
					(f[S ^ (1 << (j - 1))][i + 1] += f[S][i]) %= mod;
				}
			  else (f[S ^ (1 << (j - 1))][i] += f[S][i]) %= mod;
			}
		}
	}
	int res = 0;
	for (int i = 0; i <= n - m; i ++ ) (res += f[(1 << n) - 1][i]) %= mod;
	printf("%d\n", res);
}

int main() {
	freopen("employ.in", "r", stdin); freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &c[i]);
	if (n <= 18) return bf(), 0;
	bool flg = 1;
	for (int i = 1; i <= n; i ++ ) flg &= (s[i] == '1');
	
	if (m == n) {
		int res = 1;
		for (int i = 1; i <= n; i ++ ) if (s[i] == '0') res = 0;
		for (int i = 1; i <= n; i ++ ) if (!c[i]) res = 0;
		for (int i = 1; i <= n; i ++ ) res = 1ll * res * i % mod;
		printf("%d\n", res); return 0; 
	}
	
}
