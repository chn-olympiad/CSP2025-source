#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,ans=1e18,vis[1015],visk[15],c[15],taa;
vector<pair<ll,ll>>g[1015];
void prim1(int s){
	ll mst=0;
	priority_queue<pair<int,int>>q;
	q.push(make_pair(0,s));
	memset(vis,0,sizeof(vis));
	while(q.size()){
		int x=q.top().second;
		int d=q.top().first;
		q.pop();
		if(vis[x])
			continue;
		//cout<<x<<' ';
		vis[x]=1;
		mst+=-d;
		for(int i=0;i<g[x].size();i++){
			int y=g[x][i].first;
			int z=g[x][i].second;
			if(!vis[y])
				q.push(make_pair(-z,y));
		}
	}
	ans=min(ans,mst);
	//cout<<mst<<'\n';
}
void prim2(int s){
	ll mst=0;
	priority_queue<pair<int,int>>q;
	q.push(make_pair(0,s));
	memset(vis,0,sizeof(vis));
	while(q.size()){
		int x=q.top().second;
		int d=q.top().first;
		q.pop();
		if(vis[x])
			continue;
		if(x>n&&!visk[x-n])
			continue;
		//cout<<x<<' ';
		vis[x]=1;
		mst+=-d;
		for(int i=0;i<g[x].size();i++){
			int y=g[x][i].first;
			int z=g[x][i].second;
			if(!vis[y]&&y<=n)
				q.push(make_pair(-z,y));
			if(y>n&&!vis[y]&&visk[y-n])
				q.push(make_pair(-z,y));
		}
	}
	//cout<<'\n';
	//for(int i=1;i<=k;i++)
		//cout<<visk[i]<<' ';
	for(int i=1;i<=k;i++)
		if(visk[i])
			mst+=c[i];
	ans=min(ans,mst);
	//cout<<mst<<'\n';
}
void dfs(int x,int is){
	if(x==k+1){
		prim2(1);
		return ;
	}
	if(is){
		visk[x]=1;
		dfs(x+1,1);
		dfs(x+1,0);
	}else{
		visk[x]=0;
		dfs(x+1,1);
		dfs(x+1,0);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		g[u].push_back(make_pair(v,w));
		g[v].push_back(make_pair(u,w));
	}
	prim1(1);
	if(k==0){
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]==0)
			taa++;
		g[0].push_back(make_pair(n+i,0));
		//g[n+i].push_back(make_pair(0,0));
		for(int j=1;j<=n;j++){
			cin>>w;
			g[n+i].push_back(make_pair(j,w));
			g[j].push_back(make_pair(n+i,w));
		}
	}
	if(taa==k){
		prim1(1);
		cout<<ans;
		return 0;
	}
	dfs(1,1);
	dfs(1,0);
	cout<<ans;
	return 0;
}