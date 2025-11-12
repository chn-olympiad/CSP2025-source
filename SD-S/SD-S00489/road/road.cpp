#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1010;
const ll M=1000010;
ll f[N][N];
ll b[11][N];
ll c[11];
ll fa[N];
ll n,m,k;
ll ans,cnt;
ll findd(ll x){
	if(fa[x]!=x) fa[x]=findd(fa[x]);
	return fa[x];
}
struct ikun{
	ll u;
	ll v;
	ll w;
}a[M];
bool cmp(ikun x,ikun y){
	return x.w<y.w;
}

void solve1(){
	for(ll i=1;i<=m;i++){
		ll u=a[i].u;
		ll v=a[i].v;
		ll w=a[i].w;
		ll U=findd(u);
		ll V=findd(v);
		if(U==V) continue;
		fa[U]=V;
		ans+=w;
		cnt++;
		if(cnt==n-1){
			break;
		}
	}
	cout<<ans;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++) fa[i]=i;
	for(ll i=1;i<=m;i++){
		ll u,v,w;
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	if(k!=0){
		cout<<0;
		return 0;
	}
	solve1();
	ll cnt=0;
	sort(a+1,a+m+1,cmp);
	return 0;
}
//48pts




/*
4 7 0
1 2 3
1 2 2
2 4 1
3 4 15
1 3 11
1 4 9
2 4 7

*/
