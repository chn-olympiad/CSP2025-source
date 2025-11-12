#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, k, c[15], a[15][20010], cnt_e, fa[20010];
bool caseA = 1;

struct edge{
	int u, v, w;
} e[2000010];

bool cmp(edge x, edge y){
	return x.w < y.w;
}

int find(int x){
	return (x == fa[x]) ? x : (fa[x] = find(fa[x]));
}

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cnt_e++;
		cin >> e[cnt_e].u >> e[cnt_e].v >> e[cnt_e].w;
	}
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		if(c[i] != 0) caseA = 0;
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= n; j++){
			e[++cnt_e] = {n+i, j, a[i][j]};
		}
	}
	sort(e+1, e+cnt_e+1, cmp);
	int cntedge = 0, ans = 0;
	iota(fa+1, fa+n+k+1, 1);
	for(int i = 1; i <= cnt_e && cntedge < n + k; i++){
		int u = find(e[i].u), v = find(e[i].v);
		if(u != v){
			fa[u] = v;
			cntedge++;
			ans += e[i].w;
		}
	}
	cout << ans << '\n';
	return 0;
}