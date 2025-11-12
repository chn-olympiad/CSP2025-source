#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int> > g[10010]; 
int n,m,k;
bool vis[10010];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
int find(int start){
	vis[start]=true;
	for(int i=0;i<g[start].size();i++)pq.push({g[start][i].first,g[start][i].second});
	int cnt=n-1;
	int ans=0;
	while(cnt>=1){
		pair<int,int> u=pq.top();
		pq.pop();
		if(vis[u.second]){continue;}
		cnt--;
		vis[u.second]=true;
		ans+=u.first;
		for(int i=0;i<g[u.second].size();i++)pq.push({g[u.second][i].first,g[u.second][i].second});
	}return ans;
}
int a[10010];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++)cin>>u>>v>>w,g[u].push_back({w,v}),g[v].push_back({w,u});
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++)cin>>a[j];
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				g[j].push_back({a[j]+a[k]+c,k});
				g[k].push_back({a[j]+a[k]+c,j});
			}
		}
	}
	cout<<find(1)<<endl;
	return 0;
}


