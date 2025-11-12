#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[15][10010];
long long ans=1145141919810;
vector<pair<int,int> > e[10030];
bool b[15];
void prim(){
	long long dis[10030],cnt,t;
	bool vis[10030];
	for(int i=1;i<=10025;i++){
		dis[i]=1145141919810,vis[i]=0;
	}
	cnt=0,t=n;
	vector<pair<int,int> > ee[10030];
	priority_queue<pair<int,int> > q;
	for(int i=1;i<=n;i++){
		for(int j=0;j<e[i].size();j++){
			ee[i].push_back({e[i][j].first,e[i][j].second});
		}
	}
	for(int i=1;i<=k;i++){
		if(b[i]){
			cnt+=c[i][0];
			t++;
			for(int j=1;j<=n;j++){
				ee[j].push_back({t,c[i][j]});
				ee[t].push_back({j,c[i][j]});
			}
		}
	}
	dis[1]=0;
	q.push({0,1});
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(vis[u]){
			continue ;
		}
		cnt+=dis[u];
		dis[u]=0,vis[u]=1;
		for(int i=0;i<ee[u].size();i++){
			int to=ee[u][i].first,w=ee[u][i].second;
			if(dis[to]>w){
				dis[to]=w;
				q.push({-w,to});
			}
		}
	}
	ans=min(ans,cnt);
}
void dfs(int x){
	if(x>k){
		prim();
		return ;
	}
	b[x]=true;
	dfs(x+1);
	b[x]=false;
	dfs(x+1);
	return ;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>c[i][j];
		}
	}
	dfs(1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
