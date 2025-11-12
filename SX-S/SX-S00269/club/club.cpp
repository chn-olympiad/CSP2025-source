#include <bits/stdc++.h>
using namespace std;
long long t, n, a[100005][5], s, b[5], bj, maxs, s1;

struct ww {
	long long a1, b1, c1;
} c[100005];

bool cmp(ww p, ww q) {
	return p.a1 > q.a1;
}

void dfs(int x, int y) {

	if (x > n) {
		if (b[1] <= bj && b[2] <= bj && b[3] <= bj) {
			maxs = max(maxs, s);
		}
		return;
	}
	if (y > 3)
		return;
	s += a[x][y];
	b[y]++;
	dfs(x + 1, 1);
	s -= a[x][y];
	b[y]--;
	dfs(x, y + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;

	while (t--) {
		cin >> n;
		bj = n / 2;
		maxs = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			c[i].a1 = a[i][1];
			c[i].b1 = a[i][2];
			c[i].c1 = a[i][3];
			if (a[i][2] == 0 && a[i][3] == 0)
				s1++;
		}
		if (s1 == n) {
			sort(c + 1, c + n + 1, cmp);
			for (int i = 1; i <= bj; i++) {
				maxs += c[i].a1;
			}
		} else
			dfs(1, 1);
		cout << maxs << endl;
		maxs = 0;
		s1 = 0;
	}
	return 0;
}