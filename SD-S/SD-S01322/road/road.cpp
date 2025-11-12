#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,w;
	friend bool operator < (node a,node b){
		return a.w>b.w;
	}
};
vector <node> a[10020];
int n,m,k,c[20],s[20][10020];
long long vis[10020],dis[10020];
int prim(){
	priority_queue <node> q;
	q.push({1,0});
	fill(dis+1,dis+1+n+k,1e18);
	dis[1]=0;
	long long ans=0;
	while(!q.empty()){
		int u=q.top().v;
		int di=q.top().w;
		q.pop();
		if(vis[u]) continue;
		ans+=di;
		vis[u]=1;
		for(auto it:a[u]){
			int v=it.v,w=it.w;
			if(!vis[v]&&dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({v,w});
			}
		}
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>s[i][j];
			if(c[i]==0){
				a[i].push_back({j,s[i][j]});
				a[j].push_back({i,s[i][j]});
			}
		}
	}
	cout<<prim();
	return 0;
}
