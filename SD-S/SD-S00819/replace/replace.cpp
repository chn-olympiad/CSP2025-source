#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

struct AC {
	int n;
	std::vector<std::array<int, 26>> t;
	std::vector<int> pos, fail, len;
	std::vector<std::vector<int>> adj;
	
	AC(): n(1) {
		newNode();
	}
	int newNode() {
		const int id = t.size();
		std::array<int, 26> s;
		s.fill(-1);
		t.push_back(s);
		len.push_back(0);
		fail.push_back(-1);
		return id;
	}
	void insert(int id, const std::string &s) {
		const int n = s.size();
		int u = 0;
		for (int i = 0; i < n; i ++) {
			const int o = s[i] - 'a';
			if (t[u][o] == -1) {
				const int v = newNode();
				len[v] = len[u] + 1;
				t[u][o] = v;
			}
			u = t[u][o];
//			std::cout << u << ' ';
		}
//		std::cout << '\n';
		assert((int)pos.size() == id);
		pos.push_back(u);
	}
	void build() {
		n = t.size();
		std::queue<int> Q;
		fail[0] = -1;
		for (int o = 0; o < 26; o ++) {
			if (t[0][o] != -1) {
				fail[t[0][o]] = 0;
				Q.push(t[0][o]);
			} else {
				t[0][o] = 0;
			}
		}
		while (Q.size()) {
			const int u = Q.front();
			Q.pop();
			for (int o = 0; o < 26; o ++) {
				if (t[u][o] != -1) {
					fail[t[u][o]] = t[fail[u]][o];
					Q.push(t[u][o]);
				} else {
					t[u][o] = t[fail[u]][o];
				}
			}
		}
		
//		for (int u = 0; u < n; u ++) {
//			std::cout << fail[u] << ' ';
//		}
//		std::cout << '\n';
		
		adj.resize(n);
		for (int u = 1; u < n; u ++) {
			adj[fail[u]].push_back(u);
		}
	}
} ac0, ac1;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	int n, q;
	std::cin >> n >> q;
	
	for (int i = 0; i < n; i ++) {
		std::string s0, s1;
		std::cin >> s0 >> s1;
		
		ac0.insert(i, std::move(s0));
		ac1.insert(i, std::move(s1));
		
//		if (s0 == "l") {
//			std::cout << s0 << ' ' << s1 << '\n';
//		}
	}
	ac0.build();
	ac1.build();
	
	const int logN0 = std::__lg(ac0.n);
	const int logN1 = std::__lg(ac1.n);
	std::vector<std::vector<int>> fa0(logN0 + 1, std::vector<int>(ac0.n));
	std::vector<std::vector<int>> fa1(logN1 + 1, std::vector<int>(ac1.n));
	for (int i = 0; i < ac0.n; i ++) {
		fa0[0][i] = ac0.fail[i];
	}
	for (int i = 0; i < ac1.n; i ++) {
		fa1[0][i] = ac1.fail[i];
	}
	for (int i = 1; i <= logN0; i ++) {
		for (int j = 0; j < ac0.n; j ++) {
			if (fa0[i - 1][j] != -1) {
				fa0[i][j] = fa0[i - 1][fa0[i - 1][j]];
			}
		}
	}
	for (int i = 1; i <= logN1; i ++) {
		for (int j = 0; j < ac1.n; j ++) {
			if (fa1[i - 1][j] != -1) {
				fa1[i][j] = fa1[i - 1][fa1[i - 1][j]];
			}
		}
	}
	
	std::vector<std::vector<std::tuple<int, int, int>>> qry(ac0.n);
	
	for (int id = 0; id < q; id ++) {
		std::string s0, s1;
		std::cin >> s0 >> s1;
		
		const int n = s0.size();
		int l = 0, r = 0;
		for (int i = 0; i < n; i ++) {
			if (s0[i] != s1[i]) {
				l = i;
				break;
			}
		}
		for (int i = n - 1; i >= 0; i --) {
			if (s0[i] != s1[i]) {
				r = i;
				break;
			}
		}
		
//		std::cout << l << ' ' << r << '\n';
		
		int u0 = 0, u1 = 0;
		for (int i = 0; i < n; i ++) {
			const int o0 = s0[i] - 'a';
			const int o1 = s1[i] - 'a';
			u0 = ac0.t[u0][o0];
			u1 = ac1.t[u1][o1];
			
			if (i < r) {
				continue;
			}
			const int lim = i - l + 1;
			if (ac0.len[u0] < lim || ac1.len[u1] < lim) {
				continue;
			}
			
			int v0 = u0, v1 = u1;
			for (int i = logN0; i >= 0; i --) {
				if (fa0[i][v0] != -1 && ac0.len[fa0[i][v0]] >= lim) {
					v0 = fa0[i][v0];
				}
			}
			v0 = fa0[0][v0];
			for (int i = logN1; i >= 0; i --) {
				if (fa1[i][v1] != -1 && ac1.len[fa1[i][v1]] >= lim) {
					v1 = fa1[i][v1];
				}
			}
			v1 = fa1[0][v1];
//			std::cout << i << ' ' << u0 << ' ' << v0 << '\n';
			qry[u0].push_back(std::make_tuple(u1, 1, id));
			qry[u0].push_back(std::make_tuple(v1, -1, id));
			qry[v0].push_back(std::make_tuple(u1, -1, id));
			qry[v0].push_back(std::make_tuple(v1, 1, id));
		}
	}
	
	std::vector<std::vector<int>> upd(ac0.n);
	for (int i = 0; i < n; i ++) {
		upd[ac0.pos[i]].push_back(i);
	}
	std::vector<int> dfn(ac1.n), rdfn(ac1.n);
	int dfc = 0;
	auto dfs0 = [&](auto &&self, int u) -> void {
		dfn[u] = dfc ++;
		for (auto v : ac1.adj[u]) {
			self(self, v);
		}
		rdfn[u] = dfc;
	};
	dfs0(dfs0, 0);
	
	std::vector<int> fen(ac1.n);
	auto update = [&](int p, int k) {
		for (++ p; p <= ac1.n; p += p & -p) {
			fen[p - 1] += k;
		}
	};
	auto query = [&](int p) {
		int ans = 0;
		for (++ p; p; p -= p & -p) {
			ans += fen[p - 1];
		}
		return ans;
	};
	
	std::vector<i64> ans(q);
	auto dfs1 = [&](auto &&self, int u) -> void {
		for (auto i : upd[u]) {
			const int l = dfn[ac1.pos[i]];
			const int r = rdfn[ac1.pos[i]];
			update(l, 1);
			update(r, -1);
		}
		for (auto _ : qry[u]) {
			int v, o, id;
			std::tie(v, o, id) = _;
			ans[id] += o * query(dfn[v]);
		}
		for (auto v : ac0.adj[u]) {
			self(self, v);
		}
		for (auto i : upd[u]) {
			const int l = dfn[ac1.pos[i]];
			const int r = rdfn[ac1.pos[i]];
			update(l, -1);
			update(r, 1);
		}
	};
	dfs1(dfs1, 0);
	
	for (int i = 0; i < q; i ++) {
		std::cout << ans[i] << '\n';
	}

	return 0;
}

