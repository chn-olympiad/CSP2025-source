#include <bits/stdc++.h>
using namespace std;
int e[10005][10005];
int e2[15][10005];
int c[10005], a[15][10005], b[10005];
int n, m, k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	memset(e,0x3f,sizeof(e));
	for(int i = 1;i <= m;i ++){
		int u, v, w;
		cin >> u >> v >> w;
		e[u][v] = min(e[u][v],w);
		e[v][u] = e[u][v];
	}
	for(int i = 1;i <= k;i ++){
		cin >> c[i];
		for(int j = 1;j <= n;j ++)cin >> a[i][j];
	}
	int ans = 0;
	for(int i = 1;i <= n;i ++){
		for(int j = i + 1;j <= n;j ++){
			int sum = e[i][j];
			int mnp = -1;
			for(int u = 1;u <= k;u ++){
				int v = 0;
				if(!e2[u][i])v += a[u][i];
				if(!e2[u][j])v += a[u][j];
				if(!b[u])v += c[u];
				if(v < sum){
					mnp = u;
					sum = v;
				}
			}
			ans += sum;
			if(mnp != -1){
				b[mnp] = 1;
				e2[mnp][i] = e2[mnp][j] = 1;
			}
		}
	}
	cout << ans;
	return 0;
}