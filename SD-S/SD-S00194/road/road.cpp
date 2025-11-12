#include <bits/stdc++.h>

#define debug(...) fprintf(stderr, __VA_ARGS__)

template <typename type>
inline void read(type &x) {
	x = 0; int ch = getchar(); bool flag (false);
	while (!isdigit(ch)) flag = ch == '-', ch = getchar();
	while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	flag ? x = -x : 0;
}
template <typename type>
inline void write(type x, bool mode = 1) {
	x < 0 ? putchar('-'), x = -x : 0; static int stack[20], top (0);
	do stack[++top] = x % 10, x /= 10; while (x);
	while (top) putchar(stack[top--] | 48);
	mode ? putchar('\n') : putchar(' ');
}

using namespace std;

using ll = long long;

constexpr int MaxN = 1e4 + 50;
constexpr int MaxM = 1e6 + 50;
constexpr int MaxK = 15;

int n, m, k;

struct edge {
	int u, v, w;
	bool operator < (const edge &rhs) const {
		return w < rhs.w;
	}
} E1[MaxM], G[MaxN];

edge O[MaxK][MaxN];

edge tem[MaxN * 11];
edge mst[MaxN * 11];
int ncnt = 0, mcnt = 0;

int tot = 0; // cnt Y MST
//E1 yuantu 

int fa[MaxN], siz[MaxN];
inline int find(int x) {
	while (x != fa[x])
		x = fa[x] = fa[fa[x]];
	return x;
}
inline bool merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return false;
	if (siz[x] < siz[y])
		swap (x, y);
	fa[y] = x, siz[x] += siz[y];
	return true;
}

int val[MaxK][MaxN], cst[MaxK];

signed main() {
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	read(n), read(m), read(k);
	
	for (int i = 1; i <= m; i++)
		read(E1[i].u), read(E1[i].v), read(E1[i].w);
	sort(E1 + 1, E1 + m + 1);
	
	for (int i = 1; i <= k; i++) {
		read(cst[i]);
		for (int j = 1; j <= n; j++) {
			read(val[i][j]);
			O[i][j] = (edge){n + i, j, val[i][j]};
//			debug(" readin O[%d][%d] = (%d, %d, %d)\n", i, j, n + i, j, val[i][j]);
		}
		sort(O[i] + 1, O[i] + n + 1);
	}
	
	for (int i = 1; i <= n; i++)
		fa[i] = i, siz[i] = 1;
	
	ll ans = 0;
	for (int i = 1; i <= m; i++) {
		if (merge(E1[i].u, E1[i].v)) {
			G[++tot] = E1[i];
			ans += E1[i].w;
//			debug(" on mst (%d, %d, %d)\n", E1[i].u, E1[i].v, E1[i].w);
		}
		if (tot == n - 1) break;
	}
	
//	debug(" ans = %lld\n", ans);
	for (int S = 1; S < (1 << k); S++) {
		ncnt = n + __builtin_popcount(S);
		mcnt = n - 1;
		ll res = 0;
		for (int i = 1; i <= mcnt; i++)
			mst[i] = G[i];
		for (int i = 1; i <= k; i++) if ((S >> (i - 1)) & 1) {
			res += cst[i];
			int l = 1, r = 1, now = 1;
			for (; l <= mcnt; ) {
				while (r <= n && O[i][r].w <= mst[l].w)
					tem[now++] = O[i][r], ++ r;
				tem[now++] = mst[l];
				++ l;
			}
			while (r <= n) tem[now++] = O[i][r], ++ r;
			mcnt = now - 1;
			for (int j = 1; j <= mcnt; j++)
				mst[j] = tem[j];
		}
		
//		assert(mcnt == n - 1 + __builtin_popcount(S) * n);
		
//		for (int i = 1; i <= mcnt; i++)
//			debug(" (%d, %d, %d)\n", mst[i].u, mst[i].v, mst[i].w);
		
		for (int i = 1; i <= n + k; i++)
			fa[i] = i, siz[i] = 1;
		int ntot = 0;
		for (int i = 1; i <= mcnt; i++) {
			if (merge(mst[i].u, mst[i].v)) {
				res += mst[i].w;
				++ ntot;
			}
			if (ntot == ncnt - 1) break;
		}
		ans = min(ans, res);
//		debug(" S = %d, res = %lld\n", S, res);
	}
	
	write(ans);
}
