#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool _st;
const int N=1e4+10,M=1e6+10,K=11;
int n,m,k,c[K],a[K][N];
struct node{
	int u,v,w;
	bool operator < (const node &x) const{
		return w<x.w;
	}
}e[30000000];
int fa[N];
int find(int x){
	return fa[x]==x ? x : fa[x]=find(fa[x]); 
}
ll Kos(int cnt){
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e+1,e+cnt+1);
	ll ans=0,tot=0;
	for(int i=1;i<=cnt;i++){
		int u=find(e[i].u),v=find(e[i].v);
		if(u!=v){
			ans+=e[i].w;
			if(++tot==n-1) break;
			fa[u]=v;
		}
	}
	return ans;
}
bool _ed;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	bool fg=1;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		fg&=(c[i]==0);
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	if(fg){
		int cnt=m;
		for(int i=1;i<=k;i++)
			for(int u=1;u<=n;u++)
				for(int v=1;v<u;v++)
				e[++cnt]={v,u,a[i][u]+a[i][v]};
		cout<<Kos(cnt);
		return 0;
	}
	ll ans=1e18;
	for(int i=0;i<(1<<k);i++){
		int cnt=m;
		ll sum=0;
		for(int j=1;j<=k;j++)
			if((i>>(j-1))&1){
				sum+=c[j];
				for(int u=1;u<=n;u++)
					for(int v=1;v<u;v++)
						e[++cnt]={v,u,a[j][u]+a[j][v]};
			}
		ans=min(ans,Kos(cnt)+sum);
	}
	cout<<ans;
//	cerr<<abs(&_ed-&_st)/1024.0/1024.0;
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
