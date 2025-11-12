#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e4 + 5, K = 11, MAX = 1 << K, M = 1e6 + 5;
const ll INF = 1e17;
int n, m, k;
int fa[N], cnt[MAX], dep[N];
ll a[K][N], c[N];
vector<int> S[K];
struct Edge {
	int u, v;
	ll w;
	bool operator<(Edge b) {
		return w < b.w;
	}
}edge[M], now[M];
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}

bool merge(int u, int v) {
	u = find(u), v = find(v);
	if(u == v)return false;
	if(dep[u] < dep[v])swap(u, v);
	if(dep[u] == dep[v])dep[u] ++;
	fa[v] = u;
	return true;
}

ll solve1(int tp) {
	ll minn = 0;
	for (int i = 1; i <= n + k; i++)fa[i] = i, dep[i] = 1;
	int p = 0, res = n;
//	cout << res << '\n';
	for (int i = 1; i <= k; i++) {
		if(tp & (1 << (i - 1))) {
			res ++;
//			cout << "ins " << i << '\n';
			minn += c[i];
			for (int j = 1; j <= n; j++) {
				now[++p] = {n + i, j, a[i][j]};
			}
		}
	}
	sort(now + 1, now + p + 1);
	int l = 0, r = 0;
	while(true) {
		if(l == m) {
			r ++;
			if(merge(now[r].u, now[r].v)) {
				minn += now[r].w;
				res --;
			}
		}else if(r == p) {
			l ++;
			if(merge(edge[l].u, edge[l].v)) {
				minn += edge[l].w;
				res --;
			}
		}else{
			Edge nnow = now[r + 1];
			if(edge[l + 1].w < nnow.w) {
				nnow = edge[l + 1];
				l ++;
			}else r ++;
//			cout << nnow.u << ' ' << nnow.v << '\n';
			if(merge(nnow.u, nnow.v)) {
				minn += nnow.w;
				res --;
			}
		}
//		cout << l << ' ' << r << ' ' << minn << ' ' << res << '\n';
		if(res == 1) {
			return minn;
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
//	cout << n << ' ' << m << ' ' << k << '\n';
	for (int i = 1; i <= m; i++) {
		int u, v;
		ll w;
		scanf("%d%d%lld", &u, &v, &w);
		edge[i] = {u, v, w};
	}
	sort(edge + 1, edge + m + 1);
	for (int i = 1; i <= k; i++) {
		scanf("%lld", &c[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%lld", &a[i][j]);
		}
	}
	ll ans = INF;
	for (int i = 0; i < (1 << k); i++) {
//		cout << i << '\n';
		ans = min(ans, solve1(i));
	}
	printf("%lld", ans);
	return 0;
}