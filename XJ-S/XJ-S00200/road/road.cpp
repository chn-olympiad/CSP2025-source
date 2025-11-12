#include<bits/stdc++.h>
using namespace std;
const int N = 10005,inf = 999999999;
long long ans = 0;
priority_queue<pair<int,int> > q;
int vis[N],d[N],a[N];
struct node{long long v,w;};
vector <node> e[N];
long long n,m,k,c;
void prim(int s){
	for (int i = 1;i <= n;i++) d[i] = inf;
	d[s] = 0;q.push({0,s});
	while(q.size()){
		int u = q.top().second;q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		ans += d[u];
		for (auto ed : e[u]){
			long long v = ed.v,w = ed.w;
			if (d[v] > w){
				d[v] = w;
				q.push({-d[v],v});
			}
		}
	}
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++){
		long long u,v,w;
		cin >> u >> v >> w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for (int i = 1;i <= k;i++){
		cin >> c;
		for (int j = 1;j <= n;j++) cin >> a[j];
		for (int i = 1;i <= n;i++){
			for (int j = i + 1;j <= n;j++){
				long long u = i,v = j,w = c+a[i]+a[j];
				e[u].push_back({v,w});
				e[v].push_back({u,w});
			}
		}
	}
	prim(1);
	cout << ans;
	return 0;
}
