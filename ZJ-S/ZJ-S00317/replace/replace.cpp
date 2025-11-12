#include <bits/stdc++.h>
using uint = unsigned;
using lint = long long;
using pii = std::pair<int, int>;

namespace mtyt {
	constexpr int N = 2e5 + 10;
	
	int n, q;
	std::string t1, t2, s[N][2];
	
	namespace bf {
		int main() {
			int ans = 0;
			for (int i = 1; i <= n; ++i) {
				auto pos = t1.find(s[i][0]);
				while (pos != std::string::npos) {
					std::string boom = t1;
					boom.replace(pos, s[i][1].size(), s[i][1]);
					if (boom == t2) ++ans;
					pos = t1.find(s[i][0], pos + 1);
				}
			}
			return ans;
		}
	}
	
	void main() {
		freopen("replace.in", "r", stdin);
		freopen("replace.out", "w", stdout);
		std::cin.tie(0)->sync_with_stdio(0);
		std::cin >> n >> q;
		for (int i = 1; i <= n; ++i) std::cin >> s[i][0] >> s[i][1];
		while (q--) {
			std::cin >> t1 >> t2;
			if (t1.size() != t2.size()) std::cout << "0\n";
			else std::cout << bf::main() << "\n";
		}
		std::cout.flush();
	}
}

int main() {
	mtyt::main();
	return 0;
}
