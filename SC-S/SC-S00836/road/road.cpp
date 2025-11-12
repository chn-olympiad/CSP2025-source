#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+15;
const int M=1e6+1e5+5;
struct Edge{
	int v,w;
};
vector<Edge>e[N];
int n,m,k,a[N],dist[N],vis[N];
void init(){
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		e[u].push_back((Edge){v,w});
		e[v].push_back((Edge){u,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&a[i+n]);
		for(int j=1;j<=n;j++){
			int w;
			scanf("%lld",&w);
			e[i+n].push_back((Edge){j,w});
			e[j].push_back((Edge){i+n,w});
		}
	}
}
void dijkstra(int s){
	for(int i=0;i<=n+k;i++){
		dist[i]=INT_MAX;
	}
	dist[s]=0;
	while(1){
		int v=0;
		for(int i=1;i<=n+k;i++){
			if(dist[i]<dist[v]&&!vis[i]){
				v=i;
			}
		}
		if(v==0) break;
		vis[v]=1;
	//	printf("v:%lld\n",v);
		for(int i=0;i<e[v].size();i++){
			if(e[v][i].v<=n) dist[e[v][i].v]=min(dist[e[v][i].v],dist[v]+e[v][i].w);
			else dist[e[v][i].v]=min(dist[e[v][i].v],dist[v]+e[v][i].w+a[e[v][i].v]);
		}
	}
}
void solve(){
	init();
	int ans=0;
	for(int i=1;i<=n+k;i++){
		memset(vis,0,sizeof(vis));
		dijkstra(i);/*
		for(int j=1;j<=n+k;j++){
			printf("%d ",dist[j]);
		}
		puts("");*/
		int minn=INT_MAX;
		for(int j=1;j<=n;j++){
			if(dist[j]!=INT_MAX&&i!=j){
				minn=min(minn,dist[j]);
			//	printf("i:%lld %lld\n",i,dist[j]);	
			}
		}
		ans+=minn;
	}
	printf("%lld",ans);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	solve();
	return 0;
}