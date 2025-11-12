#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
struct edge{
	int u,v,w;
}e[1100005];
int l[10005][15],c[15];
bool cmp(edge o,edge p){
	return o.w<p.w;
}
int fa[11005];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>l[j][i];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++) e[m+(i-1)*n+j]={n+i,j,l[j][i]};
	}
	sort(e+1,e+m+k*n+1,cmp);
	int ans=0;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m+k*n;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)==find(v)) continue;
		fa[find(u)]=find(v);
		ans+=w;
	}
	cout<<ans;
	return 0;
}
