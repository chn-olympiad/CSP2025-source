#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector <pair<int,int> > e[10100];
int tmp[10100];
int vis[10100];
int dis[10100];
int ans;
priority_queue <pair<int,int> > q;
void prim(int start){
	q.push(make_pair(0,start)),vis[start]=true,dis[start]=0;
	int cnt=0;
	while(cnt<n){
		int u=q.top().second;
		q.pop();
		cnt++,vis[u]=true,ans+=dis[u];
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i].first,w=e[u][i].second;
			if(!vis[v]&&(dis[v]==-1||dis[v]>w))
				dis[v]=w,q.push(make_pair(-dis[v],v));
		}
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back(make_pair(v,w)),e[v].push_back(make_pair(u,w));
	}
	for(int i=1;i<=k;i++){
		int v=n+i,x,p=-1;
		cin>>x;
		if(x!=0)	continue;
		for(int i=1;i<=n;i++){	
			cin>>tmp[i];
			if(tmp[i]==0)	p=i;
		}
		for(int i=0;i<e[p].size();i++)
			e[p][i].second=min(tmp[e[p][i].first],e[p][i].second);
		for(int i=1;i<=n;i++){
			bool flag=true;
			for(int j=0;j<e[i].size();j++)
				if(e[i][j].first==p)
					e[i][j].second=min(tmp[i],e[i][j].second),flag=false;
			if(flag)
				e[i].push_back(make_pair(p,tmp[i])),
				e[p].push_back(make_pair(i,tmp[i]));
		}
	}
	for(int i=1;i<=n+k;i++)	dis[i]=-1;
	prim(1);
//	for(int i=1;i<=n;i++){
//		cout<<i<<":";
//		for(int j=0;j<e[i].size();j++)
//			cout<<"To"<<e[i][j].first<<"need"<<e[i][j].second<<",";
//		cout<<"\n";
//	}
	cout<<ans;
	return 0;
}
/*
4 3 1
1 2 6
2 3 1
1 4 10
0 3 2 3 0
*/
//60+48=108pts.
