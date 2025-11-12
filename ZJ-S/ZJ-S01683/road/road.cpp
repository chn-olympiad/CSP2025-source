#include<bits/stdc++.h>
#define M 2000005
#define N 20005
#define ll long long
using namespace std;
int n,m,k;
bool f;
struct node{
	int u,v,w;
}e[M],d[M];
int cnt=0;
int c[15];
int a[15][N];
int fa[N];
ll ans=0;
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(x==fa[x]) return x;
	else return fa[x]=find(fa[x]);
}
bool vis[N];
bool check(int x){
	if(x<=n) return 1;
	return vis[x-n];
}
void dfs(int x){
	if(x==k+1){
		ll sum=0;
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=1;i<=k;i++) if(vis[i]) sum+=c[i];
		for(int i=1;i<=cnt;i++){
			if(!check(d[i].u) or !check(d[i].v)) continue;
			int tx=find(d[i].u),ty=find(d[i].v);
			if(tx!=ty){
				fa[tx]=ty;
				sum+=d[i].w;
			}
		}
		ans=min(ans,sum);
		return ;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
}
int main(){
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int tx=find(e[i].u),ty=find(e[i].v);
		if(tx!=ty){
			ans+=e[i].w;
			d[++cnt]=e[i];
			fa[tx]=ty;
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			d[++cnt]=(node){n+i,j,a[i][j]};
		}
	}
	sort(d+1,d+cnt+1,cmp);
	dfs(1);
	cout<<ans;
	return 0;
}