#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k;
ll u,v,w,cnt=0,p[100005];
ll c[15],a[15][10005];
vector<pair<ll,ll>> G[10005];
ll f[100005];
bool check(){
	for(ll i=1;i<=n;i++){
		if(f[i]!=1)return true;
	}
	return false;
}
void solve(ll x){
	ll ans=0;
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
	q.push({0,x});
	while(!q.empty()&&check()){
		auto [w,u]=q.top();
		q.pop();
		if(f[u]==0){
			ans+=w;
			f[u]=1;
			for(auto [v,d]:G[u]){//v点 d距离
				if(f[v]==0){
					q.push({d+p[v],v});
				}
			}
		}
	}
	cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	cnt=n;
	for(ll i=1;i<=m;i++){
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	for(ll i=1;i<=k;i++){
		cnt++;
		cin>>c[i];
		p[cnt]=c[i];
		for(ll j=1;j<=n;j++){
			cin>>a[i][j];
			G[j].push_back({cnt,a[i][j]});
			G[cnt].push_back({j,a[i][j]});
		}
	}
	solve(1);
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
*/