#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
vector<int>e[10002],c[10002];
int a[12],g[12][10002];
int f[10002];
int fa[10002];
struct Edge{
	int u,v,w;
}edge[1000002];
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void Kruscal(){
	int ans=0;
	sort(edge+1,edge+1+m,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	int st=n,t=0;
	while(st>1){
		++t;
		int x=find(edge[t].u),y=find(edge[t].v);
		if(x!=y){
			--st;
			fa[y]=x;
			ans+=edge[t].w;
		}
	}
	printf("%lld",ans);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&edge[i].u,&edge[i].v,&edge[i].w);
		e[edge[i].u].push_back(edge[i].v);
		e[edge[i].v].push_back(edge[i].u);
		c[edge[i].u].push_back(edge[i].w);
		c[edge[i].v].push_back(edge[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&a[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&g[i][j]);
		}
	}
	Kruscal();
	return 0;
}