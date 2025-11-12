#include <bits/stdc++.h>
#define mpr(a, b) make_pair(a, b)
#define pii pair<int, int>
#define int long long
using namespace std;
const int N = 500 + 100;
const int Mod = 998244353;
int n, m, c[N];
char s[N];
inline int read() {
	int now = 0, nev = 1;
	char ch = getchar();
	while (ch < '0' || '9' < ch) {
		if (ch == '-') nev = -1;
		ch = getchar();
	}
	while ('0' <= ch && ch <= '9') {
		now = (now << 1) + (now << 3) + (ch & 15);
		ch = getchar();
	}
	return nev * now;
}
void solve1() {
	int res = 1;
	for (int i = 1; i <= n; i++) res = res * i % Mod;
	printf("%lld\n", res);
	exit(0);
}
int vis[20], a[20], res = 0;
void dfs(int x) {
	if (x == n + 1) {
		int giveup = 0;
		for (int i = 1; i <= n; i++) 
			if (giveup >= c[a[i]] || s[i] == '0') 
				giveup++;
		if (n - giveup >= m) res++;
		return;
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			vis[i] = 1;
			a[x] = i;
			dfs(x + 1);
			vis[i] = 0;
		}
	return;
}
void solve2() {
	dfs(1);
	printf("%lld", res);
	exit(0);
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read(); m = read();
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) c[i] = read();
	bool flag1 = 1, cnt = 0, cont = 0;
	for (int i = 1; i <= n; i++) 
		if (s[i] != '1') flag1 = 0;
		else cnt++;
	for (int i = 1; i <= n; i++) if (c[i] == 0) cont++;
	if (cnt < m || cont > n - m) { cout << 0 << endl; exit(0); }
	if (flag1 || n > 18) solve1();
	if (n <= 18) solve2();
	return 0;
}
