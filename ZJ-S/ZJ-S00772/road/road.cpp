#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+20;
vector<pair<int,int>> g[N];
int n,m,k,va[N],vis[N],ans=INT_MAX;
void bfs(int s){
	memset(vis,0x3f,sizeof vis);
	queue<int> q;
	vis[s]=0;
	q.push(s);
	while(q.size()){
		int u=q.front();q.pop();
		for(auto t:g[u]){
			int v=t.first,w=t.second;
			if(vis[v]>vis[u]+w){
				vis[v]=vis[u]+w;
				q.push(v);
			}
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int a,b,c;cin>>a>>b>>c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	for(int i=1;i<=k;++i){
		cin>>va[m+i];
		for(int j=1;j<=n;++j){
			int x;cin>>x;
			g[m+i].push_back({j,x+va[m+i]});
			g[j].push_back({m+i,x+va[m+i]});
		}
	}
	for(int j=1;j<=n;++j){
		bfs(j);
		int cnt=0;
		for(int i=1;i<=n;++i) cnt+=vis[i];
		ans=min(ans,cnt);
	}
	cout<<ans;
	return 0;
}
