#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e4+5;
const ll M=1e6+5;
ll n,m,k;
struct ed{
	ll x,y,z;
};
ed a[M];
bool cmp(ed xx,ed yy){
	return xx.z<yy.z;
}
ll fa[N];
ll get(ll x){
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}
void solve1(){
	ll ans=0;
	sort(a+1,a+m+1,cmp);
	for(ll i=1;i<=m;i++){
		ll zx=get(a[i].x);
		ll zy=get(a[i].y);
		if(zx!=zy){
			fa[zx]=zy;
			ans+=a[i].z;
		}
	}	
	cout<<ans;
}
void solve2(){
	ll ans=0;
	ll tot=m;
	for(ll j=1;j<=k;j++){
		ll c;
		cin>>c;
		for(ll i=1;i<=n;i++){
			ll cc;
			cin>>cc;
			++tot;
			a[tot].x=j;a[tot].y=i;a[tot].z=cc;
		}
	}
	sort(a+1,a+tot+1,cmp);
	for(ll i=1;i<=tot;i++){
		ll zx=get(a[i].x);
		ll zy=get(a[i].y);
		if(zx!=zy){
			fa[zx]=zy;
			ans+=a[i].z;
		}
	}
	cout<<ans;
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++)
		fa[i]=i;
	for(ll i=1;i<=m;i++)
		cin>>a[i].x>>a[i].y>>a[i].z;
	if(k==0) solve1();
	else solve2();
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
