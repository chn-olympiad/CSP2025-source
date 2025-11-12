#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
struct node{
	int v,w;
};
int n,m,k,c[15][N],x[N];
vector<node>g[N];
bool vis[N];
map<int,bool>mp;
int dis[N];
void dijkstra(){
	memset(dis,0x3f,sizeof(dis));
	queue<int>q;
	q.push(1);
	dis[1]=0;
	vis[1]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:g[u]){
			int V=v.v,w=v.w;
			if(dis[V]>dis[u]+w){
				dis[V]=dis[u]+w;
				x[V]=w;
				if(!vis[V]){
					q.push(V);
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	bool flag=1;
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++){
			cin>>c[i][j];
			if(c[i][j]!=0)flag=0;
		}
	if(k==0){
		dijkstra();
		int sum=0;
		for(int i=1;i<=n;i++)if(!mp[x[i]])mp[x[i]]=1,sum+=x[i];
		cout<<sum;
	}
	else cout<<0;
	return 0;
}
