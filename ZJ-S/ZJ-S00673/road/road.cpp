#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 1e4 + 10, M = 1e6 + 10;
int n, m, k;
LL c[11];
LL a[11][N];
int fa[N];
LL ans;
struct edge{
	int u, v;
	LL w;
};
vector<edge> e;

int get(int x) {
	if(fa[x] == x) return x;
	return fa[x] = get(fa[x]);
}

bool cmp(edge x, edge y) {
	return x.w < y.w;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;++ i){
		int u, v;
		LL w;
		cin >> u >> v >> w;
		e.push_back({u, v, w});
	}
	for(int i = 1;i <= k;++ i){
		cin >> c[i];
		for(int j = 1;j <= n;++ j) cin >> a[i][j];
	}
	if(k == 0) {
		for(int i = 1;i <= n;++ i) fa[i] = i;
		sort(e.begin(), e.end(), cmp);
		for(auto x : e) {
			int fu = get(x.u), fv = get(x.v);
			if(fu != fv) {
				fa[fu] = fv;
				ans += x.w;
			}
		}
		cout << ans;
	} else {
		for(int u = 1;u <= n;++ u){
			for(int v = u + 1;v <= n;++ v){
				for(int i = 1;i <= k;++ i){
					e.push_back({u, v, c[i] + a[i][u] + a[i][v]});
				}
			}
		}
		for(int i = 1;i <= n;++ i) fa[i] = i;
		sort(e.begin(), e.end(), cmp);
		int cnt = 0;
		for(auto x : e) {
			int fu = get(x.u), fv = get(x.v);
			if(fu != fv) {
				fa[fu] = fv;
				ans += x.w;
				cnt++;
			}
			if(cnt == n - 1) break;
		}
		cout << ans;
	}
 	return 0;
}