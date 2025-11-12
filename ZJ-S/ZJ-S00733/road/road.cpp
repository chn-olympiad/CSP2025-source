#include<bits/stdc++.h>
using namespace std;
const int N=1e4+17;
const long long MAX=1e18;
long long dis[N];
bool vis[N];
vector<pair<int,long long> > G[N];
int n,m,k;
void prim(int s){
	priority_queue<pair<long long,int> > q;
	q.push({0,s});
	for(int i=1;i<=n;i++){
		dis[i]=MAX;
	}
	dis[s]=0;
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(vis[x])continue;
		vis[x]=true;
		for(auto i:G[x]){
			if(dis[i.first]>i.second&&!vis[i.first]){
				dis[i.first]=i.second;
				q.push({-dis[i.first],i.first});
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=dis[i];
	}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	
	for(int i=1;i<=k;i++){
		int val;
		cin>>val;
		for(int j=1;j<=n;j++){
			long long x;
			cin>>x;
			G[n+i].push_back({j,x});
			G[j].push_back({n+i,x});
		}
	}
	n+=k;
	prim(1);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 0 2 4
0 1 3 2 0

*/