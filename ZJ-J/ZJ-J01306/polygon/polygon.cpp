// T4 polygon
// ???
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll M = 998244353ll;
int n, a[5010], o;
ll ans, f[5010];
void dfs_solve1(int i, int maxx, int m, int d) { 
	if (i == n + 1) {
		if (m >= 3 && d > 2 * maxx) ans++;
		return ;
	}
	dfs_solve1(i + 1, max(maxx, a[i]), m + 1, d + a[i]);
	dfs_solve1(i + 1, maxx, m, d);
}
void solve1() { 
	dfs_solve1(1, -1, 0, 0);
	cout << ans % M;
	exit(0);
}
void solve2() { 
	int x = 0, y = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] == 1) x++;
		else y++;
	ans = (f[x] - (ll)(x * (x - 1) / 2) - (ll)x - 1ll) * f[y] % M;
	cout << ans;
	exit(0);
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		o = max(o, a[i]);
	}
	f[0] = 1;
	for (int i = 1; i <= 5000; i++) 
		f[i] = f[i - 1] * 2ll % M;
	if (o <= 1) solve2();
	else solve1();
	return 0;
}