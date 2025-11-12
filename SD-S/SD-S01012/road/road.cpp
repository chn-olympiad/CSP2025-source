#include<bits/stdc++.h>
#define int long long
#define fi first 
#define se second 
using namespace std;
const int N=1e4+5;
int n,m,k,ans,vis[N];
vector<pair<int,int> > g[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >h;
int dis[N];
void dij(){
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	h.push(make_pair(0,1));
	while(!h.empty()){
		int u=h.top().se;
		h.pop();
		if(vis[u])break;
		vis[u]=1;
		for(auto e:g[u]){
			if(dis[e.fi]>dis[u]+e.se){
				dis[e.fi]=dis[u]+e.se; 
				h.push(make_pair(dis[e.fi],e.fi));
			}
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
cin>>n>>m>>k;
for(int i=1;i<=m;i++){
	int u,v,w;
	cin>>u>>v>>w;
	g[u].push_back(make_pair(v,w));
	g[v].push_back(make_pair(u,w));
}
int aans=0x3f3f3f3f;
for(int i=1;i<=k;i++){
	int aa=0;
	for(int j=1;j<=n;j++){
		int w;
		cin>>w;
		aa+=w;
//		g[n+i].push_back(make_pair(j,w));
//		g[j].push_back(make_pair(n+i,w));
	}
	aans=min(aans,aa);
}
dij();
for(int i=1;i<=n;i++){
	ans+=dis[i];
//	cout<<dis[i]<<' ';
}
cout<<min(ans,aans);
return 0;
}

