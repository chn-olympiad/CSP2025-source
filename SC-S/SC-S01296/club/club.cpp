#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, y) for (int i = (x); i <= (y); i++)
#define per(i, x, y) for (int i = (x); i >= (y); i--)
int read() {
	int s = 0, f = 1; char c = getchar();
	while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)) s = s * 10 + (c ^ 48), c = getchar();
	return s * f;
}
constexpr int N = 1e5 + 5;
int n, ps, a[N][3], id[N], b[N];
bool cmp(int x, int y) {
	return a[x][ps] - b[x] > a[y][ps] - b[y];
}
void sol() {
	n = read();
	rep (i, 1, n) rep (j, 0, 2) a[i][j] = read();
	array<int, 3> buc = {0, 0, 0};
	int ans = 0;
	rep (i, 1, n) {
		if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) buc[0]++, ans += a[i][0];
		else if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) buc[1]++, ans += a[i][1];
		else buc[2]++, ans += a[i][2];
	}
	if (max(max(buc[0], buc[1]), buc[2]) <= n / 2) return cout << ans << '\n', void();
	if (buc[0] > n / 2) ps = 0; else if (buc[1] > n / 2) ps = 1; else ps = 2;
//	cout << ps << ' ' << buc[ps] << '\n';
	rep (i, 1, n) {
		b[i] = 0; id[i] = i;
		rep (j, 0, 2) if (j != ps) b[i] = max(b[i], a[i][j]);
	} 
	sort(id + 1, id + n + 1, cmp); ans = 0;
	rep (i, 1, n / 2) {
		int p = id[i];
//		cerr << p << endl;
		ans += a[p][ps];
	}
	rep (i, n / 2 + 1, n) {
		int p = id[i];
		ans += b[p];
	}
	cout << ans << '\n';
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int _ = read();
	while (_--) sol();
	return 0;
}
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
