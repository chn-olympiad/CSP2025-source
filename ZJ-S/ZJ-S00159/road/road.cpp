#include<bits/stdc++.h>
using namespace std;

int n, m, k, ans = INT_MAX;
int c[15][10005];
int vis[10005];
struct node{
	int x, w;
	bool flag;
};
vector<node> edge[10005];

void dfs(int x, int cnt){
	bool flag = true;
	for(int i = 1; i <= n && flag; i++){
		if(vis[i] == 0) flag = false;
	}
	if(flag){
		ans = min(ans, cnt);
		return;
	}
	for(int i = 0; i < edge[x].size(); i++){
		if(vis[edge[x][i].x]) continue;
		if(edge[x][i].flag == false){
			edge[x][i].flag = true;
			dfs(edge[x][i].x, cnt + edge[x][i].w);
			edge[x][i].flag = false;
		}
		else{
			dfs(edge[x][i].x, cnt);
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		edge[u].push_back({v, w});
		edge[v].push_back({u, w});
	}
	for(int i = 1; i <= k; i++){
		for(int j = 0; j <= n; j++) cin >> c[i][j];
	}
	
	for(int i = 1; i <= n; i++) dfs(i, 0);
	cout << ans;
	
	return 0;
}
