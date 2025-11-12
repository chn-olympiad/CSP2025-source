//! expect: 28
#include <bits/stdc++.h>
constexpr int N = 510, Q = 998244353;

int n, m, c[N];
char s[N];

auto force() -> int {
	int cnt = 0, ord[n + 1];
	std::iota(ord + 1, ord + 1 + n, 1);
	do {
		int tot = 0;
		for (int i = 1; i <= n && n - i + 1 + tot >= m; i++) {
			if (s[i] == '0' || i - tot - 1 >= c[ord[i]]) continue;
			if (++tot >= m) break;
		}
		cnt += tot >= m;
	} while (std::next_permutation(ord + 1, ord + 1 + n));
	return cnt;
}

auto is_special() -> bool {
	for (int i = 1; i <= n; i++) if (s[i] == '0') return false;
	return true;
}

auto special() -> int {
	int v = 1;
	for (int i = 2; i <= n; i++) v = v * (long long)i % Q;
	return v;
}

auto solve() -> int {
	return is_special() ? special() : force();
}

auto main() -> int {
	freopen("employ.in", "r", stdin), freopen("employ.out", "w", stdout);
	scanf("%d%d\n", &n, &m), fgets(s + 1, N, stdin);
	for (int i = 1; i <= n; i++) scanf("%d", c + i);
	printf("%d", solve());
}
