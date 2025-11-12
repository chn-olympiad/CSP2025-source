#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+5;
ll to[N],h[N];
ll go(ll x){
	if(x==to[x])return x;
	else return to[x]=go(to[x]);
}bool merge(ll a,ll b){
	ll ga=go(a),gb=go(b);
	if(ga==gb)return 0;
	if(h[ga]<h[gb])swap(ga,gb);
	to[gb]=ga;
	return 1;
}
struct edge{
	ll w,u,v;
	edge(ll ww=0,ll uu=0,ll vv=0){
		w=ww,u=uu,v=vv;
	}ll operator<(edge e2){
		return w<e2.w;
	}
};
vector<edge> g;
ll c[15],n,m,k;
bool ag[15];
ll cnt,sum,minx=1e18;
void dfs(ll x){
	if(x==n)return;
	dfs(x-1);
	
	ag[x-n]=1;cnt++;sum+=c[x-n];
	
	for(int i=1;i<=n;i++)to[i]=i,h[i]=1;
	for(int i=1;i<=k;i++)to[n+k]=n+k,h[n+k]=1;
	
	ll used=0,sumt=0;
	for(int i=0;i<g.size();i++){
		if(g[i].u>n&&!ag[g[i].u-n])continue;
		if(merge(g[i].u,g[i].v)){
			sumt+=g[i].w;
			used++;
		}if(used==n-1+cnt){
			minx=min(sumt+sum,minx);
			break;
		}	
	}
	
	dfs(x-1);
	ag[x-n]=0;cnt--;sum-=c[x-n];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		ll u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		g.push_back(edge(w,u,v));
	}for(int i=1;i<=k;i++){
		scanf("%lld",c+i); 
		for(int j=1;j<=n;j++){
			ll w;
			scanf("%lld",&w);
			g.push_back(edge(w,i+n,j));
		}
	}sort(g.begin(),g.end());
	dfs(n+k);
	cout<<minx;
	return 0;
}


