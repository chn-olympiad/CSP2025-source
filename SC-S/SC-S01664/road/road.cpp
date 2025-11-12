#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,k;
struct node{ll u,v,w;};
vector<node>g[10050];
ll val[10050],vis[10050],c[50050];
struct t{
	ll u,d;
	friend bool operator <(t x,t y){
		return x.d>y.d;
	}
};
ll prim(ll st=1){
	priority_queue<t>q;
	q.push(t{st,val[st]});
	ll ans=0;
	ll cnt=0;
	while(!q.empty()){
		if(cnt==n)break;
		auto p=q.top();q.pop();
		ll u=p.u,d=p.d;
		if(vis[u])continue;
		ans+=d;cnt++;
		vis[u]=1;val[u]=0;
		if(c[u])c[u]=0,n++;
		for(auto e:g[u])q.push(t{e.v,e.w+val[e.v]});
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		ll u,v,w;cin>>u>>v>>w;
		g[u].push_back(node{u,v,w});
		g[v].push_back(node{v,u,w});
	}
	for(ll i=1;i<=k;i++){
		cin>>val[n+i];c[n+i]=1;
		for(ll j=1;j<=n;j++){
			ll w;cin>>w;
			g[j].push_back(node{j,n+i,w});
			g[n+i].push_back(node{n+i,j,w});
		}
	}
	cout<<prim();
	return 0;
}