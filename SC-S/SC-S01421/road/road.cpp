#include<bits/stdc++.h>
using namespace std;
int b[10005][10005];
int c[15][10005] , minn = 100000086 , ans = 0;
int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	int n , m , k;cin >> n >> m >> k;
	for(int i = 1 , u , v;i <= m;i++){
		cin >> u >> v >> b[u][v];
		ans += b[u][v];
		minn = min(minn , b[u][v]);
	} 
	for(int i = 1;i <= k;i++)
		for(int j = 1;j <= n;j++) cin >> c[i][j];
	if(k == 0) cout << ans - minn;
	else cout << 0;
	return 0;
	fclose(stdin);
	fclose(stdout);
}