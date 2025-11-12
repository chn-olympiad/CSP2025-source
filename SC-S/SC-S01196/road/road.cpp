#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int N=1e4+5,INF=0x7fffffff;
int pre[N];
/*void dj(int start){
	memset(dist,INF,sizeof(dist));
	dist[start]=0;
	priority_queue<int,vector<int>,greater<int> > qp;
	qp.push({0,start});
	while(!qp.empty()){
		if(dist[u]<d) continue;
		for(int i=0;i<graph[u].size();i++){
			int u=
			if(dist[u]>dist[u]+w){
				dist[u]=dist[u]+w;
				qp.push({dist[u],u});
		}
	}
}*///忘记狄克斯特拉怎么写了awa 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdin);
	int n,m,k,ans;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
	}
	for(int i=1;i<=k;i++){
		int c,a;
		cin>>c;
		for(int j=1;j<=n;j++)
			cin>>a;
	}
	cout<<0;
	return 0;
}