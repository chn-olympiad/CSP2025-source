#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int f[1025][1025];
int c[15];
bool vis[15];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i=1; i<=n+k; i++){
		for(int j=1; j<=n+k; j++){
			f[i][j] = 1e9+7;
		}
	}
	for(int i=1; i<=n+k; i++){
		f[i][i] = 0;
	}
	for(int i=1; i<=m; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		f[u][v] = w;
		f[v][u] = w;
	}
	for(int i=1; i<=k; i++){
		cin >> c[i];
		for(int j=1; j<=n; j++){
			int w;
			scanf("%d", &w);
			f[n+i][j] = w;
			f[j][n+i] = w;
		}
	}
	for(int l=1; l<=n+k; l++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				int add_l = 0;
				if(l>n && vis[l-n]==0){
					add_l+= c[l-n];
					vis[l-n] = 1;
				}
                
				f[i][j] = min(f[i][j], f[i][l]+f[l][j]+add_l);
			}
		}
	}
	int ans;
	for(int i=2; i<=n; i++){
		ans += f[i-1][i];
	}
	cout << ans;
	
	return 0;
} 
