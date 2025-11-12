#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define int long long
int fa[20005],cnt,ans,c[15],ca[10005][15];
struct node{
	int u,v,w;
}edges[4000005];
void add(int u,int v,int w){
	edges[++cnt].u=u;
	edges[cnt].v=v;
	edges[cnt].w=w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool cmp(node x,node y){
	return x.w<y.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w); 
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			ca[i][j]=w;
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=cnt;j++){
			edges[j].w=min(ca[i][edges[j].u]+ca[i][edges[j].v],edges[j].w);
		}
	} 
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(edges+1,edges+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int x=find(edges[i].u);
		int y=find(edges[i].v);
		if(fa[x]==y) continue;
		fa[x]=y;
		ans+=edges[i].w;
	}
	cout<<ans;
	return 0;
}
