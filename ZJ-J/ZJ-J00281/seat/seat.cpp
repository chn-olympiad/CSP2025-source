#include <bits/stdc++.h>
using uint = unsigned;
using lint = long long;
using pii = std::pair<int, int>;

namespace mtyt {
	constexpr int N = 110;
	
	int n, m, a[N], id[N];
	
	void main() {
		freopen("seat.in", "r", stdin);
		freopen("seat.out", "w", stdout);
		std::cin.tie(0)->sync_with_stdio(0);
		std::cin >> n >> m;
		for (int i = 0; i < n * m; ++i) std::cin >> a[i], id[i] = i;
		std::sort(id, id + n * m, [](int x, int y){
			return a[x] > a[y];
		});
		int pos = -1;
		for (int i = 0; i < n * m; ++i) {
			if (id[i] == 0) {
				pos = i;
				break;
			}
		}
		std::cout << pos / n + 1 << " ";
		if ((pos / n + 1) & 1) {
			std::cout << pos % n + 1 << std::endl;
		} else {
			std::cout << n - pos % n << std::endl;
		}
	}
}

int main() {
	mtyt::main();
	return 0;
}
