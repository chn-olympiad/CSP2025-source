// ±©Á¦·Ö QWQ 
#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

inline int fpow(int x, int y) {
	int res = 1;
	while (y) {
		if (y & 1) res = res * x;
		y = y >> 1;
		x = x * x;
	}
	return res;
}

inline int gcd(int x, int y) {
	int tmp;
	while (x % y) {
		tmp = x % y;
		x = y;
		y = tmp;
	}
	return y;
}

inline int lcm(int x, int y) {
	return x * y / gcd(x, y);
}

const int MAXN = 1005;
const int MOD = 998244353;
int vis[MAXN];
int n, m;
long long ans = 0;
string s;
int a[MAXN], b[MAXN];
long long ttt[MAXN];

long long dfs(int x, int cnt, int dep) {
	int flg = 1;
	if (s[dep - 1] == '0' || b[x] <= dep - cnt - 1) flg = 0;
	if (cnt + flg >= m) {
		return ttt[n - dep];
	}
	if (dep >= n) {
		return 0;
	}
	vis[x] = 1;
	long long res = 0;
	for (int i = 1; i <= n; i ++) {
		if (vis[i]) continue;
		res = (res + dfs(i, cnt + flg, dep + 1)) % MOD;
	} 
	vis[x] = 0;
	return res;
} 

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read(), m = read();
	cin >> s;
	ttt[0] = 1;
	for (int i = 1; i <= n; i ++) ttt[i] = (ttt[i - 1] * i) % MOD;
	int flg = 1;
	for (int i = 1; i <= n; i ++) {
		b[i] = read();
		if (s[i - 1] != 0) flg = 0;
	} 
	if (flg) cout << 0 << '\n';
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) vis[j] = 0;
		ans = (ans + dfs(i, 0, 1)) % MOD;
	}
	cout << ans << '\n';
	return 0;
}

