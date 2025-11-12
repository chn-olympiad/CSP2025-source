#include <bits/stdc++.h>
using namespace std;
int n,m,k,w[1010][1010],a[15][1010],c[1010];
long long ans;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	int u,v,ww;
	for(int i = 1; i <= m; i++) {
		scanf("%d%d%d",&u,&v,&ww);
		w[u][v] = ww;
		w[v][u] = ww;
	}
	for(int i = 1; i <= k; i++) {
		scanf("%d",&c[i]);
		for(int j = 1; j <= n; j++) {
			scanf("%d",&a[i][j]);
			a[j][i] = a[i][j];
		}
	}
	for(int l = 1; l <= k; l++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				if(a[l][i] + a[l][j] + c[l] < w[i][j]) {
					w[i][j] = a[l][i]+a[l][j]+c[l];
				}
			}
		}
	}
	for(int i = 1;i <= n;i++){
		long long sum = 0;
		for(int j = 1;j <= n;j++){
			if(j != i)sum += w[i][j];
		}
		ans = max(ans,sum);
	}
	printf("%d",ans);
	return 0;
}
