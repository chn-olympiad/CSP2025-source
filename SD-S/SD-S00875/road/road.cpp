#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
int n,m,k,tot=0,ans;
int dis[M],vis[M];
int head[M];
struct Node{
	int u,v,w;
	int nxt;
}e[M];
void add(int u,int v,int w){
	e[++tot].u=u;
	e[tot].v=v;
	e[tot].w=w;
	e[tot].nxt=head[u];
	head[u]=tot;
}
struct node{
	int now;
	bool operator<(const node& x) const{
		return now>x.now;
	}
};
priority_queue<node> q;
void dij(){
	for(int i=1;i<=m;i++)
		dis[i]=0x7fffffff,vis[i]=1;
	q.push({1,1});
	vis[1]=0;
	while(!q.empty()){
		int u=q.top();
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].v,w=e[i].w;
			if(dis[u]>dis[v]+w)
				dis[u]=dis[v]+w;
		}
		q.pop();
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	dij();
	for(int i=1;i<=m;i++) ans=max(dis[i],ans);
	return 0;
}

