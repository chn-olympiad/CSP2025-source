#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
const int MAXN = 1e5 + 7;
int a[MAXN][4], n, cnt1, cnt2, cnt3;
int f[MAXN];

int dfs(int x) {
	if (x > n) {
		int ans = 0;

		for (int i = 1; i <= n; i++)

			ans += a[i][f[i]];
		return ans;
	}

	int ans = -1;

	if (cnt1 < n / 2)
		cnt1++, f[x] = 1,
		               ans = std::max(ans, dfs(x + 1)), cnt1--;

	if (cnt2 < n / 2)
		cnt2++, f[x] = 2,
		               ans = std::max(ans, dfs(x + 1)), cnt2--;

	if (cnt3 < n / 2)
		cnt3++, f[x] = 3,
		               ans = std::max(ans, dfs(x + 1)), cnt3--;
	f[x] = 0;
	return ans;
}
bool f1, f2;

struct node {
	int x;
	bool operator<(const node y)const {
		return x > y.x;
	}
};
std::priority_queue<node> q;
int T;

int main() {
	std::freopen("club.in", "r", stdin);
	std::freopen("club.out", "w", stdout);
	std::cin >> T;

	while (T--) {

		std::cin >> n;

		for (int i = 1; i <= n; i++) {

			std::cin >> a[i][1] >> a[i][2] >> a[i][3];

			if (a[i][2] != 0)
				f1 = 1;

			if (a[i][3] != 0)
				f2 = 1;
		}

		if (f1 && f2)
			std::cout << dfs(1) << "\n";

		else if (!f1 && !f2) {
			int ans = 0;

			for (int i = 1; i <= n; i++)

				q.push({a[i][1]});

			for (int i = 1; i <= n / 2; i++)

				q.pop();

			for (int i = 1; i <= n / 2; i++)

				ans += q.top().x, q.pop();
			std::cout << ans << "\n";
		}
	}

	return 0;
}