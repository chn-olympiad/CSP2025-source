#include <bits/stdc++.h>

using i64 = long long;
using i128 = __int128;

constexpr int N = 200005;

constexpr i64 P = 1E18 + 1, Base = 131;

int n, q, cnt;
std::map<std::pair<i128, i128>, int> mp;

int offset(char c) {
	if (c == ' ') return 26;
	return c - 'a';
}
struct ACAM {
	struct Info {
		std::array<int, 27> f {};
		int cnt = 0, fail = 0;
		Info() {}
	};
	std::vector<Info> t;
	ACAM() {
		t.assign(2, Info {});
		t[0].f.fill(1);
	}
	void insert(std::string s) {
		int p = 1;
		for (auto c : s) {
			int rc = offset(c);
			if (!t[p].f[rc]) {
				t[p].f[rc] = t.size();
				t.emplace_back();
			}
			p = t[p].f[rc];
		}
		t[p].cnt++;
	}
	void work() {
		std::queue<int> q;
		q.push(1);
		while (!q.empty()) {
			int x = q.front(); q.pop();
			for (int c = 0; c < 27; c++) {
				if (t[x].f[c]) {
					t[t[x].f[c]].fail = t[t[x].fail].f[c];
					q.push(t[x].f[c]);
				} else t[x].f[c] = t[t[x].fail].f[c];
			}
		}
		
		int s = t.size();
		std::vector<std::vector<int>> adj(s);
		for (int i = 1; i < s; i++) adj[t[i].fail].push_back(i);
		auto dfs = [&](auto &&self, int x) -> void {
			for (int y : adj[x]) {
				t[y].cnt += t[x].cnt;
				self(self, y);
			}
		};
		dfs(dfs, 0);
	}
	int run(std::string s) {
		int p = 1, sum = 0;
		for (auto c : s) {
			sum += t[p].cnt;
			p = t[p].f[offset(c)];
		}
		sum += t[p].cnt;
		return sum;
	}
} ac[N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    
    std::cin >> n >> q;
    for (int i = 0; i < n; i++) {
    	std::string s, t;
    	std::cin >> s >> t;
    	int m = s.size();
    	int L = -1, R = -1;
    	for (int i = 0; i < m; i++) if (s[i] != t[i]) R = i;
    	for (int i = m - 1; i >= 0; i--) if (s[i] != t[i]) L = i;
    	if (L == -1) continue;
    	i128 sh = 0, th = 0;
    	for (int i = L; i <= R; i++) {
    		sh = (sh * Base + s[i]) % P;
    		th = (th * Base + t[i]) % P;
		}
		int idx;
		if (mp.count({sh, th})) idx = mp[{sh, th}];
		else idx = mp[{sh, th}] = cnt++;
		ac[idx].insert(s.substr(0, L) + " " + s.substr(R + 1, m - R - 1));
	}
	for (int i = 0; i < cnt; i++) ac[i].work();
	
	for (int i = 0; i < q; i++) {
		std::string s, t;
		std::cin >> s >> t;
    	int m = s.size();
    	int L = -1, R = -1;
    	for (int i = 0; i < m; i++) if (s[i] != t[i]) R = i;
    	for (int i = m - 1; i >= 0; i--) if (s[i] != t[i]) L = i;
    	if (L == -1) continue;
    	i128 sh = 0, th = 0;
    	for (int i = L; i <= R; i++) {
    		sh = (sh * Base + s[i]) % P;
    		th = (th * Base + t[i]) % P;
		}
		if (!mp.count({sh, th})) {
			std::cout << "0\n";
			continue;
		}
		int idx = mp[{sh, th}];
		std::cout << ac[idx].run(s.substr(0, L) + " " + s.substr(R + 1, m - R - 1)) << "\n";
	}

    return 0;
}