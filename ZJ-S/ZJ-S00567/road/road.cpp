#include <bits/stdc++.h>
using namespace std;
const int M = 2100010,N = 10110;
struct node{
	int u,dis;
	bool operator < (const node &a) const{
		return a.dis < dis;
	}
};
struct edge{
	int v,w,nxt;
}e[M];
bool used[M];
int d[N],vis[N],hd[N],cnt;
void dij(int s){
	memset(d,-1,sizeof(d));
	priority_queue <node> q;
	q.push({s,0});
	d[s] = 0;
	while(!q.empty()){
		int u = q.top().u;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int j = hd[u];j;j = e[j].nxt){
			int v = e[j].v,w = e[j].w;
			if(d[v] == -1 || d[v] > d[u] + w){
				d[v] = d[u] + w;
				q.push({v,d[v]});
				used[j] = 1;
			}
		}
	}
}
void addedge(int u,int v,int w){
	e[++cnt] = {v,w,hd[u]};
	hd[u] = cnt;
}
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1,u,v,w;i <= m;i++){
		cin >> u >> v >> w;
		addedge(u,v,w);
		addedge(v,u,w);
	}
	for(int i = 1;i <= k;i++){
		int x;
		cin >> x;
		addedge(n+(i-1)*2+1,n+i*2,x);
		addedge(n+i*2,n+(i-1)*2+1,x);
		for(int j = 1,t;j <= n;j++){
			cin >> t;
			addedge(j,n+i*2-1,t);
			addedge(n+i*2,j,t);
		}
	}int ans = 0;
	for(int i = 1;i <= 1;i++){
		dij(i);
	}
	for(int i = 1;i <= cnt;i++) if(i%2 == 0 && (used[i] == 1 || used[i+1] == 1)) ans += e[i].w;
	cout << ans << endl;
	
	return 0;
}