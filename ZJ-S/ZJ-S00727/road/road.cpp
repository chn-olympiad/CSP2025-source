#include<bits/stdc++.h>
#define speed_up ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define N 200005
#define M 15
using namespace std;
typedef long long ll;
ll n,m,k,f[N];
struct graph{
	ll u;ll v;ll w;
}line[N];
struct ext{
	ll w;ll p[N];
}county[M];
ll find_root(ll x){
	if(x==f[x]) return x;
	return f[x]=find_root(f[x]);
}
bool cmp1(graph a,graph b){
	return a.w<b.w;
}
bool cmp2(ext a,ext b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	speed_up;
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>line[i].u>>line[i].v>>line[i].w;
	}
	for(ll i=1;i<=k;i++){
		cin>>county[i].w;
		for(ll j=1;j<=n;j++){
			cin>>county[i].p[j];
		}
	}
	sort(line+1,line+1+m,cmp1);
	for(ll i=1;i<=n;i++) f[i]=i;
	ll ans=0,cnt=0;
	for(ll i=1;i<=m;i++){
		ll uf=find_root(line[i].u),vf=find_root(line[i].v);
		if(uf!=vf){
			ll tag=0;
			for(ll j=1;j<=k;j++){
				ll tot=county[j].p[line[i].u]+county[j].p[line[i].v];
				if(tot+county[j].w<=line[i].w){
					line[i].w=tot+county[j].w;
					tag=j;
				}
			}
			county[tag].w=0;
			f[uf]=vf;
			ans+=line[i].w;
			cnt++;
		}
		if(cnt==n-1) break;
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

13
*/
