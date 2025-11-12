#include <bits/stdc++.h>
#define il inline
#define int long long

using namespace std;

const int bufsz = 1 << 20;
char ibuf[bufsz], *p1 = ibuf, *p2 = ibuf;
#define getchar() (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, bufsz, stdin), p1 == p2) ? EOF : *p1++)
il int read() {
	int x = 0; char ch = getchar(); bool t = 0;
	while (ch < '0' || ch > '9') {t ^= ch == '-'; ch = getchar();}
	while (ch >= '0' && ch <= '9') {x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
	return t ? -x : x;
}
bool Beg;
const int MOD = 998244353;
const int N = 500 + 5;
int n, m, a[N], c[N];
char s[N];
int fact[N], ny[N];
il int fpow(int a, int x) {
	a %= MOD;
	int ans = 1;
	while (x) {
		if (x & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		x >>= 1;
	}
	return ans;
}
il int C(int n, int m) {
	return n < m ? 0 : fact[n] * ny[m] % MOD * ny[n - m] % MOD;
}
int solve1() {
	int ans = 1;
	for (int i = 1; i <= n; i++) ans = ans * i % MOD;
	cout << ans << "\n";
	return 0;
}
//int t[N], s[N];
int solve2() {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!a[i]) continue;
		
		
	}
	
	
	return 0;
}
int p[N];
bool End;
il void Usd() {cerr << "\nUse: " << (&Beg - &End) / 1024.0 / 1024.0 << "MB " << (double)clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n";}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	cin >> n >> m >> (s + 1);
	int flag = 1;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		a[i] = (s[i] == '1');
		flag &= (a[i] == 0);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) cnt += (c[i] == 0);
	if (n - cnt < m || flag) return cout << "0\n", 0;
//	if (m == 1) return solve2();
	for (int i = 1; i <= n; i++) p[i] = i;
	int tmp = 1;
	for (int i = 1; i <= n; i++) tmp *= i;
	int ans = 0;
	while (tmp--) {
		int cnt = 0, res = 0;
		for (int i = 1; i <= n; i++) {
			if (cnt >= c[p[i]] || !a[i]) {
				cnt++;
			} else {
				res++;
			}
		}
//		cout << "P "; for (int i = 1; i <= n; i++) cout << p[i] << " "; cout << "  R " << res << "\n";
		ans = (ans + (res >= m)) % MOD;
		next_permutation(p + 1, p + 1 + n);
	}
	cout << ans << "\n";
	
//	Usd();
	return 0;
}
