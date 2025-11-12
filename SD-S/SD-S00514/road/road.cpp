#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
const int N2=1e4+5;
ll c[N],n,m,k,uss[N],visn,vis[N2];
struct node{
	ll u,v,w,id;
}g[N];
ll fa[N],ans,cnt;
bool cmp(node x,node y){
	if(x.w==y.w) return x.u<y.u;
	else return x.w<y.w;
}
ll find(ll x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int flag=1;
	scanf("%lld%lld%lld",&n,&m,&k);
	visn=n;
	if(k==0) flag=0;
	for(int i=1;i<=m;i++){
		ll u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		g[i].u=u,g[i].v=v,g[i].w=w,g[i].id=0;
		vis[g[i].u]=2;
		vis[g[i].v]=2;
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",c+i);
		if(c[i]!=0) flag=0;
		for(int j=1;j<=n;j++){
			ll w;
			scanf("%lld",&w);
			if(w!=0) flag=0;
			cnt++;
			g[m+cnt].u=n+i,g[m+cnt].v=j,g[m+cnt].w=w+c[i],g[m+cnt].id=i;
		}
	}
	if(flag){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n+k;i++) fa[i]=i;
	sort(g+1,g+m+cnt+1,cmp);
	for(int i=1;i<=m+cnt;i++){
		if(visn<=0) break;
		int x=find(g[i].u);
		int y=find(g[i].v);
		if(x==y) continue;
		if(vis[g[i].u]==2) visn--,vis[g[i].u]=1;
		if(vis[g[i].v]==2) visn--,vis[g[i].v]=1;
		fa[x]=y;
		ans+=g[i].w;
		if(g[i].id){
			if(uss[g[i].id]) ans-=c[g[i].id];
			else uss[g[i].id]=1;
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
*/
