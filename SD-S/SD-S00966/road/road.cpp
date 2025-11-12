#include<bits/stdc++.h>
#define int long long
#define inf 1e9
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int N=1e6+10;
const int M=1e3+10;
struct node{
	int v,w;
};
vector<node> e[N];
int n,m,k,dis[M][M],vis[N],ans=0;
void prim(int x){
	dis[x][x]=0;
	vis[x]=1;
	int dist=inf;
	int u=x;
	for(int i=1;i<=n+k;i++){
		if(dis[x][i]!=inf&&dis[x][i]<dist&&!vis[i]){
			u=i;
			dist=dis[x][i];
		}
	}
	//return;
	ans+=dist;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i].v,w=e[u][i].w;
		dis[u][v]=min(dis[u][v],w);
		//cout<<u<<"->"<<v<<":"<<dis[u][v]<<"\n";
	}
	prim(u);
	return ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u,v,w;
		u=read(),v=read(),w=read();
		//e[u].push_back({v,w});
		//e[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		int c;
		c=read();
		for(int j=1;j<=n;j++){
			int w;
			w=read();
			//e[i+n].push_back({j,c+w});
			//e[j].push_back({n+i,c+w});
		}
	}
	for(int i=1;i<=n+k;i++){
		for(int j=1;j<=n+k;j++){
			dis[i][j]=inf;
		}
	}
	//prim(1);
	cout<<ans<<"\n";
	return 0;
}
/*
-g3
*/
