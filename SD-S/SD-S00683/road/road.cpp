#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,ans=0;
struct node{
	ll u,v,w;
	friend bool operator<(node p,node q){
		return p.w<q.w;
	}
}e[1500006];
ll fa[1500006],p[12],ex[12][10004];
ll find(ll x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void solve_for_sub1(){
	for(ll i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+1+m);
	ll ltk=n;
	for(ll i=1;i<=m;i++){
		ll u=find(e[i].u),v=find(e[i].v);
		if(u!=v)fa[u]=v,ans+=e[i].w,ltk--;
		if(ltk==1)break;
	}
}
void solve_for_sub2(){
	for(ll i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(ll i=1;i<=k;i++){
		cin>>p[i];
		ll x=0;
		for(ll j=1;j<=n;j++){
			cin>>ex[i][j];
			if(ex[i][j]==0)x=j;
		}
		for(ll j=1;j<=n;j++){
			if(j!=x){
				m++;
				e[m].u=x,e[m].v=j,e[m].w=ex[i][j];
			}
		}
	}
	sort(e+1,e+1+m);
	ll ltk=n;
	for(ll i=1;i<=m;i++){
		ll u=find(e[i].u),v=find(e[i].v);
		if(u!=v)fa[u]=v,ans+=e[i].w,ltk--;
		if(ltk==1)break;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0),cout.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++)
		fa[i]=i;
	if(k==0)solve_for_sub1();
	else solve_for_sub2();
	cout<<ans;
}

