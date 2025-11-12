#include <bits/stdc++.h>
using namespace std;
#define read(x) scanf("%d",&x)
const int inf=0x3f3f3f3f;
const int N=1e6+10;
int n,m,k,vis[10000+10],dis[10000+10],cost[10000+10],ans=inf;
struct node{
	int to,val;
};
vector<node>G[N];
bool check(){
	for(int i=1;i<=m;i++)
		if(!vis[i])return false;
	return true;
}
void dfs(int rt,int fa,int cnt){
	vis[rt]=1;
	if(check()){
		ans=min(ans,cnt);
		return;
	}
	for(int i=0;i<G[rt].size();i++){
		int to=G[rt][i].to,val=G[rt][i].val;
		if(to==fa) continue;
		if(vis[to]) continue;
		dfs(to,rt,cnt+val+cost[to]);
	}
	vis[rt]=0;
}
int main()
{
  	freopen("road.in","r",stdin);
  	freopen("road.out","w",stdout);
	read(n);read(m);read(k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		read(u);read(v);read(w);
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	for(int i=m+1;i<=m+k;i++){
		read(cost[i]);
		for(int j=1;j<=n;j++){
			int k;read(k);
			G[i].push_back({j,k});
			G[j].push_back({i,k});
		}
	}
	dfs(1,0,0);
	printf("%d",ans+1);
	return 0;
}
