#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+30;
const int M=3e6+10;
const int INF=0x3f3f3f3f;
int n,m,k;
struct Gragh{
	int v,w;
	bool operator<(const Gragh &B) const{
		return w>B.w;
	}
};
vector<Gragh> G[N];
int b[15][N];
int c[20];
int dis[N];
ll ans,sum;
bool vis[N];
void Prim(vector<Gragh> G1[]){
	for(int i=1;i<=n;i++){
		vis[i]=false,dis[i]=INF;
	}
	priority_queue<Gragh> pq;
	pq.push({1,0});
	dis[1]=0;
	int cnt=0;
	while(!pq.empty()){
		int u=pq.top().v;
		int w=pq.top().w;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=true;
		cnt++;
		sum+=w; 
		if(cnt==n) return;
		for(auto v:G1[u]){
			if(dis[v.v]>v.w){
				dis[v.v]=v.w;
				pq.push({v.v,dis[v.v]});
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	Prim(G);
	if(k==0){
		printf("%lld\n",sum);
		return 0;
	}
	ans=sum;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&b[i][j]);
		}
	}
	for(int i=1;i<(1<<k);i++){
		sum=0;
		vector<Gragh> G1[N]=G;
		int nw=i,pos=1;
		while(nw){
			if(nw&1){
				sum+=c[pos];
				for(int x=1;x<=n;x++){
					for(int y=1;y<x;y++){
						G1[x].push_back({y,b[pos][x]+b[pos][y]});
						G1[y].push_back({x,b[pos][x]+b[pos][y]});
					}
				}
			}
			pos++,nw>>=1;
		}
		Prim(G1);
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}
