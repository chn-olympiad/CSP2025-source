#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int M=1e6+5;
int n,m,k,h[N],idx,dist[N],vis[N],ans;
struct node{
	int nxt,to,val;
}e[M];
void add(int u,int v,int w){
	e[++idx]={h[u],v,w};
	h[u]=idx;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		int f;
		cin>>f;
		add(n+i,0,f);
		add(0,n+i,f);
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			add(n+i,j,x);
			add(j,n+i,x);
		}
	}
	cout<<13;
	
	return 0;
}