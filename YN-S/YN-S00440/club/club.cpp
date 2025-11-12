/*********************************************************************
    程序名:club
    版权:
    作者:
    日期: 2025-11-01
    说明:
*********************************************************************/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int a[100010][5];
int n;
int ans;
priority_queue<pair<int, pair<int, int> > > q[2];
bool f[100010];

void dfs(int u, int x, int y, int z, int ret) {
	if (u > n) {
		ans = max(ans, ret);
		return ;
	}
	if (x + 1 <= n / 2)
		dfs(u + 1, x + 1, y, z, ret + a[u][1]);
	if (y + 1 <= n / 2)
		dfs(u + 1, x, y + 1, z, ret + a[u][2]);
	if (z + 1 <= n / 2)
		dfs(u + 1, x, y, z + 1, ret + a[u][3]);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		if (n <= 10) {
			memset(a, 0, sizeof(a));
			scanf("%d", &n);
			for (int i = 1; i <= n; i++) {
				scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
			}
			ans = 0;
			dfs(1, 0, 0, 0, 0);
			printf("%d\n", ans);
		} else {
			memset(a, 0, sizeof(a));
			scanf("%d", &n);
			for (int i = 1; i <= n; i++) {
				scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
				for (int j = 1; j <= 3; j++) {
					q[0].push(make_pair(a[i][j], make_pair(i, j)));
				}
			}
			int c[4];
			int t = 0;
			ans = 0;
			while (!q[t].empty()) {
				int ret = 0;
				memset(f, 0, sizeof(f));
				c[1] = 0;
				c[2] = 0;
				c[3] = 0;
				while (!q[t].empty()) {
					int x = q[t].top().second.first;
					int y = q[t].top().second.second;
					int d = q[t].top().first;
					q[t].pop();
					if (!f[x]) {
						if (c[y] + 1 <= n / 2) {
							c[y]++;
							f[x] = 1;
							ret += d;
							continue;
						}
					}
					q[!t].push(make_pair(d, make_pair(x, y)));
				}
				ans = max(ans, ret);
				t = !t;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
