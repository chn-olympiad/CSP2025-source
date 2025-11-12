#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 510;
const int mod = 998244353;

LL n, m, c[N];
string s;

namespace subtask_1_to_2 {
	bool vis[12];
	LL res = 0;
	vector<int> order;
	
	void dfs(int u) {
		if (u == n + 1) {
			int cnt = 0;
			int ok = 0;
			for (int i = 0; i < n; i++) {
				int id = order[i];
				if (c[id] <= cnt) {
					cnt++;
				} else {
					if (s[i] == '1') {
						ok++;
					} else {
						cnt++;
					}
				}
			}
			if (ok >= m) {
				res++;
				res %= mod;
			}
			return;
		}
		
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				vis[i] = true;
				order.push_back(i);
				dfs(u + 1);
				order.pop_back();
				vis[i] = false;
			}
		}
	}
	
	void solve() {
		memset(vis, 0, sizeof vis);
		res = 0;
		dfs(1);
		cout << res << "\n";
	}	
};

void solve() {
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	
	subtask_1_to_2::solve();
}

int main() {
	#ifndef ZCX
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	#endif
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T = 1;
	// cin >> T;
	while (T--) {
		solve();
	} 
	
	return 0;
}
