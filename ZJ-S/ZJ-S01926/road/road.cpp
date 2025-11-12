#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
}e[10002];
int n,m,k,a[11],fa[10002],rx,ry,ans;
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		e[++k]=(node){u,v,w};
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		rx=find(e[i].u);
		ry=find(e[i].v);
		if(rx!=ry){
			ans+=e[i].w;
			fa[rx]=ry;
		}
	}
	cout<<ans;
	return 0;
}
