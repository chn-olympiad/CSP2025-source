#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Node{
	int u,v,w;
}edge[1000010];
int n,m,k;
int fa[10010];
int cost[15];
bool vis[10010];
int find_(int x){
	if(x==fa[x]) return x;
	return fa[x]=find_(fa[x]);
}
bool cmp(Node x,Node y){
	return x.w<y.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		edge[i].u=x; edge[i].v=y; edge[i].w=z;
	} 
	for(int i=1;i<=k;i++){
		cin>>cost[i];
		for(int j=1;j<=n;j++){
			int z;
			cin>>z;
			edge[m+i*j].u=j,edge[m+i*j].v=n+i,edge[m+i*j].w=z;
		}
	}
	stable_sort(edge+1,edge+m+n*k+1,cmp);
	int min_=0,cnt=0;
	while((++cnt)<=m+n*k){
		int _1=find_(edge[cnt].u);
		int _2=find_(edge[cnt].v);
		if(_1!=_2){
			fa[_1]=fa[_2];
			min_+=edge[cnt].w;
		}
	}
	printf("%d\n",min_);
	return 0;
}
/*
5 5 1
1 2 2
2 3 5
3 4 3
4 5 2
1 5 1
0 1 1 1 1 1
*/
