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
const int N = 1e4 + 10, M = 1e6 + 10;
int n, m, kk, c[20], v[20][N];
struct node {
	int x, y, w;
	il bool operator < (const node & cmp) const {
		return w < cmp.w;
	}
} e[M];
int fa[N << 1];
il int getfa(int x) {
	return x == fa[x] ? x : fa[x] = getfa(fa[x]);
}
node a[M], b[M];

bool End;
il void Usd() {cerr << "\nUse: " << (&Beg - &End) / 1024.0 / 1024.0 << "MB " << (double)clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n";}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
//	freopen("road4.in", "r", stdin);
	n = read(), m = read(), kk = read();
	for (int i = 1; i <= m; i++) {
		int x = read(), y = read(), w = read();
		e[i] = {x, y, w};
	}
	for (int i = 1; i <= kk; i++) {
		c[i] = read();
		for (int j = 1; j <= n; j++) v[i][j] = read();
	}
	int tot = 0;
	for (int i = 1; i <= n; i++) fa[i] = i;
	sort(e + 1, e + 1 + m);
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		int x = getfa(e[i].x), y = getfa(e[i].y);
		if (x != y) {
			fa[y] = x;
			b[++tot] = e[i];
			ans += e[i].w;
		}
	}
	for (int st = 0; st < (1 << kk); st++) {
		int tt = tot;
		for (int i = 1; i <= tt; i++) a[i] = b[i];
		int sum = 0;
		for (int i = 1; i <= kk; i++) {
			if (!((st >> i - 1) & 1)) continue;
			for (int j = 1; j <= n; j++) {
				a[++tt] = {n + i, j, v[i][j]};
			}
			sum += c[i];
		}
		sort(a + 1, a + 1 + tt);
		for (int i = 1; i <= n + kk; i++) fa[i] = i;
		for (int i = 1; i <= tt; i++) {
			int x = getfa(a[i].x), y = getfa(a[i].y);
			if (x != y) {
				fa[y] = x;
				sum += a[i].w;
//				cout << "E " << a[i].x << " " << a[i].y << " " << a[i].w << "\n";
			}
		}
		ans = min(ans, sum);
//		cout << "S " << st << " " << sum << "\n";
	}
	printf("%lld\n", ans);
	
//	Usd();
	return 0;
}
