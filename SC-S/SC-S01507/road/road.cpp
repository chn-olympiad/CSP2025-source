//Ren5Jie4Di4Ling5%
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX = 1e4 + 10;
int a[MAX][MAX] ,dis[MAX][MAX] ,c[MAX];
const int inf = 1e9+ 10;
void init(int n) {
	for(int i=1;i <= n;i ++)
	for(int j=1;j <= n;j ++)
		if(i != j)dis[i][j] =inf;
}
void floyd(int n) {
	for(int k=1;k <= n;k ++)
	for(int i=1;i <= n;i ++)
	for(int j=1;j <= n;j ++)
		dis[i][j] = min(dis[i][j] ,dis[k][i] + dis[j][k]) ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout) ;
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0) ;
	int  n,m ,k; cin >> n >> m >> k;
	init(n) ;
	for(int i=1;i <= m;i ++) {
		int u ,v,w; cin >>u >> v>>w ;
		dis[u][v] = w;
		dis[v][u] = w;
	}
	floyd(n) ;
	for(int i=1;i <=k;i ++){
		cin >> c[i] ;
		for(int j =1;j <= n;j ++) {
			cin >> a[i][j] ;
		}
	}int ans = inf;
	for(int i=1;i <= n;i ++)
	for(int j=1;j <= n;j ++)
		if(i != j)ans = min(ans ,dis[i][j]) ;
	cout << ans;
	return 0;
}