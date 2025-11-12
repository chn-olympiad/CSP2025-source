#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e4 + 5, M = 1e6 + 5, K = 15;
int n, m, k, c[K], a[K][N], atl[N][N];
struct str{
	int u, v, w;
}rd[M];
bool cmp(str x, str y){
	return x.w < y.w;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) cin >> rd[i].u >> rd[i].v >> rd[i].w;
	for (int i = 1; i <= k; i++){
		cin >> c[i];
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	}
	for (int i = 1; i <= m; i++) atl[u[i]][v[i]] = atl[v[i]][u[i]] = w[i];
	if (k == 0){
		bool t[N] = {0}, f = 1; long long ans = 0;
		sort (rd + 1, rd + m + 1, cmp);
		for (int i = 1; i <= n - 1; i++) ans += rd[i].w;
		cout << ans; return 0;
	}
	return 0;
}
