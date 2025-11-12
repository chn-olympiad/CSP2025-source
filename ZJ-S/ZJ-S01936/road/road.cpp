#include <bits/stdc++.h>
using namespace std;
long long a[10010][10010];
long long b[15][10010];
int vis[10010];
int n, m, k;
long long ans = 0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) a[i][j] = 0;
			else a[i][j] = 0x3f;
		}
	}
	while(m--){
		int u,v,w;
		cin >> u >> v >> w;
		a[u][v] = a[v][u] = w;
	}
	int cnt = 0;
	for(int i = 1; i <= k; i++){
		cin >> b[i][1];
		cnt++;
		for(int j = 2; j <= n+1;j++){
			cin >> b[i][j];
			a[n+cnt][j-1] = b[i][j];
		}
	}
	for(int l = 1; l <= n+cnt; l++){
		for(int j = 1; j <= n+cnt; j++){
			for(int i = 1; i <= n+cnt; i++){
				if(a[i][l]+a[l][j] < a[i][j]){
					a[i][j] = a[i][l]+a[l][j];
				}
				
			}
		}
	}
	for(int i = 1; i <= n+cnt; i++){
		long long min1 = 0x3f;
		for(int j = 1; j <= n+cnt; j++){
			min1 = min(min1,a[i][j]);
		}
		ans+=min1;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
