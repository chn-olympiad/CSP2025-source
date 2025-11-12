#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define INF_LL 0x3f3f3f3f3f3f3f3f
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 5, M = 5e6 + 5, C = 26;
const int P = 993244853, base = 2137, base2 = 1337;

int n, q;

string s, t;
string str;

struct Trie {
	int rt[N], ch[M][C], tot;
	int ins(int id, string &s) {
		if (!rt[id]) {
			rt[id] = ++tot;
		}
		int p = rt[id];
		for (char c : s) {
			c -= 'a';
			if (!ch[p][c]) {
				ch[p][c] = ++tot;
			}
			p = ch[p][c];
		}
		return p;
	}

	int dfn[M], lst[M], dfc;
	void dfs(int u) {
		dfn[u] = ++dfc;
		for (int i = 0; i < C; ++i) {
			if (ch[u][i]) {
				dfs(ch[u][i]);
			}
		}
		lst[u] = dfc;
	}
	void getdfs() {
		for (int i = 1; i <= tot; ++i) {
			if (!dfn[i]) {
				dfs(i);
			}
		}
	}
} T1, T2;

int p1[N], p2[N];

int q1[N], q2[N];

int ip[N], iq[N];
int num;
map<int, int> id;

int m;
struct node {
	int x, y, val;
	node() {}
	node(int X, int Y, int V) {
		x = X, y = Y, val = V;
	}
	bool operator<(const node &t) const {
		return x < t.x;
	}
} f[N << 2];
struct query {
	int x, y, id;
	query() {}
	query(int X, int Y, int I) {
		x = X, y = Y, id = I;
	}
	bool operator<(const query &t) const {
		return x < t.x;
	}
} g[N << 2];

int tr[M];
void add(int k, int x) {
	for (; k <= T2.tot; k += (k & (-k))) {
		tr[k] += x;
	}
}
int qry(int k) {
	int res = 0;
	for (; k; k ^= (k & (-k))) {
		res += tr[k];
	}
	return res;
}

int ans[N];

signed main() {
	assert(freopen("replace.in", "r", stdin));
	assert(freopen("replace.out", "w", stdout));

	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> s >> t;
		if (s == t) {
			continue;
		}
		int len = s.size(), lt = 0, rt = 0;
		for (int j = 0; j < len; ++j) {
			if (s[j] ^ t[j]) {
				lt = j;
				break;
			}
		}
		for (int j = len - 1; j >= 0; --j) {
			if (s[j] ^ t[j]) {
				rt = j;
				break;
			}
		}
		int hsh = 0;
		for (int j = lt; j <= rt; ++j) {
			hsh = (1ll * hsh * base + (s[j] * base2 + t[j])) % P;
		}
		if (!id[hsh]) {
			id[hsh] = ++num;
		}
		ip[i] = id[hsh];
		str.clear();
		for (int i = lt - 1; i >= 0; --i) {
			str += s[i];
		}
		p1[i] = T1.ins(ip[i], str);
		str.clear();
		for (int i = rt; i < len; ++i) {
			str += s[i];
		}
		p2[i] = T2.ins(ip[i], str);
	}
	for (int i = 1; i <= q; ++i) {
		cin >> s >> t;
		if (s.size() != t.size()) {
			continue;
		}
		int len = s.size(), lt = 0, rt = 0;
		for (int j = 0; j < len; ++j) {
			if (s[j] ^ t[j]) {
				lt = j;
				break;
			}
		}
		for (int j = len - 1; j >= 0; --j) {
			if (s[j] ^ t[j]) {
				rt = j;
				break;
			}
		}
		int hsh = 0;
		for (int j = lt; j <= rt; ++j) {
			hsh = (1ll * hsh * base + (s[j] * base2 + t[j])) % P;
		}
		if (!id[hsh]) {
			id[hsh] = ++num;
		}
		iq[i] = id[hsh];
		str.clear();
		for (int i = lt - 1; i >= 0; --i) {
			str += s[i];
		}
		q1[i] = T1.ins(iq[i], str);
		str.clear();
		for (int i = rt; i < len; ++i) {
			str += s[i];
		}
		q2[i] = T2.ins(iq[i], str);
	}
	T1.getdfs();
	T2.getdfs();
	for (int i = 1; i <= n; ++i) {
		if (!p1[i]) {
			continue;
		}
		int l1 = T1.dfn[p1[i]], r1 = T1.lst[p1[i]];
		int l2 = T2.dfn[p2[i]], r2 = T2.lst[p2[i]];
		// cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << '\n';
		f[++m] = node(l1, l2, 1);
		f[++m] = node(l1, r2 + 1, -1);
		f[++m] = node(r1 + 1, l2, -1);
		f[++m] = node(r1 + 1, r2 + 1, 1);
	}
	for (int i = 1; i <= q; ++i) {
		// cout << T1.dfn[q1[i]] << ' ' << T2.dfn[q2[i]] << '\n';
		g[i] = query(T1.dfn[q1[i]], T2.dfn[q2[i]], i);
	}
	sort(f + 1, f + m + 1);
	sort(g + 1, g + q + 1);
	for (int i = 1, j = 1; i <= m; ++i) {
		for (; j <= q && g[j].x < f[i].x; ++j) {
			// cout << g[j].y << ' ' << qry(g[j].y);
			ans[g[j].id] = qry(g[j].y);
		}
		// cout << f[i].y << ' ' << f[i].val << '\n';
		add(f[i].y, f[i].val);
	}
	for (int i = 1; i <= q; ++i) {
		cout << ans[i] << '\n';
	}

	return 0;
}