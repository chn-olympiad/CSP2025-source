#include <bits/stdc++.h>;
using namespace std;
int n, m, k, cost;
bool ans[10005][10005], kong[10005];

struct s {
	int c, a[10005];
} a[15];

struct ll {
	int b, e, c;

} l[1000005];

bool cmp(ll o, ll p) {
	return o.c <= p.c;
}


bool dfs(bool vis[10005][10005], int h, bool u[10005], int c) {
	if (h >= n)
		return 1;
	if (c >= n * 2) {
		return 0;
	}
	for (int i = 0; i < m; i++) {
		for (int j = i; j < m; j++) {
			if (vis[i][j] == 1) {
				if (u[i] == 0) {
					h++;
					u[i] = 1;
				}
				if (u[j] == 0) {
					h++;
					u[j] = 1;
				}
				return dfs(vis, h, u, c + 1);
				vis[i][j] = 0;
				return dfs(vis, h		, u, c + 1);
			}
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		cin >> l[i].b >> l[i].e >> l[i].c;
	}
	sort(l, l + m, cmp);

	for (int i = 0; i < k; i++) {
		cin >> a[i].c;
		for (int j = 0; j < n; j++) {
			cin >> a[i].a[j];
		}
	}

	if (k == 0) {
		for (int i = 0; i < m; i++) {
			ans[l[i].b][l[i].e] = 1;
			ans[l[i].e][l[i].b] = 1;
			cost += l[i].c;
			if (dfs(ans, 0, kong, 0) == 1) {
				cout << cost << endl;
				return 0;
			}
		}

	}
	cout << cost;
	return 0;
}
//JM350234
//JM350235
