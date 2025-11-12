#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
struct node{
	int u,v,w;
}e[1000010],g[200010];
inline bool operator < (node x,node y){
	return x.w<y.w;
}
int fa[200010];
inline int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
int v[20];
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1);
	int tot=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		if(find(e[i].u)==find(e[i].v)) continue;
		fa[find(e[i].u)]=find(e[i].v);
		g[++tot]=e[i];
	}
	for(int i=1;i<=k;i++){
		cin>>v[i];
		for(int j=1;j<=n;j++){
			tot++;
			g[tot].u=n+i,g[tot].v=j,cin>>g[tot].w;
		}
	}
	sort(g+1,g+tot+1);
	int ans=1e18;
	for(int s=0;s<(1<<k);s++){
		for(int i=1;i<=n+k;i++) fa[i]=i;
		int sum=0;
		for(int i=1;i<=k;i++) if(s&(1<<(i-1))) sum+=v[i];
		for(int i=1;i<=tot;i++){
			if(g[i].u>n && !(s&(1<<(g[i].u-n-1)))) continue;
			if(find(g[i].u)==find(g[i].v)) continue;
			fa[find(g[i].u)]=find(g[i].v),sum+=g[i].w;
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}