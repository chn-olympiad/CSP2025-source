#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+50,inf=0x3f3f3f3f;
ll n,m,k,u,v,w,dis[N],ans,anss=inf,cst[15][N];
bool vis[N],vv[N];
struct node{
	ll v,w;
	bool operator<(const node &b)const{
		return w>b.w;
	}
};
vector<node> g[N];
void prim(){
	ll cnt=0;
	priority_queue<node> q;
	q.push({1,0});
	while(!q.empty()){
		node u=q.top();
		q.pop();
		if(vis[u.v]) continue;
		vis[u.v]=true;
		ans+=u.w;
		cnt++;
		for(int i=0;i<g[u.v].size();i++){
			node v=g[u.v][i];
			if(vis[v.v]) continue;
			q.push({v.v,v.w});
		}
	}
}
void dfs(int x){
	if(x==n+k+1){
		ans=0;
		for(int i=1;i<=k;i++){
			if(!vis[n+i]) ans+=cst[i][0];
			vv[n+i]=vis[n+i];
		}
		prim();
		anss=min(anss,ans);
		memset(vis,0,sizeof vis);
		for(int i=1;i<=k;i++) vis[n+i]=vv[n+i];
		return ;
	}
	vis[x]=0;
	dfs(x+1);
	vis[x]=1;
	dfs(x+1);
}
int main(){
	freopen("road3.in","r",stdin);
	//freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>cst[i][0];
		for(int j=1;j<=n;j++){
			cin>>cst[i][j];
			g[n+i].push_back({j,cst[i][j]});
			g[j].push_back({n+i,cst[i][j]});
		}
	}
	if(k) dfs(n+1);
	else{
		prim();
		anss=ans;
	}
	cout<<anss;
	return 0;
}
/*
5 6 1
1 2 4
4 5 3
1 4 2
2 4 3
2 5 5
3 5 7
*/

