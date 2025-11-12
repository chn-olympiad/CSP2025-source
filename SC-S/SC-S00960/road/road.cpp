#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+15;
int n,m,k,u,v,w,c[15],ans;
vector<vector<pair<int,int>>>g(N);
struct node {
	int x,y;
	bool operator<(const node other)const{
		return y>other.y;
	}
};
int prim(vector<vector<pair<int,int>>>g){
	int dis[N],res=0;
	bool vis[N];
	memset(dis,0x3f,sizeof dis);
	priority_queue<node>q;
	q.push({1,0});
	dis[1]=0;
	while(!q.empty()){
		int u=q.top().x;
		q.pop();
		if(vis[u]==true)continue;
		vis[u]=true;
		res+=dis[u];
		for(pair<int,int>pr:g[u]){
			int v=pr.first,w=pr.second;
			if(!vis[v]&&w<dis[v]){
				dis[v]=w;
				q.push({v,w});
			}
		}
	}
	return res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		g[u].push_back(make_pair(v,w));
		g[v].push_back(make_pair(u,w));
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		ans+=c[i];
		for(int j=1;j<=n;j++){
			cin>>w;
			g[n+i].push_back(make_pair(j,w));
			g[j].push_back(make_pair(n+i,w));
		}
	}
	ans+=prim(g);
	cout<<ans<<endl;
	return 0;
}