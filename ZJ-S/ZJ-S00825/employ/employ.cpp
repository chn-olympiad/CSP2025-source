#include <bits/stdc++.h>
#define sz(x) (int)x.size()
const int N = 2e5 + 6;
int n, m, c[N], p[N]; std::string s;
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	std::cin >> n >> m >> s;
	for (int i = 1; i <= n; ++i)
		std::cin >> c[i], p[i] = i;
	int ans = 0;
	do {
		int cnt = 0, has = 0;
		for (int i = 1; i <= n; ++i) {
			if (cnt >= c[p[i]]) ++cnt;
			else {
				if (s[i - 1] == '1') ++has;
				else ++cnt;
			}
		}
		ans += has >= m;
	} while (std::next_permutation(p + 1, p + n + 1));
	std::cout << ans << "\n";
}
