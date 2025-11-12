#include <bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int N=20010,M=1000010;
constexpr ll inf=1e16;
int n,m,K,p2K,ne2,ne3,fa[N],b[10];
struct Edge{
	int u,v,w;
	friend int operator<(const Edge &a,const Edge &b){
		return a.w<b.w;
	}
}e[M],e2[11*N],e3[11*N];
int find(int u){
	while(u!=fa[u]){
		u=fa[u]=fa[fa[u]];
	}
	return u;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>K;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		auto [u,v,w]=e[i];
		u=find(u);
		v=find(v);
		if(u==v){
			continue;
		}
		fa[u]=v;
		e2[++ne2]=e[i];
	}
	for(int i=0;i<K;i++){
		cin>>b[i];
		for(int j=1,w;j<=n;j++){
			cin>>w;
			e2[++ne2]={i+n+1,j,w};
		}
	}
	sort(e2+1,e2+ne2+1);
	p2K=1ll<<K;
	ll ans=inf;
	for(int i=0;i<p2K;i++){
		ll s=0;
		for(int j=0;j<K;j++){
			if(i>>j&1){
				s+=b[j];
			}
		}
		for(int j=1;j<=n+K;j++){
			fa[j]=j;
		}
		for(int j=1;j<=ne2;j++){
			auto [u,v,w]=e2[j];
			if((u<=n||i>>(u-n-1)&1)&&(v<=n||i>>(v-n-1)&1)){
				u=find(u);
				v=find(v);
				if(u==v){
					continue;
				}
				fa[u]=v;
				s+=w;
				if(s>=ans){
					break;
				}
			}
		}
		ans=min(ans,s);
	}
	cout<<ans<<"\n";
	return 0;
}