#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n, dp[N], ans;

struct nodee {
	int x, y, z;
} a[N];

//

void dfs(int k, int sa, int sb, int sc, int jiz) {
	if (k > n) {
		ans = max(ans, jiz);
		return;
	}
	if (sa > 0) {
		dfs(k + 1, sa - 1, sb, sc, jiz + a[k].x);
	}
	if (sb > 0) {
		dfs(k + 1, sa, sb - 1, sc, jiz + a[k].y);
	}
	if (sc > 0) {
		dfs(k + 1, sa, sb, sc - 1, jiz + a[k].z);
	}
	return;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		bool v = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
			if (a[i].y != 0 || a[i].z != 0) {
				v = 1;
			}
			dp[i] = a[i].x;
		}
		if (!v) {
			sort(dp + 1, dp + n + 1);
			int sum = 0;
			for (int i = n; i > n - (n / 2); i--) {
				sum += dp[i];
			}
			cout << sum << "\n";
			continue;
		}
		dfs(1, n / 2, n / 2, n / 2, 0);
		cout << ans << "\n";
		ans = 0;
	}
	return 0;
}
/*
10
3004 4255 17336
11894 5756 17092
8150 14715 10991
5149 16652 16780
11524 11996 5433
7690 10472 19935
1184 6516 9246
3231 5570 10010
8426 16992 4654
18955 13977 16657
RP在上午用光了，呵
*/