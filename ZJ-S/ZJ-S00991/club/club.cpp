#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

const int N = 1e5 + 10;

int n;
int a[N][4];

std::vector <int> d[4];

bool cmp (int x, int y) {
	return a[x][3] - a[x][2] > a[y][3] - a[y][2];
}

void solve() {
	std::cin >> n;
	for (int i = 1; i <= 3; ++i) {
		d[i].clear();
	}

	i64 ans = 0;
	for (int i = 1; i <= n; ++i) {
		int maxn = -1, maxi = 0;
		for (int j = 1; j <= 3; ++j) {
			std::cin >> a[i][j];
			if (a[i][j] > maxn) {
				maxn = a[i][j];
				maxi = j;
			}
		}
		std::sort(a[i] + 1, a[i] + 4);
		ans += a[i][3];
		d[maxi].push_back(i);
	}

	int maxs = 0, id = 0;
	for (int i = 1; i <= 3; ++i) {
		if (d[i].size() > maxs) {
			maxs = d[i].size();
			id = i;
		}
	}

	std::sort(d[id].begin(), d[id].end(), cmp);
	for (int i = maxs; i > n / 2; --i) {
		ans -= (a[d[id][i - 1]][3] - a[d[id][i - 1]][2]);
	}
	std::cout << ans << "\n";
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}