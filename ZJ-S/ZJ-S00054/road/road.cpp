#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+15,maxk=15;

int n,m,k,d[maxk];
long long dis[maxn],val[maxk],ans;
bool vis[maxn];

struct Edge{
	int v;
	long long w;
};
vector<Edge> g[maxn];

struct Node{
	int u,v;
	long long w;
	friend bool operator < (const Node a,const Node b){
		return a.w>b.w;
	}
};

void Prim(){
	priority_queue<Node> que;
	que.push({0,1,0});
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	int cnt=0;
	while (cnt<n){
		int lst=que.top().u;
		int u=que.top().v;
		que.pop();
		if (vis[u]){
			continue;
		}
		vis[u]=true;
		if (u<=n){
			cnt++;
		}else{
			d[u-n]++;
			val[u-n]=dis[u];
		}
		if (lst>n){
			d[lst-n]++;
		}
		ans+=dis[u];
		for (int i=0;i<(int)g[u].size();i++){
			int v=g[u][i].v;
			long long w=g[u][i].w;
			if (w<dis[v]){
				dis[v]=w;
				que.push({u,v,dis[v]});
			}
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	while (m--){
		int u,v;
		long long w;
		scanf("%d %d %lld",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for (int u=1;u<=k;u++){
		scanf("%lld",&val[u]);
		for (int v=1;v<=n;v++){
			long long w;
			scanf("%lld",&w);
			g[v].push_back({u+n,val[u]+w});
			g[u+n].push_back({v,w});
		}
	}
	Prim();
	for (int i=1;i<=k;i++){
		if (vis[i+n] && d[i]<2){
			ans-=val[i];
		}
	}
	printf("%lld",ans);
	return 0;
}
