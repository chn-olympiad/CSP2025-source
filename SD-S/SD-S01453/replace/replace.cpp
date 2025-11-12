#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
const ll mod = 1000000007, base = 133;
const int N = 200005, L = 5000005;
int n;
vector < int > G[L];
int son[L], sz[L], fa[L];
void dfs1(int u, int fa) {
	::fa[u] = fa;
	sz[u] = 1;
	son[u] = -1;
	for (int v : G[u]) {
		dfs1(v, u);
		sz[u] += sz[v];
		if (son[u] == -1 || sz[son[u]] < sz[v]) {
			son[u] = v;
		}
	}
}
int top[L], dfn[L], cnt;
void dfs2(int u, int toplink) {
	top[u] = toplink;
	cnt++;
	dfn[u] = cnt;
	if (son[u] != -1) {
		dfs2(son[u], toplink);
		for (int v : G[u]) {
			if (v != son[u]) {
				dfs2(v, v);
			}
		}
	}
}
struct Node {
	int l, r, sum;
} node[4 * L];
void push_up(int p) {
	node[p].sum = node[2 * p].sum + node[2 * p + 1].sum;
}
void buildT(int p, int l, int r) {
	node[p].l = l;
	node[p].r = r;
	node[p].sum = 0;
	if (l < r) {
		int mid = (l + r) / 2;
		buildT(2 * p, l, mid);
		buildT(2 * p + 1, mid + 1, r);
	}
}
void add(int p, int pos, int v) {
	node[p].sum += v;
	if (node[p].l < node[p].r) {
		int mid = (node[p].l + node[p].r) / 2;
		if (pos <= mid) {
			add(2 * p, pos, v);
		} else {
			add(2 * p + 1, pos, v);
		}
	}
}
int query(int p, int l, int r) {
	if (l <= node[p].l && node[p].r <= r) {
		return node[p].sum;
	} else {
		int mid = (node[p].l + node[p].r) / 2, ans = 0;
		if (l <= mid) {
			ans += query(2 * p, l, r);
		}
		if (mid + 1 <= r) {
			ans += query(2 * p + 1, l, r);
		}
		return ans;
	}
}
void add(int x, int v) {
	add(1, dfn[x], v);
}
int query(int x) {
	int ans = 0;
	while (x != -1) {
		ans += query(1, dfn[top[x]], dfn[x]);
		x = fa[top[x]];
	}
	return ans;
}
ll ans[N];
struct Query {
	int y, id;
	Query(int y_, int id_) {
		y = y_;
		id = id_;
	}
};
vector < int > T[N];
struct Phigros {
	struct Milthm {
		struct Node {
			int ch[26], fail;
			vector < int > id;
			Node() {
				fail = -1;
				for (int i = 0; i < 26; i++) {
					ch[i] = -1;
				}
			}
		};
		vector < Node > node;
		map < int, int > pos;
		void init() {
			node.push_back(Node());
		}
		void insert(const string & s, int id) {
			int p = 0;
			for (char c : s) {
				if (node[p].ch[c - 'a'] == -1) {
					node[p].ch[c - 'a'] = node.size();
					node.push_back(Node());
				}
				p = node[p].ch[c - 'a'];
			}
			pos[id] = p;
			node[p].id.push_back(id);
		}
		void build() {
			queue < int > q;
			node[0].fail = 0;
			for (int i = 0; i < 26; i++) {
				if (node[0].ch[i] == -1) {
					node[0].ch[i] = 0;
				} else {
					q.push(node[0].ch[i]);
				}
				node[node[0].ch[i]].fail = 0;
			}
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (int i = 0; i < 26; i++) {
					if (node[u].ch[i] != -1) {
						node[node[u].ch[i]].fail = node[node[u].fail].ch[i];
						q.push(node[u].ch[i]);
					} else {
						node[u].ch[i] = node[node[u].fail].ch[i];
					}
				}
			}
		}
		void output() {
			int n = node.size();
			printf("ACAM, n = %d\n", n);
			for (int i = 0; i < n; i++) {
				printf("node %d: ", i);
				printf("fail %d child", node[i].fail);
				for (int j = 0; j < 26; j++) {
					printf(" %d", node[i].ch[j]);
				}
				printf(", vec");
				for (int x : node[i].id) {
					printf(" %d", x);
				}
				printf("\n");
			}
			for (auto p : pos) {
				printf("pos[%d] = %d\n", p.first, p.second);
			}
		}
	} M1, M2;
	Phigros() {
		M1.init();
		M2.init();
	}
	vector < vector < Query > > vec;
	void solve(int u) {
		for (int x : M1.node[u].id) {
			add(M2.pos[x], +1);
		}
		for (const Query & q : vec[u]) {
			ans[q.id] += query(q.y);
		}
		for (int v : T[u]) {
			solve(v);
		}
		for (int x : M1.node[u].id) {
			add(M2.pos[x], -1);
		}
	}
	void build() {
		M1.build();
		M2.build();
		vec.resize(M1.node.size());
	}
	void solve() {
		int l1 = M1.node.size();
		for (int i = 1; i < l1; i++) {
			T[M1.node[i].fail].push_back(i);
		}
		int l2 = M2.node.size();
		for (int i = 0; i < l2; i++) {
			dfn[i] = 0;
		}
		for (int i = 1; i < l2; i++) {
			G[M2.node[i].fail].push_back(i);
		}
		dfs1(0, -1);
		cnt = 0;
		dfs2(0, 0);
		buildT(1, 1, l2);
		solve(0);
		for (int i = 0; i < l1; i++) {
			T[i].clear();
		}
		for (int i = 0; i < l2; i++) {
			G[i].clear();
		}
	}
};
vector < Phigros > pool;
map < ll, int > pool_id;
ll Hash(const string & s) {
	ll x = 0;
	for (char ch : s) {
		x = (x * base + ch) % mod;
	}
	return x;
}
struct Result {
	string op[4];
	ll h;
	void slice(const string A, const string B) {
		int n = A.length();
		for (int i = 0; i < n; i++) {
			if (A[i] != B[i]) {
				for (int j = n; j > 0; j--) {
					if (A[j - 1] != B[j - 1]) {
						op[0] = A.substr(0, i);
						op[1] = A.substr(i, j - i);
						op[2] = B.substr(i, j - i);
						op[3] = A.substr(j);
						reverse(op[3].begin(), op[3].end());
						h = (Hash(op[1]) << 32) | Hash(op[2]);
						return;
					}
				}
			}
		}
	}
};
int main() {
	ios::sync_with_stdio(false);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		if (s1 != s2) {
			Result res;
			res.slice(s1, s2);
			if (pool_id.count(res.h) == 0) {
				int cnt = pool.size();
				pool_id[res.h] = cnt;
				pool.push_back(Phigros());
			}
			Phigros & phi = pool[pool_id[res.h]];
			phi.M1.insert(res.op[0], i);
			phi.M2.insert(res.op[3], i);
		}
	}
	for (Phigros & phi : pool) {
		phi.build();
	}
	for (int i = 1; i <= q; i++) {
		string t1, t2;
		cin >> t1 >> t2;
		if (t1.length() != t2.length()) {
			continue;
		}
		Result res;
		res.slice(t1, t2);
		if (pool_id.count(res.h) == 0) {
			continue;
		}
		Phigros & phi = pool[pool_id[res.h]];
		int x = 0, y = 0;
		for (char c : res.op[0]) {
			x = phi.M1.node[x].ch[c - 'a'];
		}
		for (char c : res.op[3]) {
			y = phi.M2.node[y].ch[c - 'a'];
		}
		phi.vec[x].push_back(Query(y, i));
	}
	for (Phigros & phi : pool) {
		phi.solve();
	}
	for (int i = 1; i <= q; i++) {
		printf("%lld\n", ans[i]);
	}
	return 0;
}
/*
AC automaton.
对 5e6 的树跑树剖? 有点意思.
16:30 读错题了.
18:03 通过 replace3.in/ans.
*/
