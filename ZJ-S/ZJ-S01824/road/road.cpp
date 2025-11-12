#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k,fa[114514],sz[114514],cnt;
struct Edge{
	ll u,v,w;
	bool operator<(const Edge &x)const{
		return w<x.w;
	}
}edges[2000000];
struct node{
	ll v,w;
};
vector<node>G[11451];
ll K[12][10005];
ll c[14];
ll find(ll x){
	if(fa[x]==x)return x;
	else{
		return fa[x]=find(fa[x]);
	}
}
void main1(){
	sort(edges+1,edges+1+cnt);
	ll tot=0,ans=0;
	for(ll i=1;i<=cnt;i++){
		ll u=edges[i].u,v=edges[i].v,w=edges[i].w;
		ll fv=find(v),fu=find(u);
		if(fu==fv)continue;
		ans+=w;
		if(sz[fv]>=sz[fu])swap(fu,fv);
		fa[fv]=fu;
		sz[fu]+=sz[fv];
		tot++;
		if(tot==n-1)break;
	}
//	cout<<1<<'\n';
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=n+k+1;i++)fa[i]=i,sz[i]=1;
//	cout<<1;
	for(ll i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
//		G[u].push_back({v,w});
//		G[v].push_back({u,w});
		edges[++cnt]={u,v,w};
	}
	ll f1=1;
//	cout<<1;
	for(ll i=1;i<=k;i++){
		
		cin>>c[i];
		if(c[i])f1=0;
		ll f2=0;
		for(ll j=1;j<=n;j++){
			ll  w;
			cin>>K[i][j];
			if(K[i][j]==0)f2=1;
			
		}
		if(!f2)f1=0;
	}
//	cout<<1;
	if(!k)main1();
	else if(f1){
		for(ll i=1;i<=k;i++){
			for(ll j=1;j<=n;j++){
//				G[n+i].push_back({j,K[i][j]});
//				G[j].push_back({n+i,K[i][j]});
				edges[++cnt]={j,n+i,K[i][j]};
			}
			
		}
		n+=k;
		main1();
	}
	return 0;
}