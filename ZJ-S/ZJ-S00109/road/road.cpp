#include <bits/stdc++.h>
using namespace std;
int n, m, k, c[15][10005], cnt = 0;
long long ans = 0;
int g[10003][10003];
struct node{
	int u, v, w;
}edge[1000005];
bool cmp(node x, node y){
	return x.w < y.w;
}
int fa[10005], num = 0;
int find(int x){
	while (fa[x] != x)  x = fa[x];
	return x;
}
void Kruskal(){
	sort(edge+1, edge+cnt+1, cmp);
	for (int i=1; i <= cnt; i++){
		int uu = find(edge[i].u), vv = find(edge[i].v);
		if (uu == vv)  continue;
		fa[vv] = uu;
		ans += edge[i].w;
		if (++num == n-1)  return ;
	}
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i=1; i <= n; i++)  fa[i] = i;
	if (k == 0){
		for (int i=1; i <= m; i++){
			int u, v, w;
			cin >> u >> v >> w;
			edge[++cnt] = node{u, v, w};
		}	
		for (int i=1; i <= n; i++){
			for (int j=1; j <= n; j++){
				if (g[i][j])  edge[++cnt] = node{i, j, g[i][j]};
			}
		}
		Kruskal();
		cout << ans;
	}
	else {
		for (int i=1; i <= n; i++){
			for (int j=1; j <= n; j++)  g[i][j] = 1e9+5;
		}
		for (int i=1; i <= m; i++){
			int u, v, w;
			cin >> u >> v >> w;
			if (u > v)  swap(u, v);
			g[u][v] = w;
		}
		for (int j=1; j <= k; j++){
			for (int l=0; l <= n; l++)  cin >> c[j][l];
		}
		bool flag = 1;
		for (int i=1; i <= k; i++){
			if (c[k][0]){
				flag = 0;
				break;
			}
		}
		if (flag){
			for (int i=1; i <= n; i++){
				for (int j=i+1; j <= n; j++){
					for (int l=1; l <= k; l++){
						if ((long long)c[k][i] + (long long)c[k][j] > (long long)1e9)  continue;
						g[i][j] = min(g[i][j], c[k][i] + c[k][j]);
					}
				}
			}
			for (int i=1; i <= n; i++){
				for (int j=i; j <= n; j++){
					if (g[i][j] != 1e9+5)  edge[++cnt] = node{i, j, g[i][j]};
				}
			}	
			Kruskal();
			cout << ans;
		}
	}
	return 0;
}
//I really can't work it out :( I won't like or trust this government anymore. :(
