#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5;
ll n,ans,m,k,ww,c[N],a[15][N];
bool vis[N];
struct S{
	ll v,w;
}b[N];
bool cmp(S x,S y){
	if(x.w==y.w) return x.v<y.v;
	else return x.w<y.w;
}
vector<S> G[N];
void dfs(ll u,ll fa){
	S v;
	if(vis[u]){
		ll mx=0,tw=ww,ds=0;
		while(tw!=0&&b[tw].v!=u){
			if(b[tw].w>mx){
				mx=b[tw].w;
				ds=tw;
				tw--;
			}
		}
		b[ds].w=0;
		ans-=mx;
//		cout<<mx<<" ";
		return ;
	}
	vis[u]=1;
	for(ll i=0;i<G[u].size();i++){
		v=G[u][i];
		if(v.v!=fa){
			b[++ww]={u,v.w};
			dfs(v.v,u);
			ww--;
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	ll u,v,w;
	for(ll i=1;i<=m;i++){
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
		ans+=w;
	}
	for(ll i=1;i<=n;i++){
		sort(G[i].begin(),G[i].end(),cmp);
	}
		
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++) cin>>a[i][j];
		if(c[i]==0){
			cout<<0;
			return 0;
		}
	}
//	dfs(1,0);
	cout<<ans;
//
//	
//	for(ll i=0;i<(1<<k);i++){
//		
//	}
	return 0;
}
