#include<bits/stdc++.h>
using namespace std;
int n1;
long long n,m,k,ans,flag=0,bui[1000010],a[20][1000010];
struct node{
	int to;
	long long vil;
};
vector<node>G[1000010];
//dij
long long vis[2000010],dis[2000010],la[2000010],ff[2000010];
queue<int>q;
void dij(){
	for(int i=1;i<=n1;i++) dis[i]=2e9;
	q.push(1);
	vis[1]=1;
	dis[1]=0;
	while(!q.empty()){
		int now=q.front();
//		cout<<now<<" ";
		q.pop();
		vis[now]=0;
		for(int i=0;i<G[now].size();i++){
			int nxt=G[now][i].to;
//			cout<<nxt<<" ";
			if(dis[now]+G[now][i].vil<dis[nxt]){
				dis[nxt]=dis[now]+G[now][i].vil;
				if(!vis[nxt]) q.push(nxt);
				vis[nxt]=1;
				la[nxt]=G[now][i].vil;
				if(nxt>n) la[nxt]=la[now];
				if(now>n) la[nxt]=dis[nxt]-la[now];
			}
		}
//		cout<<"\n";
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	n1=n;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>bui[i];
		if(bui[i]!=0) flag=1;
		else n1++;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			G[j].push_back({n1,a[i][j]+bui[i]});
			G[n1].push_back({j,a[i][j]+bui[i]});
		}
	}
	if(k==0){
		dij();
		for(int i=1;i<=n;i++) ans+=la[i];
		cout<<ans;
		return 0;
	}
	if(!flag){
		dij();
		for(int i=1;i<=n;i++) ans+=la[i];
		cout<<ans;
		return 0;
	}
	dij();
	for(int i=1;i<=n;i++) ans+=la[i];
	cout<<ans;
	return 0;
}
/*
5 7 1
1 2 20
1 3 37
1 5 10
2 3 52
2 5 24
3 4 68
4 5 25
0 2 3 5 100 100
*/
