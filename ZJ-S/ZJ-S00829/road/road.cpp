#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
struct node{
	ll u,v,s;
}a[N];
bool cmp(node a,node b){
	return a.s<b.s;
};
ll fa[N];
inline ll find(ll x){
	if (x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
ll c[N];

ll ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,m,k;
	cin>>n>>m>>k;
	for (ll i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].s;
	}
	if (k==0){
		sort(a+1,a+n+1,cmp);
		for (ll i=1;i<=n;i++) fa[i]=i;
		ll q=0;
		for (ll i=1;i<=m;i++){
			if (q==n-1) break;
			ll u=a[i].u,v=a[i].v,cost=a[i].s;
			ll fu=find(u),fv=find(v);
			if (fu==fv) continue;
			q++;
			ans+=cost;
			fa[fu]=fv;
		}
		cout<<ans<<'\n';
		return 0;
	}
	else cout<<0<<'\n';
	return 0;
}