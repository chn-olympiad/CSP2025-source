// 但愿能过
// CCF 求你了

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const int N = 2e5 + 10, M = 5e6 + 10, INF = 2e9;
const int c = 13331, P = 1e9 + 7;

int n, q;
string a, b;

struct Tree {
	int idx, ts;
	vector<vector<int>> tr;
	vector<int> L, R;
	
	inline int newnode() {
		tr.push_back(vector<int>(26, 0));
		L.push_back(0), R.push_back(0);
		return ++ idx;
	}
	
	Tree() {
		idx = ts = 0;
		tr.push_back(vector<int>(26, 0));
		L.push_back(0), R.push_back(0);
		tr.push_back(vector<int>(26, 0));
		L.push_back(0), R.push_back(0);
		idx = 0;
	}
	
	void dfs(int u) {
		L[u] = ++ ts;
		for (int i = 0; i < 26; ++ i )
			if (tr[u][i]) {
				dfs(tr[u][i]);
			}
		R[u] = ts;
	}
	
	int insert0(int l, bool f = false) {
		int p = 0;
		for (int j = l - 1; ~j; -- j ) {
			int &t = tr[p][a[j] - 'a'];
			if (!t) {
				if (f) return p;
				t = newnode();
			}
			p = t;
		}
		return p;
	}
	
	int insert1(int r, bool f = false) {
		int p = 0;
		for (int j = r + 1; j < (int)a.size(); ++ j ) {
			int &t = tr[p][a[j] - 'a'];
			if (!t) {
				if (f) return p;
				t = newnode();
			}
			p = t;
		}
		return p;
	}
};
vector<Tree> T;

map<pair<int, int>, int> mp;
int cnt;
int x[N], y[N];		// 这个字符串，对应到两颗 Trie 上，是哪个点 
int res[N];
int ID[N];		// 第 i 个串的中间部分的hs 

struct Node {
	int x, l, r, d;
	
	Node() {}
	Node(int _x, int _l, int _r, int _d) {
		x = _x, l = _l, r = _r, d = _d;
	}
	
	bool operator <(const Node &h) const {
		return x != h.x ? x < h.x : l != h.l ? l < h.l : r != h.r ? r < h.r : d < h.d;
	}
};

vector<vector<Node>> que;

struct Fenwick {
	int n;
	vector<int> tr;
	
	void init(int m) {
		n = m;
		tr = vector<int>(n + 1, 0);
	}
	
	void modify(int x, int d) {
		for (int i = x; i <= n; i += i & -i) tr[i] += d;
	}
	
	int query(int x) {
		int res = 0;
		for (int i = x; i; i -= i & -i) res += tr[i];
		return res;
	}
}BIT;

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> q;
	for (int i = 1; i <= n; ++ i ) {
		a.clear(), b.clear();
		cin >> a >> b;
		
		if (a == b) {
			ID[i] = -1;
			continue;
		}
		
		int l = 0;
		while (a[l] == b[l]) l ++ ;
		int r = (int)a.size() - 1;
		while (a[r] == b[r]) r -- ;
		
		int hs1 = 0, hs2 = 0;
		for (int i = l; i <= r; ++ i ) hs1 = (1ll * hs1 * c + a[i]) % P;
		for (int i = l; i <= r; ++ i ) hs2 = (1ll * hs2 * c + b[i]) % P;
		
		int id;
		if (!mp.count({hs1, hs2})) {
			mp[{hs1, hs2}] = cnt ++ ;
			T.push_back(Tree()), T.push_back(Tree());
			que.push_back(vector<Node>());
			id = cnt - 1;
		} else {
			id = mp[{hs1, hs2}];
		}
		ID[i] = id;
		
		x[i] = T[id * 2].insert0(l);
		y[i] = T[id * 2 + 1].insert1(r);
	}
	
	for (int i = 0; i < cnt * 2; ++ i ) T[i].dfs(0);
	
	for (int i = 1; i <= q; ++ i ) {
		cin >> a >> b;
		
		int l = 0;
		while (a[l] == b[l]) l ++ ;
		int r = (int)a.size() - 1;
		while (a[r] == b[r]) r -- ;
		
		int hs1 = 0, hs2 = 0;
		for (int i = l; i <= r; ++ i ) hs1 = (1ll * hs1 * c + a[i]) % P;
		for (int i = l; i <= r; ++ i ) hs2 = (1ll * hs2 * c + b[i]) % P;
		
		int id;
		if (!mp.count({hs1, hs2})) {
			continue;
		} else {
			id = mp[{hs1, hs2}];
		}
		
		int p0 = T[id * 2].insert0(l, true);
		int p1 = T[id * 2 + 1].insert1(r, true);
		
		que[id].push_back(Node(T[id * 2].L[p0], T[id * 2 + 1].L[p1], INF, i));
	}
	
	for (int i = 1; i <= n; ++ i ) {
		int id = ID[i];
		if (id == -1) continue;
		
		int a = T[id * 2].L[x[i]];
		int b = T[id * 2].R[x[i]];
		int l = T[id * 2 + 1].L[y[i]];
		int r = T[id * 2 + 1].R[y[i]];
		
		que[id].push_back(Node(a, l, r, 1));
		que[id].push_back(Node(b + 1, l, r, -1));
	}
	
	for (int i = 0; i < cnt; ++ i ) {
		BIT.init(T[i * 2 + 1].tr.size() + 5);
		sort(que[i].begin(), que[i].end());
		
		for (auto p : que[i]) {
			int l = p.l, r = p.r, d = p.d;
			if (r == INF) {
				res[d] = BIT.query(l);
			} else {
				BIT.modify(l, d);
				BIT.modify(r + 1, -d);
			}
		}
	}
	
	for (int i = 1; i <= q; ++ i ) cout << res[i] << '\n';
	
	return 0;
}
