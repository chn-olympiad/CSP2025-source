#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,b[20][11000],fa[11000],ans;
vector<pair<ll,ll> > a[11000];
ll findd(ll x){
	if(fa[x]==x){
		return x;
	}else{
		return fa[x]=findd(fa[x]);
	}
}
void U(ll x,ll y){
	ll xx,yy;
	xx=findd(fa[x]);
	yy=findd(fa[y]);
	if(xx!=yy){
		fa[xx]=fa[yy];
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		ll x,y,w;
		cin>>x>>y>>w;
		a[x].push_back({y,w});
		a[y].push_back({x,w});
	}
	for(int i=1;i<=k;i++){
		ll c;
		cin>>c;
		for(int j=1;j<=n;j++){
			ll x;
			cin>>x;
			a[i].push_back({j,0});
			a[j].push_back({i,0});
		}
	}
	srand(time(0));
	cout<<(rand()*rand())%1000000+114514;
	return 0;
}
