#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,ans=0,res=1e9,dis[10015];
bool vis[10015];
struct node{
	int to,w;
	bool operator<(const node& x)const{
		return x.w<w;
	}
};
vector<node>e[10005];
vector<int>a[15];
void prim(int s){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f3f3f,sizeof(dis));
	priority_queue<node>q;
	dis[s]=0;
	q.push({s,0});
	while(!q.empty()){
		node u=q.top();
		q.pop();
		if(vis[u.to])continue;
		vis[u.to]=true;
		ans+=u.w;
		for(int i=0;i<(int)e[u.to].size();i++){
			int v=e[u.to][i].to,w=e[u.to][i].w;
			if(dis[v]>w){
				dis[v]=w;
				q.push({v,dis[v]});
			}
		}
	}
}
void dfs(int id,int x,int y){
	if(x>=y){
		n+=y;
		prim(1);
		res=min(ans,res);
		n-=y;
		return;
	}
	for(int i=id;i<=k-(y-x);i++){
		ans+=a[i][0];
		for(int j=1;j<=n;j++){
			e[n+x+1].push_back({j,a[i][j]});
			e[j].push_back({n+x+1,a[i][j]});
		}
		dfs(i+1,x+1,y);
		ans-=a[i][0];
		for(int j=1;j<=n;j++){
			e[n+x+1].pop_back();
			e[j].pop_back();
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	prim(1);
	res=ans;
	for(int i=1;i<=k;i++){
		int v,u;
		cin>>v;
		a[i].push_back(v);
		for(int j=1;j<=n;j++){
			cin>>u;
			a[i].push_back(u);
		}
	}
	for(int i=1;i<=k;i++){
		ans=0;
		dfs(1,0,i);
	}
	cout<<res;
	return 0;
}