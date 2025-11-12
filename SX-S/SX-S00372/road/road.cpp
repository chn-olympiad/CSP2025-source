#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <vector>
#define rep(a,b,c) for(int a=b;a<=c;a++)
using namespace std;
const int N = 2e4+5, M = 2e6+5;
const long long W = 1e9+5;
long long n, m, k, a, b, c, cnt, pre[N], dis[N], ww[N], tag[N], ans;
long long qwq[15][N], fl, fa[N];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	if (find(x) != find(y))
		fa[find(x)] = find(y);
}

struct edge {
	long long u, v, w;
} e[M];

bool cmp(edge a, edge b) {
	return a.w < b.w;
}

struct node {
	long long to, w;
	bool operator<(node b) {
		return w < b.w;
	}
};

void kruskal() {
	sort(e + 1, e + m + 1, cmp);
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if (find(u) == find(v))
			continue;
		merge(u, v);
		ans += w;
		if ((++cnt) == n - 1)
			break;
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	rep(i, 1, m) cin >> a >> b >> c, e[i] = {a, b, c};
	rep(i, 1, n) fa[i] = i;
	pre[1] = 1;
	rep(i, 1, k) {
		int tot;
		cin >> tot;
		ww[i + n] = tot;
		if (tot == 0)
			fl ++;
		vector<node> v;
		rep(j, 1, n) {
			cin >> qwq[i][j];
			v.push_back({j, qwq[i][j]});
		}
		sort(v.begin(), v.end());
		rep(ii, 0, min(n - 2, 1ll * 133)) {
			rep(j, ii + 1, n - 1) {
				e[++m] = {v[ii].to, v[j].to, ww[i + n] + v[ii].w + v[j].w};
			}
		}
		//printf("%d %d %d\n", v[0].to, v[1].to, ww[i + n] + v[0].w + v[1].w);
	}
	kruskal();
	cout << ans;
	return 0;
}
