#include<bits/stdc++.h>
using namespace std;
const int N=1e4+20;
int n,m,k,c[15],mp[15][N];
long long ans=1e18,sum,dis[N];
bool cnt[N],vis[N];
struct node{
	int v,w;
};
vector<node> g[N];
long long spfa2(){
	for(int i=2;i<=n+k;i++){
		dis[i]=1e18;
	}dis[1]=0;
	long long sum=0;
	memset(vis,0,sizeof(vis));
	vis[1]=1;
	queue<int> q;
	while(!q.empty()){
		q.pop();
	}
	q.push(1);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].v,w=g[u][i].w;
			if(!vis[v]&&w<dis[v]){
				dis[v]=w;
			}
		}
		if(u<=n){
			for(int i=1;i<=k;i++){
				if(cnt[i+n]&&!vis[i+n]){
					if(mp[i][u]<dis[i+n]){
						dis[i+n]=mp[i][u];
					}
				}
			}
		}
		int p=0,val=INT_MAX;
		for(int i=1;i<=n+k;i++){
			if(i>=1&&i<=n){
				if(!vis[i]&&dis[i]<val){
					val=dis[i];
					p=i;
				}
			}
			else{
				if(cnt[i]){
					if(!vis[i]&&dis[i]<val){
						val=dis[i];
						p=i;
					}
				}
			}
		}
		if(!p){
			return sum;
		}
		sum+=val;
		vis[p]=1,dis[p]=0;
		q.push(p);
	}
	return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&mp[i][j]);
			g[i+n].push_back({j,mp[i][j]});
			g[j].push_back({i+n,mp[i][j]});
		}
	}
	for(int i=0;i<(1<<k);i++){
		sum=0;
		for(int j=1;j<=k;j++){
			if((i>>(j-1))&1){
				cnt[j+n]=1;
				sum+=c[j];
			}
			else{
				cnt[j]=0;
			}
		}
		ans=min(ans,sum+spfa2());
	}
	cout<<ans;
	return 0;
}