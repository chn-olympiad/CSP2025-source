#include<bits/stdc++.h>
#define int long long 
#define PII pair<int,int>
#define PVG PII,vector<PII>,greater<PII>
using namespace std;
const int N=1e4+5;
int n,m,k,fans=1e18;
vector<PII>g[N*12];
int a[N];
bool vis[N];
struct node{
	int num,id;
}dis[N];
void dijk(int s){
	memset(vis,0,sizeof vis);
	memset(dis,0x7f,sizeof dis);
	for(int i=1;i<=n*(k+1);i++)dis[i].id=s;
	priority_queue<PVG>q;
	q.push({0,s});
	dis[s].num=0;
	while(q.size()){
		int u=q.top().second;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto [v,w]:g[u]){
			if(dis[v].num>dis[u].num+w){
				dis[v].num=dis[u].num+w;
				dis[v].id=u;
				q.push({dis[v].num,v});
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int minn=1e18;
		for(int j=0;j<=k;j++){
			minn=min(minn,dis[i+j*n].num-dis[dis[i+j*n].id].num);
		}
		ans+=minn;
	}
	fans=min(ans,fans);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		int c;cin>>c;
		for(int u=1;u<=n;u++)cin>>a[u];
		for(int u=1;u<=n;u++){
			g[u].push_back({u+i*n,c});
			g[u+i*n].push_back({u,0});
			for(int v=u+1;v<=n;v++){
				g[u+i*n].push_back({v+i*n,a[u]+a[v]});
				g[v+i*n].push_back({u+i*n,a[u]+a[v]});
			}
		}
	}
	dijk(4);
//	for(int i=1;i<=n;i++)dijk(i);
	cout<<fans;
	return 0;
}