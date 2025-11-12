#include <bits/stdc++.h>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll N=1e4+100,M=1e6+10;
ll fa[N],ans,n,k,m,cnt=0;
struct node{
	ll u;
	ll v;
	ll w;
	bool operator <(const node& y) const{
		return w<y.w ;
	}
}a[N];
struct node2{
	ll c;
}b[M];

inline ll Get(ll x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=Get(fa[x]);
}

void Merge(ll u,ll v){
	fa[v]=Get(fa[u]);
}

inline void work(){
	for(ll i=1;i<=ll(n+k);i++){
		fa[i]=i;
	}
	for(ll i=1;i<=ll(m+n*k);i++){
		ll u=a[i].u ;
		ll v=a[i].v ;
		if(fa[u]==fa[v]) continue;
		ans+=a[i].w ;
		cnt++;
		Merge(u,v);
		if(cnt==n-1) break;
	}
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>a[i].u >>a[i].v >>a[i].w ;
	}
	ll a2;
	for(ll i=1;i<=k;i++){
		cin>>b[i].c ;
		for(ll j=1;j<=n;j++){
			cin>>a2;
			a[++m].u =j;
			a[m].v =i;
			a[m].w =a2+b[i].c ;
		}
	}
	sort(a+1,a+1+n*k+m);
	work();
	cout<<ans;
	return 0;
}

