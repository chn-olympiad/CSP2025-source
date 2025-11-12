#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
typedef long long LL;
const int N = 1e6 + 10;

namespace problem {

int n;
int a[N][5];
int ct[5];
int nn[N];
int c[N];
void solve() {
	int T;
	std::cin >> T;
	while (T--) {
		ct[0] = ct[1] = ct[2] = 0;
		std::cin >> n;
		LL ans = 0;
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i][0] >> a[i][1] >> a[i][2];
			c[i] = inf;
			int now = 0;
			for (int j = 0 ; j < 3; j++) {
				if (a[i][j] > a[i][now]) {
					now = j;
				}
			}
			ct[now]++;
			ans += a[i][now];
			nn[i] = now;
		}
		int d = 0;
		for (int i = 0; i < 3; i++) {
			if (ct[i] > n / 2)
				d = i;
		}
		for (int i = 1; i <= n; i++) {
			if (nn[i] != d)
				continue;
			for (int j = 1; j <= 2; j++) {
				int now = (nn[i] + j) % 3;
				c[i] = std::min(c[i], a[i][nn[i]] - a[i][now]);
			}
		}
		std::sort(c + 1, c + n + 1);
		//std::cout << ans << " " << ct[d] << "\n";
		for (int i = 1; i <= ct[d] - n / 2; i++) {
			ans -= c[i];
		}
		std::cout << ans << "\n";
	}
}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	problem::solve();
	return 0;
}