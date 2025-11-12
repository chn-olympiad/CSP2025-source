#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
const int K = 20;
struct node{
	int v, w;
};
vector<node> g[N];
vector<int> nxt[N];
int c[K], a[N], dis[N];
int n, m, k, sum = 0, tot = 0;
bool vis[N], pp[N][N];
void spfa(int s){
	for(int i = 1; i <= n; i++) dis[i] = INT_MAX;
	queue<int> q;
	q.push(s);
	dis[s] = 0;
	vis[s] = 1;
	while(q.size()){
		int u = q.front(); q.pop();
		vis[u] = 0;
		for(int i = 0; i < g[u].size(); i++){
			int v = g[u][i].v, w = g[u][i].w;
			if(dis[v] > dis[u]+w){
				dis[v] = dis[u]+w;
				if(!vis[v]){
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin>>u>>v>>w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	tot = n;
	for(int i = 1; i <= k; i++){
		cin>>c[i];
		for(int j = 1; j <= n; j++){
			cin>>a[i];
			g[++tot].push_back({i, a[i]});
			g[i].push_back({tot, a[i]});
		}
	}
	for(int i = 1; i <= n; i++){
		spfa(i);
		int minn = INT_MAX, t;
		for(int j = 1; j <= n; j++){
			if(i == j) continue;
			if(minn > dis[j]) 
			minn = dis[j], t = j;
		}
		if(!pp[t][i])
			sum += minn; 
		pp[i][t] = 1;
	}
	cout<<sum;
	return 0;
}

