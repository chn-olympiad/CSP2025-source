#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,K=15;
struct node{
	int v,w;
};
int n,m,k,c[K],a[K][N],p[N],ans;
bool vis[N];
vector<node> g[N];
inline int find(int x){
	if(p[x]==x) return x;
	return p[x]=find(p[x]);
}
inline void merge(int x,int y){
	int px=find(x),py=find(y);
	if(px!=py){
		p[px]=py;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	//if(k==0){
		for(int i=1;i<=n;i++){
			p[i]=i;
		}
		for(int t=1;t<=n;t++){
			memset(vis,0,sizeof vis);
			for(int i=1;i<=n;i++){
				if(vis[i]) continue;
				int k=-1;
				for(int j=0;j<g[i].size();j++){
					int to=g[i][j].v;
					if((k==-1||g[i][j].w<g[i][k].w)&&find(i)!=find(to)){
						k=j;
					}
				}
				if(k!=-1){
					int to=g[i][k].v;
					if(vis[to]) continue;
					vis[to]=1;
					merge(i,to);
					ans+=g[i][k].w;
				}
			}
		}
		printf("%d\n",ans);
	//}
	
	return 0;
}
/*
6 8 0
1 2 1
2 3 2
3 4 4
2 4 3
4 5 6
5 6 5
2 6 8
1 6 7
*/

