#include<bits/stdc++.h>
using namespace std;
#define node pair<int,int>
int tot=1;//最短路行不行 
const int N=2e5+10;
long head[2*N],to[2*N],wyr[2*N],nxt[2*N],dis[2*N];
bool vis[2*N];
priority_queue<node,vector<node>,greater<node> > q;
void add(int u,int v,int w){
	to[tot]=v;
	nxt[tot]=head[u];
	wyr[tot]=w;
	head[u]=tot++;
}
void dij(int s){
	q.push({0,s});
	dis[s]=0;
	while(!q.empty()){
		long u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(dis[v]>dis[u]+wyr[i]){
				dis[v]=dis[u]+wyr[i];
				q.push({dis[v],v}); 
				vis[u]=0;
			}
		}
	} 
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		long c;
		cin>>c;
		for(int j=1;j<=n;j++){
			int a;
			cin>>a;
			add(i,j,a+c);
		}
	}
	memset(dis,0x3f3f3f3f,sizeof(dis));
	dij(1);
	long ans=0;
	for(int i=1;i<=n;i++)
		ans+=dis[i];
	cout<<ans;
	return 0;
}