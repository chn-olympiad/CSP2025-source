#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e4 + 10, MAXM = 1e6 + 10, MAXK = 15;

struct node1 {
	long long u, v, w;
};

struct node2 {
	int c;
	int r[MAXN];
};
long long n, m, k, ans = 1e18;
int mp[MAXN][MAXN];
node1 road[MAXM];
node2 rk[MAXK];
int c[MAXK], mpx[MAXK][MAXN];
int mpnow[MAXN][MAXN], se[MAXN];
int chk[MAXK];
bool v[MAXN], vis;

int find() {
	int bh = 0;
	for (int i = 1; i <= n; i++) {
		if (v[i] == 0) {
			bh = i;
			break;
		}
	}
	return bh;
}

int cut() {
	int maxn = -1;
	for (int i = 1; i <= n; i++) {
		maxn = max(maxn, mpnow[i][se[i]]);
	}
	return maxn;
}

void dfsr(int cost, int dep) {
	if (dep == n) {
		if (find() != 0 && mpnow[n][find()] != 0) {
			long long nnow = cost + mpnow[n][find()];
			se[n] = find();
			ans = min(ans, nnow - cut());
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		vis = true;
		for (int j = 1; j < dep; j++) {
			if (j == i && dep == se[j]) {
				vis = false;
				break;
			}
		}
		if (v[i] != 0 || i == dep || mpnow[i][dep] == 0 || vis == false)
			continue;
		v[i] = 1;
		se[dep] = i;
		dfsr(cost + mpnow[dep][i], dep + 1);
		v[i] = 0;
	}
}

void build(int cnt, int cost) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			mpx[i][j] = 0;
		}
	}
	for (int i = 1; i <= cnt; i++) {
		for (int j = 1; j <= n; j++) {
			mpx[chk[i]][j] = rk[chk[i]].r[j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			mpnow[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;
			if (mp[i][j] == 0) {
				vis = false;
				for (int l = 1; l <= cnt; l++) {
					if (mpx[l][i] != 0 && mpx[l][j] != 0) {
						vis = true;
						if (mpnow[i][j] != 0)
							mpnow[i][j] = min(mpnow[i][j], mpx[l][i] + mpx[l][j]);
						else
							mpnow[i][j] = mpx[l][i] + mpx[l][j];
					}
				}
				if (vis == false) {
					mpnow[i][j] = 0;
				}
			} else {
				mpnow[i][j] = mp[i][j];
				for (int l = 1; l <= cnt; l++) {
					mpnow[i][j] = min(mpnow[i][j], mpx[l][i] + mpx[l][j]);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		v[i] = 0;
	}
	dfsr(cost, 1);
}

void dfsk(int dep, int cnt, int cost) {
	if (dep > k) {
		build(cnt, cost);
		return;
	}
	chk[cnt + 1] = dep;
	dfsk(dep + 1, cnt + 1, cost + rk[dep].c);
	dfsk(dep + 1, cnt, cost);
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> road[i].u >> road[i].v >> road[i].w;
		mp[road[i].u][road[i].v] = road[i].w;
		mp[road[i].v][road[i].u] = road[i].w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> rk[i].c;
		for (int j = 1; j <= n; j++) {
			cin >> rk[i].r[j];
		}
	}
	dfsk(1, 0, 0);
	cout << ans;
	return 0;
}