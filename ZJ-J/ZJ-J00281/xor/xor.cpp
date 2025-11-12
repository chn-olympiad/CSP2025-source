#include <bits/stdc++.h>
using uint = unsigned;
using lint = long long;
using pii = std::pair<int, int>;

namespace mtyt {
	constexpr int N = 5e5 + 10, V = 3e6 + 10;
	
	int idx; pii range[N];
	int n, m, ans, a[N], s[N], nxt[V];
	
	void main() {
		freopen("xor.in", "r", stdin);
		freopen("xor.out", "w", stdout);
		std::cin.tie(0)->sync_with_stdio(0);
		std::cin >> n >> m;
		for (int i = 1; i <= n; ++i) std::cin >> a[i], s[i] = s[i - 1] ^ a[i];
		for (int i = n; i; --i) {
			nxt[s[i]] = i;
			int tar = s[i - 1] ^ m;
			if (nxt[tar]) range[++idx] = {i, nxt[tar]};
		}
		std::sort(range + 1, range + idx + 1, [](pii x, pii y){
			if (x.second != y.second) return x.second < y.second;
			return x.first > y.first;
		});
		for (int i = 1, r = 0; i <= idx; ++i) {
			if (range[i].first > r) {
				++ans;
				r = range[i].second;
			}
		}
		std::cout << ans << std::endl;
	}
}

int main() {
	mtyt::main();
	return 0;
}
