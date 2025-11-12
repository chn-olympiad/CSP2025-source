#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,c[100],d[100][(ll)1e4+10];
vector<pair<ll,ll>>a[(ll)1e4+10],b[(ll)1e4+10];
ll prim(){
	priority_queue<pair<ll,ll>>q;
	ll dis[(ll)1e4+10];
	bool vis[(ll)1e4+10]={0};
	memset(dis,0x3f,sizeof dis);
	dis[1]=0;
	q.push({0,1});
	ll ans=0;
	while(!q.empty()){
		ll t=q.top().second;
		q.pop();
		if(vis[t])continue;
		vis[t]=1;
		ans+=dis[t];
		for(auto i:a[t]){
			if(dis[i.first]>i.second){
				dis[i.first]=i.second;
				q.push({-i.second,i.first});
			} 
		}
		for(auto i:b[t]){
			if(dis[i.first]>i.second){
				dis[i.first]=i.second;
				q.push({-i.second,i.first});
			} 
		}
	}
	return ans;
} 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k; 
	for(ll i=0;i<m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			cin>>d[i][j];
		}
	}
	ll minans=1e18;
	for(ll i=0;i<(1<<k);i++){
		for(ll j=1;j<=n;j++){
			b[j].clear();
		}
		ll ans=0;
		for(ll j=1;j<=k;j++){
			if((i>>j-1)&1){
				ans+=c[j];
				for(ll o=1;o<=n;o++){
					b[j+n].push_back({o,d[j][o]});
					b[o].push_back({j+n,d[j][o]});
				}
			}
		}
		ans+=prim();
		minans=min(ans,minans);
	}
	cout<<minans;
	return 0;
}

