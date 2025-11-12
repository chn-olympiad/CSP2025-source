#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
};
vector<node>adj[10020];
int c[20][100010];
int n,m,k;
int vis[10020];
long long ju[10020];
int dad[10020];
int dis[20010];
void spfa(int s){
	queue<int>pq;
	pq.push(s);
	for(int i=1;i<=n+k;i++){
		vis[i]=0;
		ju[i]=1e9;
		dis[i]=1e9;
	}
	vis[s]=1;
	ju[s]=0;
	dis[s]=0;
	while(pq.size()){
		int u=pq.front();
		pq.pop();
		vis[u]=0;
		for(int i=0;i<adj[u].size();i++){
			int v=adj[u][i].v;
			int w=adj[u][i].w;
			if((dis[v]>dis[u]+w || (dis[v]==dis[u]+w && ju[v]>w)) && dad[u]!=v){
				dis[v]=dis[u]+w;
				ju[v]=w;
				dad[v]=u;
				if(!vis[v]){
					pq.push(v);
				}
			}
		}
	}
	return;
}
int vip[100010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
    	int u,v,w;
    	cin>>u>>v>>w;
    	adj[u].push_back({u,v,w});
    	adj[v].push_back({v,u,w});
	}
	for(int i=1;i<=k;i++){
		int cj;
		cin>>cj;
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			adj[i+n].push_back({i+n,j,w});
			adj[j].push_back({j,n+i,w+cj});
		}
	}
	spfa(1);
	long long sum=0;
	for(int j=1;j<=n;j++){
		if(ju[j]!=1e9){
		    sum+=ju[j];
		}
		if(dad[j]>n && !vip[dad[j]]){
		    sum+=ju[dad[j]];
			vip[dad[j]]=1;	
		}
	}
	cout<<sum;
	return 0;
}
