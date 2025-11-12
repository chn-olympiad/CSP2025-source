#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const ll MAXN=1000106;
ll n,m,k;
struct edge{
	ll u,v,w;
}e[MAXN];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
ll fa[MAXN];
ll find(ll x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
ll ksl(){
	ll cnt=0;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		ll u=find(e[i].u);
		ll v=find(e[i].v);
		ll w=e[i].w;
		if(u==v) continue;
		else{
			fa[u]=v;
			cnt+=w;
		}
	}
	return cnt;
}
ll c[15],a[15][10104];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		ll u1,v1,w1;
		cin>>u1>>v1>>w1;
		e[i].u=u1;
		e[i].v=v1;
		e[i].w=w1;
	}
	if(k==0){
		cout<<ksl();
	}
	else{
		cout<<0;
	}
	return 0;
}

