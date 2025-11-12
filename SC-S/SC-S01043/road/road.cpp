#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
typedef pair<int,int> pii;
int dis[N],vis[N],to[N],nextn[N],head[N],qz[N],tot;
int n,m,k;
priority_queue<pii,vector<pii>,greater<pii> > q;
void add(int u,int v,int w){
	qz[tot++]=w;
	nextn[tot]=head[u];
	to[tot]=v;
	head[tot]=u;
}
void dijkstra(){
	while(!q.empty()){
		int v=q.top().second;
		if(vis[v]==0) continue;
		vis[v]=0;
		for(int i=head[v];i;i=nextn[i]){
			if(dis[v]>dis[u]+i){
				dis[v]=dis[u]+i;
				q.push({v,i});
			}
		}
	} 
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	dis[1]=0;
	q.push({0,});
	dijkstra();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
