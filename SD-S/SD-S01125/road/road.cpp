#include <cstring>
#include <iostream>
#include <vector>

#define ll long long

const int Maxn = 1e4 + 4, Maxm = 2e6 + 4 + 2e5;

inline ll Read() {
	char ch = getchar();
	ll ct = 0, lve = 1;

	while (ch < '0' || ch > '9') {
		if (ch == '-')
			lve = -lve;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		ct = (ct << 3) + (ct << 1) + ch - '0';
		ch = getchar();
	}
	return ct * lve;
}
inline void Write(ll x) {
	if (x < 0)
		x = -x;
	if (x > 9)
		Write(x / 10);
	putchar(x % 10 + '0');
}

inline ll max(ll x, ll y) {
	return x > y ? x : y;
}
inline ll min(ll x, ll y) {
	return x < y ? x : y;
}

int cnt, head[Maxn + 10], to[Maxm], nxt[Maxm], val[Maxm];

inline Add(int u, int v, int w) {
	to[++cnt] = v;
	nxt[cnt] = head[u];
	val[cnt] = w;
	head[u] = cnt;
}
inline AddEdge(int u, int v, int w) {
	Add(u, v, w), Add(v, u, w);
}

int uni[Maxn + 10], siz[Maxn + 10];

inline Find(int x) {
	return uni[x] == x ? x : uni[x] = Find(uni[x]);
}
inline Unite(int x, int y) {
	x = Find(x), y = Find(y);
	uni[x] = y;
	siz[y] += siz[x];
}

bool vis[Maxm], al[Maxn + 10], f;
int n, m, k, c[14], t, node[14], res, path[Maxn + 10], ans;
std::vector <int> vec;

inline void Init() {
	memset(vis, false, sizeof vis);
	res = 0;
	for (int i = 1; i <= n; ++i)
		uni[i] = i, siz[i] = 1, vec.push_back(i), path[i] = 0, al[i] = true;
	for (int i = 1; i <= t; ++i)
		uni[node[i]] = node[i], siz[node[i]] = 1, vec.push_back(node[i]), path[node[i]] = 0, al[node[i]] = true;
}

inline void B() {
	Init(); 

	while (siz[Find(1)] < n + t) {
		for (int u : vec) {
			int fu = Find(u);
			for (int i = head[u]; i; i = nxt[i]) {
				if (vis[i])
					continue;
				int v = to[i], w = val[i];
				if (Find(v) != fu && al[v])
					if (!path[fu] || val[path[fu]] > w)
						path[fu] = i;
			}
		}
		for (int i = 1; i <= n + k; ++i)
			if (path[i]) {
				int p = path[i];
				if (!vis[p]) {
					Unite(i, to[p]);
					res += val[p];
					vis[p] = vis[(p % 2 ? p + 1 : p - 1)] = true;
				}
				path[i] = 0;
			}
	}
}

inline void Solve() {
	if (f) {
		for (int i = 1; i <= k; ++i)
			node[++t] = n + i;
		B();
		ans = res;
		Write(ans);
		return ; }

	B();
	ans = res;

	ll b = (ll)((m + n * k << 1) * k) * 15;

	if (b > 1e8) {
		Write(ans);
		return ; }

	for (int i = 1; i <= k; ++i) {
		node[++t] = n + i;
		B();
		if (res + c[i] > ans)
			--t;
		else
			ans = res + c[i];
	}

	Write(ans);
}

int T;

signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	n = Read(), m = Read(), k = Read(), f = true;
	for (int i = 1; i <= m; ++i) {
		int u = Read(), v = Read(), w = Read();
		AddEdge(u, v, w);
	}
	for (int i = 1; i <= k; ++i) {
		c[i] = Read();
		f &= (!c[i]);
		for (int j = 1, a; j <= n; ++j)
			AddEdge(n + i, j, a = Read());
	}

	Solve();

	return 0;
}

