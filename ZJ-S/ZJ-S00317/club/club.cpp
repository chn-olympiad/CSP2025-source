#include <bits/stdc++.h>
using uint = unsigned;
using lint = long long;
using pii = std::pair<int, int>;

namespace mtyt {
	constexpr int N = 1e5 + 10;
	
	int testcase, n, m, a[N][3];
	
	namespace bf { // brute dp
		constexpr int NN = 5e3 + 10;
		
		int ans, f[2][NN][NN];
		
		void main() {
			memset(f[0], 0, sizeof f[0]), ans = 0;
			for (int i = 1; i <= n; ++i) {
				for (int j = 0; j <= std::min(i, m); ++j) {
					for (int k = 0; k <= std::min(i - j, m); ++k) {
						f[i & 1][j][k] = 0;
						if (j > 0) f[i & 1][j][k] = std::max(f[i & 1][j][k], f[i & 1 ^ 1][j - 1][k] + a[i][0]);
						if (k > 0) f[i & 1][j][k] = std::max(f[i & 1][j][k], f[i & 1 ^ 1][j][k - 1] + a[i][1]);
						if (i - j - k > 0) f[i & 1][j][k] = std::max(f[i & 1][j][k], f[i & 1 ^ 1][j][k] + a[i][2]);
					}
				}
			}
			for (int j = 0; j <= m; ++j) for (int k = m - j; k <= m; ++k)
				ans = std::max(ans, f[n & 1][j][k]);
			std::cout << ans << "\n";
		}
	}
	
	namespace A {
		int id[N];
		lint ans;
		bool check() {
			for (int i = 1; i <= n; ++i)
				if (a[i][1] != 0 || a[i][2] != 0) return false;
			return true;
		}
		void main() {
			ans = 0;
			for (int i = 1; i <= n; ++i) id[i] = i;
			std::sort(id + 1, id + n + 1, [](int x, int y){
				return a[x][0] > a[y][0];
			});
			for (int i = 1; i <= m; ++i) ans += a[id[i]][0];
			std::cout << ans << "\n";
		}
	}
	
	namespace B {
		lint ans;
		int id[N];
		
		struct cmp {
			bool operator()(int x, int y) const {
				return a[x][0] - a[x][1] > a[y][0] - a[y][1];
			}
		};
		
		std::priority_queue<int, std::vector<int>, cmp> heap;
		
		bool check() {
			for (int i = 1; i <= n; ++i)
				if (a[i][2] != 0) return false;
			return true;
		}
		
		void main() {
			ans = 0;
			for (int i = 1; i <= n; ++i) id[i] = i;
			std::sort(id + 1, id + n + 1, [](int x, int y){
				return a[x][0] > a[y][0];
			});
			for (int i = 1; i <= m; ++i) heap.emplace(id[i]);
			for (int i = m + 1; i <= n; ++i) {
				int p = id[i];
				if (a[p][0] - a[p][1] > a[heap.top()][0] - a[heap.top()][1]) {
					ans += a[heap.top()][1];
					heap.pop();
					heap.emplace(p);
				} else {
					ans += a[p][1];
				}
			}
			while (heap.size()) ans += a[heap.top()][0], heap.pop();
			std::cout << ans << "\n";
		}
	}
	
	void solve() {
		std::cin >> n, m = n >> 1;
		for (int i = 1; i <= n; ++i) std::cin >> a[i][0] >> a[i][1] >> a[i][2];
		if (n <= 500) bf::main();
		else if (A::check()) A::main();
		else if (B::check()) B::main();
		else bf::main();
	}
	
	void main() {
		freopen("club.in", "r", stdin);
		freopen("club.out", "w", stdout);
		std::cin.tie(0)->sync_with_stdio(0);
		for (std::cin >> testcase; testcase; --testcase) solve();
		std::cout.flush();
	}
}

int main() {
	mtyt::main();
	return 0;
}
