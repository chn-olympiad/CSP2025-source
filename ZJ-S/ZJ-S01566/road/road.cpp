#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N=1e4;
int n,m,k;
vector<PII>g[N*15];
int c[N*15];
int a[15][N];
int dis[N*15];
bool vis[N*15];
void spfa(int st){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	queue<int>q;
	dis[st]=0;
	vis[st]=1;
	q.push(st);
	while(!q.empty()){
		auto u=q.front();q.pop();
		vis[u]=0;
		for(auto t:g[u]){
			int v=t.first;
			int w=t.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
//				cout<<u<<" "<<v<<" "<<w<<"\n";
				if(!vis[v]){
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
	int ans=-1e18;
	for(int i=1;i<=n;i++){
		ans=max(ans,dis[i]);
//		cout<<dis[i]<<" ";
	}
	cout<<ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	g[0].push_back({1,0});
	for(int i=1;i<=k;i++){
		cin>>c[i];
		g[0].push_back({i+n,c[i]});
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			g[i+n].push_back({j,a[i][j]});
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=i+1;j<=k;j++){
			g[i+n].push_back({j+n,c[j]});
			g[j+n].push_back({i+n,c[i]});
		}
	}
	spfa(0);
	return 0;
}