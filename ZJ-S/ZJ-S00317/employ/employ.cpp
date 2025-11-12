#include <bits/stdc++.h>
using uint = unsigned;
using lint = long long;
using pii = std::pair<int, int>;

namespace mtyt {
	constexpr int N = 510;
	constexpr int MOD = 998244353;
	
	char s[N];
	int n, m, a[N];
	
	namespace mequaln {
		lint ans = 1;
		void main() {
			for (int i = 1; i <= n; ++i) {
				(ans *= i) %= MOD;
				if (s[i] == '0' || a[i] == 0) {
					std::cout<< 0 << std::endl;
					exit(0);
				}
			}
			std::cout << ans << std::endl;
		}
	}
	
	namespace bf {
		lint ans;
		int p[N];
		
		void main() {
			for (int i = 1; i <= n; ++i) p[i] = i;
			do {
				int cnt = 0;
				for (int i = 1; i <= n; ++i)
					cnt += cnt >= a[p[i]] || s[i] == '0';
				ans += m + cnt <= n;
			} while (std::next_permutation(p + 1, p + n + 1));
			std::cout << ans << std::endl;
			exit(0);
		}
	}
	
	void main() {
		freopen("employ.in", "r", stdin);
		freopen("employ.out", "w", stdout);
		std::cin.tie(0)->sync_with_stdio(0);
		std::cin >> n >> m >> (s + 1);
		for (int i = 1; i <= n; ++i) std::cin >> a[i];
		if (n <= 11) bf::main();
		else if (m == n) mequaln::main();
		else bf::main();
	}
}

int main() {
	mtyt::main();
	return 0;
}
