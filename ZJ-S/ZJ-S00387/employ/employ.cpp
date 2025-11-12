#include <iostream>

#define MOD 998244353

int n = 0;
int m = 0;
std::string prob;
int lim[501] = {};
int ans = 0;
bool vis[501] = {};
int pre[501] = {};

void dfs(int p, int sum) {
	if (p > n) {
		ans = (ans + (sum >= m)) % MOD;
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (vis[i]) {
			continue;
		}
		vis[i] = true;
		int add = 1;
		if (prob[p - 1] == '0') {
			add = 0;
		}
		if (p - 1 - sum >= lim[i]) {
			add = 0;
		}
		dfs(p + 1, sum + add);
		vis[i] = false;
	}
}

void solve() {
	int s = 0;
	for (int i = 0; i < n; ++i) {
		s += prob[i] - '0';
	}
	if (s == n) {
		ans = pre[n];
		return;
	}
	if (m == 1) {
		int dir = 0;
		for (int i = 0; i < n; ++i) {
			if (prob[i] == '1') {
				dir = i;
				break;
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (lim[i] > dir) {
				++ans;
			}
		}
		ans = (ans * pre[n - 1]) % MOD;
		return;
	}
	dfs(1, 0);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	pre[0] = 1;
	for (int i = 1; i <= 500; ++i) {
		pre[i] = (pre[i - 1] * i) % MOD;
	}
	std::cin >> n >> m;
	std::cin >> prob;
	for (int i = 1; i <= n; ++i) {
		std::cin >> lim[i];
	}
	
	solve();
	
	std::cout << ans;
	
	return 0;
}
