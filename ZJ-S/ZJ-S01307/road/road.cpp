#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int N = 1e4+5;
struct Node{
	int to, sz;
};
int ans, w[N], c[N], v[N], vis[N], u[N];
vector<int> G[N];
void dfs(int x){
	vis[x] = 1;
	for(int i = 0; i < G[x].size(); i++){
		if(!vis[G[x][i]])
			dfs(G[x][i]);
	}
	return ;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	for(int i = 1; i <= n; i++)
		for(int j = i+1; j <= n; j++){
			G[i].push_back(j);
			G[j].push_back(i);
		}
	for(int i = 1; i <= n; i++){
		memset(vis, 0, sizeof(vis));
		dfs(i);
		for(int j = 1; j <= n; j++)
			if(!vis[j])
				ans += w[j];
	}
	cout << ans;
	return 0;
}
