#include <bits/stdc++.h>

using namespace std;

#define int long long

int _;
inline int read() {int s = 0, w = 1;char ch = getchar();while (ch < '0' || ch > '9') {if (ch == '-') w *= -1;ch = getchar();}while (ch >= '0' && ch <= '9') {s = (s << 3) + (s << 1) + (ch ^ 48);ch = getchar();}return s * w;}
inline void write(int x) {if (x < 0) x = -x, putchar('-');if (x > 9) write(x / 10);putchar(x % 10 + '0');}

const int N = 1e5 + 5;
int n, m, a[4][N], vis[4], ans, t1, t2;

void dfs(int x, int sum) {
	if (vis[1] > m || vis[2] > m || vis[3] > m) return ;
	if (x == n + 1) {
		ans = max(ans, sum);
		return ;
	}
	vis[1]++;
	dfs(x + 1, sum + a[1][x]);
	vis[1]--, vis[2]++;
	dfs(x + 1, sum + a[2][x]);
	vis[2]--, vis[3]++;
	dfs(x + 1, sum + a[3][x]);
	vis[3]--;
}

inline void solve() {
	ans = 0;
	n = read();
	m = n / 2;
	vis[1] = vis[2] = vis[3] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 3; ++j) {
			a[j][i] = read();
			if (j == 2 && a[j][i] == 0) t1++;
			else if (j == 3 && a[j][i] == 0) t2++;
		}
	}
	if (t1 == n && t2 == n) {
		sort(a[1] + 1, a[1] + n + 1, greater<int>());
		int sum = 0;
		for (int i = 1; i <= m; ++i) {
			sum += a[1][i];
		}
		write(sum);
		return ;
	}
	dfs(1, 0);
	write(ans), putchar('\n');
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	_ = read();
//	_ = 1;
	for (int i = 1; i <= _; ++i) solve();
	return 0;
}
