#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define f first
#define s second
using namespace std;
const ll N=1e4+10,M=1e6+10,inf=9e18;
struct node{
	ll u,v,w;
	bool friend operator < (node a,node b){
		return a.w<b.w;
	}
}e[M];
ll n,m,k,x,sum,l,fa[N],u[N],v[N],w[N],cnt;
ll find(ll x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(ll x,ll y){
	ll fx=find(x),fy=find(y);
	if(fx!=fy){
		fa[fx]=fy;
	}
}
void kruskal(){
	cnt=m;
	for(ll i=1;i<=n;i++){
		fa[i]=i;
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			e[++l].w=w[i];
			e[l].u=u[i],e[l].v=v[i];
		}
	}
	sort(e+1,e+l+1);
	for(ll i=1;i<=l;i++){
		ll x=e[i].u,y=e[i].v;
		if(find(x)!=find(y)){
			sum+=e[i].w;
			merge(x,y);
			cnt--;
		}
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
		cin>>u[i]>>v[i]>>w[i];
	}
	for(ll i=1;i<=k;i++){
		cin>>x;
		for(ll j=1;j<=n;j++){
			cin>>x;
		}
	}
	kruskal();
	cout<<sum;
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

13  /   
-----------
4 4 0
1 2 114514
2 3 1
3 4 2
1 4 3

6
----------
4 4 1
1 2 12
2 3 112
3 4 114514
1 4 1
3 1 1 1 1

125
----------
1 1 0
1 1 1

0
----------
4 4 1
1 2 12
2 3 112
3 4 88
1 4 1
3 1 9 1 9

101
*/
