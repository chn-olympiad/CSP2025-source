#include<bits/stdc++.h>
using namespace std;
#define int long long
struct DSU{
	int fa[10050];
	void init(){
		for (int i = 0; i <= 10020; i++){
			fa[i] = i;
		}
	}
	int find(int x){
		if (fa[x] == x){
			return fa[x];
		}
		return fa[x] = find(fa[x]);
	}
	bool same(int x,int y){
		return find(x) == find(y);
	}
	void merge(int x,int y){
		fa[find(max(x,y))] = fa[find(min(x,y))]; 
	}
	bool OK(int n){
		for (int i = 1; i < n; i++){
			if (fa[i] != fa[i + 1]){
				return false;
			}
		}
		return true;
	}
	
}dsu;
struct Node{
	int u,v,w;
	bool operator < (const Node& rhs) const{
		return w > rhs.w;
	}
};
vector<Node> adj[100010];
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	dsu.init();
	priority_queue<Node> a;
	
	for (int i = 0; i < m; i++){
		int u,v,w;
		cin >> u >> v >> w;
		adj[u].push_back({u,v,w});
		adj[v].push_back({v,u,w});
		a.push({u,v,w});
	}
	for (int i = 1; i <= k; i++){
		int c;
		cin >> c;
		for (int j = 1; j <= n; j++){
			int x;
			cin >> x;
			adj[n + i].push_back({n + i,j,x + c});
			adj[j].push_back({j,n + i,x + c});
			a.push({n + i,j,x + c});
		}
	}
	int ans = 0;
	while(!a.empty()){
		Node now = a.top();
		a.pop();
		if (!dsu.same(now.u,now.v)){
			dsu.merge(now.u,now.v);
			ans += now.w;
		}
		if (dsu.OK(n)){
			cout << ans;
			return 0;
		}
	}
	
	return 0;
}
