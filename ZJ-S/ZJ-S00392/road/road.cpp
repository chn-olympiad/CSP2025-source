#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u,v,w;
vector<pair<int,int>> g[10001];
int c[11];
int t[11][10001];
int dist[10001];
void djs(int s){
	priority_queue<int,vector<int>,greater<int>> q;
	q.push(s);
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0;
	while(!q.empty()){
		int u=q.top();
		q.pop();
		for(auto x:g[u]){
			int v=x.first;
			int w=x.second;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				q.push(v);
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>t[i][j];
		}
	}
	long long minn=1e18;
	for(int i=1;i<=n;i++){
		djs(i);
		long long ans=0;
		for(int j=1;j<=n;j++){
			ans+=dist[j];
		}
		minn=min(minn,ans);
	}
	cout<<minn;
	return 0;
}