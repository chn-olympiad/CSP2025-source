#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int t, n, c[4], bo[N];

struct node {
	int x, ii, jj, gx;
} a[3 * N];

bool cmp(node u, node o) {
	return u.gx > o.gx;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			bo[i] = 0;
			for (int j = 1; j <= 3; j++) {
				int u;
				cin >> u;
				a[++cnt].x = u;
				a[cnt].ii = i;
				a[cnt].jj = j;
			}
			a[cnt - 2].gx = a[cnt - 2].x - max(a[cnt - 1].x, a[cnt].x);
			a[cnt - 1].gx = a[cnt - 1].x - max(a[cnt - 2].x, a[cnt].x);
			a[cnt].gx = a[cnt].x - max(a[cnt - 1].x, a[cnt - 2].x);
		}
		c[1] = c[2] = 0;
		c[3] = 0;
		sort(a + 1, a + cnt + 1, cmp);
		int ans = 0, o = 0;
		cnt = 0;
		while (o < n) {
			node tmp = a[++cnt];
			if (bo[tmp.ii] == 0) {
				if (c[tmp.jj] < n / 2) {
					c[tmp.jj]++;
					ans += tmp.x;
					o++;
					bo[tmp.ii] = 1;
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/