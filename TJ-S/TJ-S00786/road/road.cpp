#include <bits/stdc++.h>
using namespace std;
int n,m,k;
struct edge{
	int to,next,w;
}q[2020005];
int tot,h[10015],c[15],a[15][10005],fa[10015],ans;
void addEdge(int u,int v,int w){
	q[++tot]={v,h[u],w};
	h[u]=tot;
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
void init(int n){
	for (int i=1;i<=n;i++){
		fa[i]=i;
	}
}
int get(int u){
	if (u==fa[u]){
		return u;
	}
	fa[u]=get(fa[u]);
	return fa[u];
}
bool merge(int x,int y){
	x=get(x);
	y=get(y);
	if (x==y){
		return false;
	}
	fa[x]=y;
	return true;
}
void kru(){
	sort(q+1,q+1+tot,cmp);
	int cnt=0;
	for (int i=1;i<=n;i++){
		for (edge e=q[h[i]];e.to;e=q[e.next]){
			if (merge(i,e.to)){
				ans+=e.w;
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		addEdge(u,v,w);
		addEdge(v,u,w);
	}
	for (int i=1;i<=k;i++){
		cin>>c[i];
		for (int j=1;j<=n;j++){
			cin>>a[i][j];
			addEdge(n+i,j,a[i][j]);
			addEdge(j,n+i,a[i][j]);
		}
	}
	kru();
	cout<<0;
	return 0;
}
