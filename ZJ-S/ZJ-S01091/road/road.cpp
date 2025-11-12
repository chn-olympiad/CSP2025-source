#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5;
int n,m,k,f[N],ans;
ll c[15],a[15][N];
vector<pair<ll,int> > g[N];
bool vis[N],is_c;
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
void prim(){
	int cnt=1;
	for(int i=1;i<=n;i++) f[i]=i;
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > pq;
	vis[1]=1;
	for(auto i:g[1]) pq.push({i.first,i.second});
	while(cnt<n){
		while(!pq.empty()&&find(1)==find(pq.top().second)) pq.pop();
		if(!pq.empty()) vis[pq.top().second]=1,f[pq.top().second]=1,cnt++,ans+=pq.top().first; 
		if(!pq.empty()){
			int x=pq.top().second;
			pq.pop();
			for(auto i:g[x]){
				if(vis[i.second]) continue;
				pq.push({i.first,i.second});
			}
		}
	}
	cout<<ans;
}
void solve(){
	int cnt=1;
	for(int i=1;i<=n;i++) f[i]=i;
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > pq;
	vis[1]=1;
	for(auto i:g[1]){
		pq.push({i.first,i.second});
		for(int j=1;j<=k;j++) pq.push({a[j][1]+a[j][i.second],i.second});
	}
	while(cnt<n){
		while(!pq.empty()&&find(1)==find(pq.top().second)) pq.pop();
		if(!pq.empty()) vis[pq.top().second]=1,f[pq.top().second]=1,cnt++,ans+=pq.top().first; 
		if(!pq.empty()){
			int x=pq.top().second;
			pq.pop();
			for(auto i:g[x]){
				if(vis[i.second]) continue;
				pq.push({i.first,i.second});
				for(int j=1;j<=k;j++) pq.push({a[j][x]+a[j][i.second],i.second});
			}
		}
	}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int u,v,i=1;i<=m;i++){
		ll w;
		cin>>u>>v>>w;
		g[u].push_back({w,v}),g[v].push_back({w,u});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) is_c=1;
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	if(k==0) prim();
	else if(!is_c) solve();
	return 0;
}
