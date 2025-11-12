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
const int N = 5e3 + 2, M = 25000000 + 10, maxn = 1e4 + 5;
int n, a[N];
int t[M], s[N];
il void add(int &x, int y) {
	x = x + y >= MOD ? x + y - MOD : x + y;
}
int p[N];
int solve1() {
	int ans = 0;
	t[0] = 1;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = a[i] + 1; j <= s[i - 1]; j++) {
			add(cnt, t[j]);
		}
		add(ans, cnt);
		for (int j = s[i - 1]; j >= 0; j--) {
			add(t[j + a[i]], t[j]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
il int solve2() {
	int ans = 1;
	for (int i = 1; i <= n; i++) ans = ans * 2 % MOD;
	ans = (ans - 1 - n * (n - 1) / 2 % MOD - n) % MOD;
	ans = (ans + MOD) % MOD;
//	cout << "!";
	printf("%lld\n", ans);
	return 0;
}
//int f[N][maxn];
bool End;
il void Usd() {cerr << "\nUse: " << (&Beg - &End) / 1024.0 / 1024.0 << "MB " << (double)clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n";}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
//	freopen("sample.in", "r", stdin);
	n = read();
	int flag = 1;
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		flag &= (a[i] == 1);
	}
	if (flag) return solve2();
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
//	if (n <= 500 && s[n] <= 250000) 
//	return solve1();
//	p[0] = 1;
//	for (int i = 1; i <= n; i++) p[i] = p[i - 1] * 2 % MOD;
	int ans = 0;
	t[0] = 1;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = a[i] + 1; j <= s[i - 1]; j++) {
			add(cnt, t[j]);
		}
		add(ans, cnt);
		for (int j = s[i - 1]; j >= 0; j--) {
			add(t[j + a[i]], t[j]);
		}
	}
	printf("%lld\n", ans);
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int k = 1; k < i; k++) {
//			for (int j = a[i] + 1; j < maxn; j++) {
//				add(ans, f[k][j]);
//			}
//		}
//		f[i][a[i]] = p[i - 1];
//		for (int k = 1; k < i; k++) {
//			for (int j = 1; j < a[i]; j++) {
//				add(f[k][j + a[i]], f[k][j]);
//			}
//		}
//	}
//	printf("%lld\n", ans);
	
//	Usd();
	return 0;
}
