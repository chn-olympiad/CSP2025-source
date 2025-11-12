#include <bits/stdc++.h>
char *p1, *p2, buf[100000];
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread (buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++)
#define pii pair <int, int>
using namespace std;

template <typename T> void read (T &x) {
	x = 0; int f = 1; char ch = getchar ();
	while (!isdigit (ch)) f = (ch == '-') ? -1 : f, ch = getchar ();
	while (isdigit (ch)) x = x * 10 + (ch & 15), ch = getchar (); x *= f;
}

const int N = 100010;
bool used[N]; int num[3];
int id[3][N], p[3], v[3];
multiset <pii> add[3][3];
int n, m, a[N][3], ans;

int gval (int j) {
	int x = -1e9, res = 0;
	for (int i = 0; i < 3; i++) {
		if (i == j) continue;
		if ((*add[j][i].rbegin ()).first >= x) {
			x = (*add[j][i].rbegin ()).first;
			res = i;
		}
	}
	return res;
}

void Erase (multiset <pii> &x, pii y) {
	x.erase (x.find (y));
}

void solve () {
	read (n);
	for (int i = 1; i <= n; i++) used[i] = 0;
	for (int i = 0; i < 3; i++) num[i] = 0, p[i] = 1;
	for (int i = 1; i <= n; i++) for (int j = 0; j < 3; j++) read (a[i][j]);
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) add[i][j].clear ();
	m = ans = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= n; j++) id[i][j] = j;
		sort (id[i] + 1, id[i] + n + 1, [&](int x, int y) {
			return a[x][i] > a[y][i];
		});
	}
	for (int i = 1; i <= n; i++) {
		int pos = 0, tag[3], tmp[3];
		for (int j = 0; j < 3; j++) {
			while (used[id[j][p[j]]]) p[j]++;
		}
		for (int j = 0; j < 3; j++) {
			v[j] = a[id[j][p[j]]][j], tag[j] = 0;
			if (num[j] == n / 2) {
				pos = gval (j), tag[j] = 1;
				v[j] += (*add[j][pos].rbegin ()).first;
			}
			tmp[j] = j;
		}
		sort (tmp, tmp + 3, [&](int x, int y) {
			return v[x] > v[y];
		});
		int x = tmp[0];
		if (tag[x]) {
			ans += v[x], num[pos]++, used[id[x][p[x]]] = 1;
			for (int j = 0; j < 3; j++) if (j != x) {
				add[x][j].insert ({a[id[x][p[x]]][j] - a[id[x][p[x]]][x], id[x][p[x]]});
			}
			int pl = (*add[x][pos].rbegin ()).second;
			for (int j = 0; j < 3; j++) if (j != x) {
				Erase (add[x][j], {a[pl][j] - a[pl][x], pl});
			}
			for (int j = 0; j < 3; j++) if (j != pos) {
				add[pos][j].insert ({a[pl][j] - a[pl][pos], pl});
			}
			p[x]++;
		}
		else {
			ans += v[x], num[x]++, used[id[x][p[x]]] = 1;
			for (int j = 0; j < 3; j++) if (j != x) {
				add[x][j].insert ({a[id[x][p[x]]][j] - v[x], id[x][p[x]]});
			}
			p[x]++;
		}
	}
	printf("%d\n", ans);
}

signed main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	// freopen ("club4.in", "r", stdin);
	// freopen ("myA.txt", "w", stdout);
	int T; read (T);
	while (T--) solve ();
	return 0;
}