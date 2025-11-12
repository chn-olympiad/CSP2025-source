//王子铭 SN-S00482 西安市曲江第一中学 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int n,m,k;
int a[15][10005],c[10005],vis[N];
int f[N];
vector<pair<int,int>>e[N];
void dijiskt(int s){
	for(int i = 1;i <= n;i ++){
		f[i] = 1e9+5;
	}
	priority_queue<vector<pair<int,int>>,vector<pair<int,int>>,greater<pair<int ,int>>> q;
	f[s] = 0;
	q.push_back({s,0});
	while(!q.empty()){
		auto it = q.front();
		int u = it.first;
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u] = 1;
		for(auto it:e[u]){
			int v = it.first,w = it.second;
			if(f[v]>f[u]+w){
				f[v] = f[u]+w;
				p.push_back({v,f[v]});
			} 
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i ++){
		int u,v,w;
		cin >> u >> v >> w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i = 1;i <= k;i ++){
		cin >> c[i];
		for(int j = 1;j <= n;j ++){
			cin >> a[i][j];
		}
	}
	dijiskt(1);
	int ans = 0;
	for(int i = 1;i <= n;i ++){
		ans += f[i];
	}
	cout << ans;
	return 0;
}
