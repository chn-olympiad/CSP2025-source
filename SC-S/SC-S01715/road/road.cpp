#include <bits/stdc++.h>//带权图 
using namespace std;
vector<int> e[1000005];
int v,u,m,n,k,x,c;
int a[100015][100015];
int f[100025][100025][2];
int ans1 = 0,ans2 = 0x3f;
void dfs(int u,int fa){
	for(auto v : e[u]){
		if(v == fa){
			continue;
		}
		dfs(v,u);
		ans1 += a[v][u];
	}
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> v >> u >> x;
		e[u].push_back(v);
		e[v].push_back(u);
		a[u][v] = x;
		a[v][u] = x;
	}
	
	for(int i = 1;i <= k;i++){
		for(int j = 1;j <= n;j++){
			cin >> c;
			cin >> v;
			e[n + i].push_back(v);
		}
	}
	for(int i = 1;i <= n + k;i++){
		dfs(i,0);
		ans2 = min(ans1,ans2);
	}
	cout << ans2;
	return 0;
}