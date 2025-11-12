#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e5+10;
vector<pair<int,int>>g[N],p[N],l[N];
int vis[N],res,c[N],a[15][N];
void mst(int s,vector<pair<int,int>> p[]){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	q.push({0,s});vis[s]=1;
	while(!q.empty()){
		int u=q.top().second,f=q.top().first;q.pop();
		for(auto x:g[u]){
			int v=x.first,ff=x.second;
			if(vis[v])continue;vis[v]=1;
			p[u].push_back({v,ff}); p[v].push_back({u,ff});
			res+=ff;cout<<res<<endl;
			q.push({f+ff,v});
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		g[u].push_back({v,w});g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
	cin>>c[i];for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	mst(1,p);
	cout<<res<<endl;
	return 0;
}
