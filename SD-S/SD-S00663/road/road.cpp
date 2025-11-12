#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define LD long double
#define ull unsigned long long
#define x first
#define y second
#define F(i, a, b) for (int i = (a), i##E = (b); i <= i##E; ++i)
#define G(i, a, b) for (int i = (a), i##E = (b); i >= i##E; --i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(), a.end()
#define PB push_back

typedef pair <int, int> pii;
typedef pair <LL, LL> pll;
typedef pair <double, double> pdd;

inline void read(int &x) {
	x = 0; int w = 0; char ch = 0;
	while (!isdigit(ch)) w |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) x = (x<<3)+(x<<1)+(ch^48), ch = getchar();
	if (w) x = -x;
}

inline void readl(LL &x) {
	x = 0; int w = 0; char ch = 0;
	while (!isdigit(ch)) w |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) x = (x<<3)+(x<<1)+(ch^48), ch = getchar();
	if (w) x = -x;
}

const int mod = 998244353;

inline void ad(int &x, int y) {
	x += y;
	while (x >= mod) x -= mod;
}

const int N = 10010, M = 1000010, K = 12;

int n, m, k, c[K], fa[N+K];
pii a[K][N];
struct edge {
	int a, b, c;
	bool operator < (const edge &cmp) const {
		return c < cmp.c;
	}
} ep[M], e[M], et[M];

inline int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void mymain() {
	read(n), read(m), read(k);
	F(i, 1, m) {
		read(ep[i].a), read(ep[i].b), read(ep[i].c);
	}
	F(i, 0, k-1) {
		read(c[i]);
		F(j, 1, n) {
			read(a[i][j].x);
			a[i][j].y = j;
		}
		sort(a[i]+1, a[i]+n+1);
	}
	sort(ep+1, ep+m+1);
	F(i, 1, n) fa[i] = i;
	int tot = 0;
	LL res = 0;
	F(i, 1, m) {
		int pa = find(ep[i].a), pb = find(ep[i].b);
		if (pa != pb) {
			e[++tot] = ep[i];
			fa[pa] = pb;
			res += ep[i].c;
		}
	}
	F(i, 1, tot) ep[i] = e[i];
	F(mask, 1, (1<<k)-1) {
		LL val = 0;
		F(i, 0, k-1) {
			if (mask >> i & 1) {
				val += c[i];
				int p1 = 1, p2 = 1, tt = 0;
				F(j, 1, tot) et[j] = e[j];
				while (p1 <= tot && p2 <= n) {
					if (et[p1].c <= a[i][p2].x) e[++tt] = et[p1], p1++;
					else e[++tt] = {n+i+1, a[i][p2].y, a[i][p2].x}, p2++;
				}
				while (p1 <= tot) e[++tt] = et[p1], p1++;
				while (p2 <= n) e[++tt] = {n+i+1, a[i][p2].y, a[i][p2].x}, p2++;
				tot = tt;
			}
		}
		F(i, 1, n+k) fa[i] = i;
		F(i, 1, tot) {
			int pa = find(e[i].a), pb = find(e[i].b);
			if (pa != pb) {
				fa[pa] = pb;
				val += e[i].c;
			}
		}
		res = min(res, val);
		tot = n-1;
		F(i, 1, tot) e[i] = ep[i];
	}
	printf("%lld\n", res);
}

void myclear() {
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int _ = 1;
//	read(_);
	F(ca, 1, _) {
		mymain();
		if (ca < _) myclear();
	}
	return 0;
}

