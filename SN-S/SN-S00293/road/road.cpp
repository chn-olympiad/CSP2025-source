#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e4+10,M=1e6+10,K=11,inf=1e18+7;
int n,m,k,tot,fa[N+N],cnt;
int h[M+M],len;
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
struct node{
	int u,v,w;
}e[M],g[M];
vector<node>r[N*K+N];
int c[K],a[K][N];
bool cmp(node a,node b){return a.w<b.w;}
int work(int s){
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=len;i++)r[i].clear();
	for(int i=1;i<=tot;i++)r[g[i].w].push_back(g[i]);
	int ret=0;
	for(int i=1;i<=k;i++)
		if((1<<i-1)&s){
			ret+=c[i];
			for(int j=1;j<=n;j++)r[a[i][j]].push_back((node){n+i,j,a[i][j]});
		}
	for(int i=1;i<=len;i++){
		for(auto t:r[i]){
			if(find(t.u)==find(t.v))continue;
			fa[find(t.u)]=find(t.v);
			ret+=h[t.w];
		}
	
	}return ret;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		if(find(e[i].u)==find(e[i].v))continue;
		g[++tot]=e[i];
		fa[find(e[i].u)]=find(e[i].v);
	}
	for(int i=1;i<=tot;i++)h[++len]=g[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j],h[++len]=a[i][j];
	}
	sort(h+1,h+len+1);len=unique(h+1,h+len+1)-h-1;
	for(int i=1;i<=tot;i++)g[i].w=lower_bound(h+1,h+len+1,g[i].w)-h;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)a[i][j]=lower_bound(h+1,h+len+1,a[i][j])-h;
	int ans=inf;
	for(int s=0;s<(1<<k);s++)ans=min(ans,work(s));
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
