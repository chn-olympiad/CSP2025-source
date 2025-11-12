#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
	int n;
	std::cin >> n;
	
	std::vector<std::array<int, 3>> a(n);
	std::vector<int> b(n);
	std::array<int, 3> cnt{0, 0, 0};
	int ans = 0;
	for (int i = 0; i < n; i ++) {
		std::cin >> a[i][0] >> a[i][1] >> a[i][2];
		const int o = std::max_element(a[i].begin(), a[i].end()) - a[i].begin();
		b[i] = o;
		++ cnt[o];
		ans += a[i][o];
	}
	
	int o = -1;
	for (int i = 0; i < 3; i ++) {
		if (cnt[i] > n / 2) {
			o = i;
			break;
		}
	}
	
	if (o == -1) {
		std::cout << ans << '\n';
		return;
	}
	
	const int o0 = !o;
	const int o1 = 1 + 2 - o0 - o;
	const int need = cnt[o] - n / 2;
	std::vector<int> f;
	f.reserve(n);
	for (int i = 0; i < n; i ++) {
		if (b[i] == o) {
			f.push_back(std::max(a[i][o0] - a[i][o], a[i][o1] - a[i][o]));
		}
	}
	std::sort(f.begin(), f.end(), std::greater<int>());
	ans += std::accumulate(f.begin(), f.begin() + need, 0);
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	int t;
	std::cin >> t;
	
	while (t --) {
		solve();
	}

	return 0;
}

