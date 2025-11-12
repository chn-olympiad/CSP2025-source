//! expect: 100
#include <bits/stdc++.h>
constexpr int N = 1e5 + 10;

template <typename T>
void read(T& v) {
	v = 0; char c;
	while (!isdigit(c = getchar()));
	do { v = (v << 1) + (v << 3) + (c ^ '0'); } while (isdigit(c = getchar()));
}

int n, c[N][3];

auto max(int i) -> int* {
	return std::max_element(c[i], c[i] + 3);
}

auto solve() -> int {
	read(n);
	for (int i = 1; i <= n; i++) read(c[i][0]), read(c[i][1]), read(c[i][2]);
	int sum = 0;
	std::vector<int> b[3];
	for (int i = 1; i <= n; i++) {
		int *p = max(i), v;
		v = *p, sum += v, *p = 0, b[p - c[i]].emplace_back(*max(i) - v);
	}
	auto &p = *std::max_element(b, b + 3, [](const auto &l, const auto &r) {
		return l.size() < r.size();
	});
	if ((int)p.size() > (n >> 1)) {
		std::sort(p.begin(), p.end(), std::greater<int>{});  // Why not use nth_element?
		sum += std::accumulate(p.begin(), p.begin() + (p.size() - (n >> 1)), 0);
	}
	return sum;
}

auto main() -> int {
	freopen("club.in", "r", stdin), freopen("club.out", "w", stdout);
	int t;
	for (read(t); t--; ) printf("%d\n", solve());
}
