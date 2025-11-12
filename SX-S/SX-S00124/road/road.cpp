#include <bits/stdc++.h> //部分分：特殊性质A
using namespace std;
#define ll long long
#define int ll
#define i128 _int128_t
#define endl '\n'
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1e6+100;
const int MaxN = 1e9;
int minn = MaxN, sum = MaxN, n, m, k;
vi c, vit;
vector<vi> a;

struct XXX {
	int n, l, r;
};

void dfs(int ans, int dep) {
	if (dep == n) {
		sum = min(sum, ans);
	}
	for (int i = 2; i <= n; i++) {
		if (!vit[i])
			continue;
		for (int j = i + 1; j < n; j++) {
			vit[j] = 1;
			dfs(ans + a[i][j], dep++);
		}
	}
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	a.assign(n + 1, vi(n + 1, MaxN));
	c.assign(k + 1, {});
	vit.assign(n + 1, 0 );
	for (int i = 1; i <= m; i++) {
		int  x, y, w;
		cin >> x >> y >> w;
		if (y > x)
			swap(x, y);
		a[x][y] = w;
	}
	for (int i = 1; i <= k; i++) {
		int x;
		cin >> x;
		for (int j = 1; j <= n; j++) {
			cin >> c[i];
		}
		for (int h = 1; h <= n; i++) {
			for (int j = h + 1; j <= n; j++) {
				if (a[h][j] > c[h] + c[j]) {
					a[h][j] = c[h] + c[j];
				}
			}
		}
	}//留言：老师我两两连通不会T^T
	for (int i = 1; i <= n; i++) {
		vit[i] = 1;
		dfs(a[1][i], 1);
		vit[i] = 0;
	}
	cout << sum;
	return 0;
}