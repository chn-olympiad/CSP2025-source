#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+20;
const ll inf=1e9;
int n,m,k,cnt;
ll a[15][N],c[N],ans,dis[N];
struct node{
	int v;
	ll w;
};
vector<node> V[N];
void dfs(){
	queue<int> q;
	q.push(1);
	dis[1]=0;
	while(!q.empty()){
		int u=q.front(),flag=0;
		q.pop();
		if(u<=n)	cnt++;
		
		for(int i=0;i<V[u].size();i++){
			int v=V[u][i].v;
			int w=V[u][i].w;
			if(v>n)	flag=c[v-n];
			if(dis[v]>dis[u]+w+flag){
				if(dis[v]!=inf)	ans-=dis[v]-dis[u];
				dis[v]=dis[u]+w+flag;
				ans+=w+flag;
				q.push(v);
			}
		}
	}
	printf("%lld",ans);
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		scanf("%d%d%d",&u,&v,&w);
		V[u].push_back((node){v,w});
		V[v].push_back((node){u,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			V[j].push_back((node){i+n,a[i][j]});
			V[i+n].push_back((node){j,a[i][j]});
		}
	}
	for(int i=1;i<=n+k;i++){
		dis[i]=inf;
	}
	dfs();
	return 0;
}