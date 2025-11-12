#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e4 + 2;
const int M = 2e6 + 2;
const int INF = 0x3f3f3f3f3f3f3f3fll;

int n, m, k;
int ww[N];
int c[12], cnt[1 << 10], ans[1 << 10], tot[1 << 10];
int f[N][1 << 10];
struct edge{
	int u, v, w, idx;
}eg[M];

int find(int x, int s){return x == f[x][s] ? x : (f[x][s] = find(f[x][s], s));}

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++){
		int u, v, w;  cin >> u >> v >> w;
		eg[i] = {u, v, w, 0};
	}
	for(int i = 1; i <= k; i ++){
		cin >> c[i];
		for(int j = 1; j <= n; j ++){
			int w;  cin >> w;
			eg[++ m] = {n + i, j, w, i};
		}
	}
	sort(eg + 1, eg + m + 1, [](edge x, edge y){
		return x.w < y.w;
	});
	for(int s = 0; s < (1 << k); s ++){
		for(int i = 1; i <= n + k; i ++)  f[i][s] = i;
		for(int i = 1; i <= k; i ++){
			if((s >> (i - 1)) & 1){
				ans[s] += c[i];
				tot[s] ++;
			}
		}
	}
	int res = INF;
	for(int s = 0; s < (1 << k); s ++){
		for(int i = 1; i <= m; i ++){
			if(cnt[s] == n + tot[s] - 1)  break;
			int u = eg[i].u, v = eg[i].v, w = eg[i].w, idx = eg[i].idx;
			if(idx && !((s >> idx - 1) & 1))  continue;
			int fu = find(u, s), fv = find(v, s);
			if(fu == fv)  continue;
//			if(s == 1)  cerr << u << ' ' << v << ' ' << w << '\n';
			f[fv][s] = fu;
			cnt[s] ++;
			ans[s] += w;
		}
		res = min(res, ans[s]);
	}
	cout << res;

	return 0;
}
