#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
const int MAXN=10005;
const int MAXM=1000005;
int n,m,k,tot=0;
int c[15],a[15][MAXN],fa[MAXN];
struct Node{
	int u,v;
	ll w;
}e[MAXM];
bool cmp(Node x,Node y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	if(x==y) return;
	x=find(x),y=find(y);
	fa[x]=y;
}
ll kruskal(){
	ll ans=0;
	int cnt=n;
	sort(e+1,e+tot+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=tot;i++){
		int u=e[i].u,v=e[i].v;
		if(find(u)==find(v)) continue;
		merge(u,v);
		ans+=e[i].w;
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		e[++tot]=(Node){u,v,w};
		e[++tot]=(Node){v,u,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)  cin>>a[i][j];
	}
	if(k==0){
		cout<<kruskal();
		return 0;
	}
	return 0;
}
