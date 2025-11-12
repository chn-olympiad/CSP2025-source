#include  <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,k;
struct node{
	int u,v,w;
}edge[N];
int c[N];
int fa[N];
int get(int x){
	if (x==fa[x]) return x;
	return fa[x]=get(x);
}
void merge(int x,int y){
	fa[x]=y;
}
bool cmp(node a,node b){
	return a.w<b.w;
}
int ans=0;
bool make[N];
int main (){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		int u,v,w;
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	}
	int tot=n,edge_tot=m;
	for (int i=1;i<=k;i++){
		tot++;
		cin>>c[i];
		for (int j=1;j<=n;j++){
			edge[++edge_tot].u=tot,edge[edge_tot].v=j;
			cin>>edge[edge_tot].w;
		}
	}
	for (int i=1;i<=tot;i++){
		fa[i]=i;
	}
	sort(edge+1,edge+1+edge_tot,cmp);
	int cnt=0;
	for (int i=1;i<=edge_tot;i++){
		if (cnt==n) break;
		int uv=get(edge[i].v);
		int uu=get(edge[i].u);
		if (uu==uv) continue;
		merge(uv,uu);
		ans+=edge[i].w;
	}
	cout<<ans<<"\n";
	
	
	return 0;
}
