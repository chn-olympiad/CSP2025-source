#include<bits/stdc++.h>
#define int long long
const int slen=1e4+10,slen1=1e6+10;
using namespace std;
struct info{
  int to,w;
};
vector<info>e[slen1*2];
struct info1{
  int dian,w;
}pq[slen];
int n,m,k,dis[slen];
int head=0,tail=0,ans=0;
bool vis[slen];
signed main(){
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  bool flag=true;
  memset(dis,0x7f,sizeof(dis));
  scanf("%d%d%d",&n,&m,&k);
  for(int i=1;i<=m;i++){
  	int u,v,w;scanf("%d%d%d",&u,&v,&w);
  	e[u].push_back({v,w});e[v].push_back({u,w});
  }
  for(int i=1;i<=k;i++){
	int c;scanf("%d",&c);
	for(int j=1;j<=n;j++){
	  int x,bh=n+i;
	  scanf("%d",&x);;
	  if(x+=c!=0) flag=false;
	  //cout<<bh<<" "<<x<<endl;
	  e[bh].push_back({j,x});e[j].push_back({bh,x});
	}
  }
  if(flag&&k!=0) {cout<<0;return 0;}
  dis[1]=0;pq[tail].dian=1;pq[tail++].w=0;
  while(head<=tail){
  	int node=pq[head++].dian;
  	if(vis[node]) continue;
  	vis[node]=true;
  	for(int i=0;i<e[node].size();i++){
  	  int to=e[node][i].to;
  	  if(dis[to]>dis[node]+e[node][i].w&&!vis[to]){
  	  	dis[to]=dis[node]+e[node][i].w;//cout<<dis[to]<<" ";
  	  	ans+=e[node][i].w;
  	  	pq[tail].dian=to;pq[tail++].w=dis[to];
	  }
	}
  }
  cout<<ans;
  return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 0 0 0 0
0 0 0 0 0
*/