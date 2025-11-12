#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,c[15],a[15][10005],fa[10005];
bool flag;
struct node{
	ll u,v,w;
};
vector<node>g;
bool cmp(node x,node y){
	return x.w<y.w;
}
ll find(ll x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void push(ll l,ll r){
	ll lll=find(l),rr=find(r);
	if(lll!=rr)fa[lll]=rr;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		g.push_back({u,v,w});
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)flag=1;
		for(ll j=1;j<=n;j++)cin>>a[i][j];
	}
	if(!flag){
		ll ans=0;
		for(ll i=1;i<=n;i++)fa[i]=i;
		for(ll i=1;i<=k;i++){
			for(ll j=1;j<=n;j++){
				g.push_back({i,j,a[i][j]});
			}
		}
		stable_sort(g.begin(),g.end(),cmp);
		for(auto it:g){
			ll u=it.u,v=it.v,w=it.w;
			ll uu=find(u),vv=find(v);
			if(uu!=vv){
				ans+=w;
				push(uu,vv);
			}
		}
		cout<<ans;
	}
	else{
		ll ans=0;
		for(ll i=1;i<=n;i++)fa[i]=i;
		stable_sort(g.begin(),g.end(),cmp);
		for(auto it:g){
			ll u=it.u,v=it.v,w=it.w;
			ll uu=find(u),vv=find(v);
			if(uu!=vv){
				ans+=w;
				push(uu,vv);
			}
		}
		cout<<ans;
	}
	return 0;
}
