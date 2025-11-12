#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+10,M=1e6+10;
struct Edge{
	ll u,v,w;
}E[M],E2[M];
ll tot,tott;
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
ll f[M],c[N];
ll find(ll x){
	return f[x]==x?x:f[x]=find(f[x]);
}
bool merge(ll u,ll v){
	u=find(u),v=find(v);
	if(u==v) return 0;
	f[v]=u;
	return 1;
}
ll n,m,k;
bool used[N];
ll kruskal(){
	ll res=0;
	for(ll i=1;i<=m;i++){
		if(merge(E[i].u,E[i].v)){
			res+=E[i].w;
			E2[++tot].u=E[i].u;
			E2[tot].v=E[i].v;
			E2[tot].w=E[i].w;
		}
	}
	return res;
}
ll kruskal2(){
	ll res=0;
	for(ll i=1;i<=tot;i++){
		if(E2[i].u<=n){
			if(merge(E2[i].u,E2[i].v)){
				res+=E2[i].w;
			}
		}
		else if(used[E2[i].u-n]){
			if(merge(E2[i].u,E2[i].v)){
				res+=E2[i].w;
			}
		}
	}
	return res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>E[i].u>>E[i].v>>E[i].w;
	}
	for(ll i=1;i<=n;i++) f[i]=i;
	sort(E+1,E+m+1,cmp);
	ll ans=kruskal();
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			ll w;cin>>w;
			E2[++tot]=((Edge){n+i,j,w});
		}
	}
	sort(E2+1,E2+tot+1,cmp);
	for(ll i=1;i<(1ll<<k);i++){
		ll S=i,cnt=0;
		for(ll j=k;j>=1;j--){
			if(S>=(1ll<<(j-1))){
				cnt+=c[j];
				S-=(1ll<<(j-1));
				used[j]=1;
			}
			else used[j]=0;
		}
		for(ll j=1;j<=n+k;j++) f[j]=j;
		ll qw=kruskal2();
		ans=min(ans,qw+cnt);
	}
	cout<<ans<<'\n';
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