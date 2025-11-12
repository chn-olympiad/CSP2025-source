#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=2e4+10;
const int MAXN=2e6+10;
int n,m,k,a[15][N],c[15];
int tot,head[N<<1],ver[N<<1],nxt[N<<1],w[N];
int dis[MAXN],vis[MAXN],ans;
priority_queue<pii,vector<pii>,greater<pii>> q;
void add(int x,int y,int z){
	ver[++tot]=y;
	w[tot]=z;
	nxt[tot]=head[x];
	head[x]=tot;
}
void dij(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=nxt[i]){
			int v=ver[i],w2=w[i];
			if(dis[u]+w2<dis[v]){
				dis[v]=dis[u]+w2;
				q.push({dis[v],v});
			}
		}
	}
	return ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,z;
		cin>>u>>v>>z;
		add(u,v,z);
		add(v,u,z);
	}
	bool flag=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) flag=1;
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
//	A&aaa	
	if(!flag){
		n+=k;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				add(n+i,j,a[i][j]);
				add(j,n+1,a[i][j]);
			}
		}
	}
//	A	32pts
	dij(1);
	int maxx=-1;
	for(int i=1;i<=n;i++) maxx=max(maxx,dis[i]);
	cout<<maxx;
//	A&aaa  <48pts
	return 0;
}
