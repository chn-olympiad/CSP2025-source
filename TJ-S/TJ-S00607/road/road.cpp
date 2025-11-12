#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=0;
struct edge{
	int v;
	int w;
};
vector<edge> adj[10005];
int newr[15][10005];
int ncon[10005][10005];
int conn[10005][10005]={INT_MAX};
void conci(int p,int q){
	for(int i=1;i<=n;i++){
		if(conn[q][i]!=INT_MAX){
			conn[p][i]=min(conn[p][i],conn[p][q]+conn[q][i]);
			conn[i][p]=conn[p][i];
		}
		if(conn[p][i]!=INT_MAX){
			conn[q][i]=min(conn[q][i],conn[p][q]+conn[p][i]);
			conn[i][q]=conn[q][i];
		}
	}
}
int con[10005]={0};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			conn[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		conn[u][v]=min(conn[u][v],w);
		conn[v][u]=conn[u][v];
		conci(u,v);
	}
	for(int i=1;i<=k;i++){
		cin>>newr[i][0];
		for(int j=1;j<=n;j++){
			cin>>newr[i][j];
			for(int i1=1;i1<j;i1++){
				conn[j][i1]=min(conn[j][i1],newr[i][0]+newr[i][i1]+newr[i][j]);
				conn[i1][j]=conn[j][i1];
			}
		}
	}
	int q=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(i==j) continue;
			con[++q]=conn[i][j];
		}
	}
	sort(con+1,con+q+1);
	for(int i=1;i<=3;i++){
		ans+=con[i];
	}
	cout<<ans;
	return 0;
} 

