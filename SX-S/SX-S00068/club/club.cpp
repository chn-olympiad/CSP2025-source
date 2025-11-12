#include <bits/stdc++.h>
using namespace std;

void file() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
}

int n, t, a[100005][5], c1, c2, c3, ans;
vector<int> g;

int main() {
	file();
	cin >> t;
	while (t--) {
		ans = c1 = c2 = c3 = 0;
		cin >> n;
		g.clear();
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", a[i] + 1, a[i] + 2, a[i] + 3);
			if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3])
				c1++, ans += a[i][1];
			if (a[i][2] > a[i][1] && a[i][2] >= a[i][3])
				c2++, ans += a[i][2];
			if (a[i][3] > a[i][1] && a[i][3] > a[i][2])
				c3++, ans += a[i][3];
		}
		int f = 0;
		if (c1 > n / 2) {
			for (int i = 1; i <= n; i++)
				if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3])
					g.emplace_back(a[i][1] - max(a[i][2], a[i][3]));
			f = c1 - n / 2;
		} else if (c2 > n / 2) {
			for (int i = 1; i <= n; i++)
				if (a[i][2] > a[i][1] && a[i][2] >= a[i][3])
					g.emplace_back(a[i][2] - max(a[i][1], a[i][3]));
			f = c2 - n / 2;
		} else if (c3 > n / 2) {
			for (int i = 1; i <= n; i++)
				if (a[i][3] > a[i][1] && a[i][3] > a[i][2])
					g.emplace_back(a[i][3] - max(a[i][1], a[i][2]));
			f = c3 - n / 2;
		}
		sort(g.begin(), g.end());
		for (int i = 0; i < f; i++)
			ans -= g[i];
		cout << ans << "\n";
	}
	return 0;
}
