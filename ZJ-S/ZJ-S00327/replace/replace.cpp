#include <bits/stdc++.h>
using namespace std;
bool o1;
const int N = 1e7 + 10, M = 4e5 + 10;
using ll = long long;
const ll P1 = 1000000009;
const ll P2 = 998244353;
int f[N];
inline void update(int u, int v) {
	while (u < N) f[u] += v, u += u & -u;
}
inline int query(int u) {
	int ans = 0;
	while (u) ans += f[u], u -= u & -u;
	return ans;
}
struct Hsh {
	ll v1, v2;
	inline void operator+=(char v) {
		v1 = (v1 * 251 + v) % P1;
		v2 = (v2 * 307 + v) % P2;
	}
	inline bool operator<(Hsh b) const { return v1 != b.v1 ? v1 < b.v1 : v2 < b.v2; }
	inline bool operator==(Hsh b) const { return v1 == b.v1 && v2 == b.v2; }
};
int ch[N][26], ncnt;
inline int insert(string c) {
	int u = 0;
	for (char v : c) {
		if (!ch[u][v - 'a']) ch[u][v - 'a'] = ++ncnt;
		u = ch[u][v - 'a'];
	}
	return u;
}
inline int query(string c) {
	int u = 0;
	for (char v : c) {
		if (!ch[u][v - 'a']) return -1;
		u = ch[u][v - 'a'];
	}
	return u;
}
int dfn[N], L[N], R[N], dfncnt;
void dfs(int u) {
	dfn[u] = ++dfncnt, L[u] = dfncnt;
	for (int i = 0; i < 26; i++)
		if (ch[u][i]) dfs(ch[u][i]);
	R[u] = dfncnt;
}
struct Info {
	string pre;
	Hsh val;
	string suf;
	int type;
	inline void print() { cerr << pre << ' ' << suf << ' ' << type << endl; }
} a[M];
struct Update {
	int x, l, r, type;
	inline bool operator<(Update b) {
		if (x != b.x) return x < b.x;
		return type < b.type;
	}
} upd[M * 4];
inline Info readInfo(int type) {
	string s1, s2;
	cin >> s1 >> s2;
	if (s1 == s2) return {};
	if (s1.size() != s2.size()) return {};
	int pl = 0, pr = int(s1.size() - 1);
	while (s1[pl] == s2[pl]) ++pl;
	while (s1[pr] == s2[pr]) --pr;
	Info res = {};
	res.type = type;
	for (int i = pl - 1; ~i; i--) res.pre += s1[i];
	for (int i = pr + 1; i < s1.size(); i++) res.suf += s1[i];
	for (int i = pl; i <= pr; i++) res.val += s1[i];
	for (int i = pl; i <= pr; i++) res.val += s2[i];
	// cerr << "res info:" << res.pre << ' ' << res.val.v1 << ' ' << res.suf << endl;
	return res;
}
inline void clear() {
	for (int i = 0; i <= ncnt; i++) memset(ch[i], 0, sizeof(ch[i]));
	ncnt = 0;
}
int n, q, ans[M], id[M], posL1[M], posR1[M];
bool o2;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	// cerr << (&o2 - &o1) / 1048576. << endl;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) a[i] = readInfo(0);
	for (int i = 1; i <= q; i++) a[n + i] = readInfo(i);
	for (int i = 1; i <= n + q; i++) id[i] = i;
	sort(id + 1, id + n + q + 1, [&](int x, int y) { return a[x].val < a[y].val; });
	// for (int i = 1; i <= n + q; i++) cerr << id[i] << ' ';
	// cerr << endl;
	int pvp = 0;
	for (int l = 1, r; l <= n + q; l = r + 1) {
		r = l;
		while (r + 1 <= n + q && a[id[r + 1]].val == a[id[r]].val) ++r;
		// cerr << "find nosk:" << l << ' ' << r << endl;
		// if (l != r) cerr << "to there:" << ' ' << l << ' ' << r << endl, a[id[l]].print(), a[id[r]].print();
		clear();
		for (int i = l; i <= r; i++) 
			if (a[id[i]].type) pvp += (l != r), insert(a[id[i]].pre);
		dfncnt = 0;
		dfs(0);
		for (int i = l; i <= r; i++) {
			int u = query(a[id[i]].pre);
			// cerr << "find youmoto:" << i << ' ' << u << ' ' << L[u] << ' ' << R[u] << endl;
			if (u != -1) posL1[i] = L[u], posR1[i] = R[u];
			else posL1[i] = posR1[i] = -1, assert(!a[id[i]].type);
		}
		clear();
		for (int i = l; i <= r; i++) 
			if (a[id[i]].type) insert(a[id[i]].suf);
		dfncnt = 0;
		dfs(0);

		int cur = 0;
		for (int i = l; i <= r; i++) {
			int u = query(a[id[i]].suf);
			if (u != -1) {
				if (!a[id[i]].type && posL1[i] != -1) {
					upd[++cur] = {posL1[i], L[u], R[u], -1};
					upd[++cur] = {posR1[i] + 1, L[u], R[u], -2};
					// cerr << "find insert update:" << posL1[i] << ' ' << posR1[i] << ' ' << L[u] << ' ' << R[u] << endl;
				}
				if (a[id[i]].type) upd[++cur] = {posL1[i], L[u], 0, a[id[i]].type};
			}
		}
		sort(upd + 1, upd + cur + 1);
		for (int i = 1; i <= cur; i++) {
			if (upd[i].type < 0) {
				// cerr << "find upd:" << upd[i].type << ' ' << upd[i].l << ' ' << upd[i].r << endl;
				update(upd[i].l, upd[i].type == -2 ? -1 : 1);
				update(upd[i].r + 1, upd[i].type == -2 ? 1 : -1);
			} else ans[upd[i].type] += query(upd[i].l);
		}
		// cerr << "sum:" << query(114514) << endl;
	}
	// cerr << "findpvp:" << pvp << endl;
	for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
	return 0;
}
/*
4 1
xax xbx
xa xb
ax bx
a b
xaxy xbxy
*/