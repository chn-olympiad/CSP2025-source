#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,k;
int u,v,w;
struct edge2{
	int co;int to;int val;
}e[1000010];
bool ch[1000010];
int fa[10010];
int find(int x){
	if(fa[x]==x)return x;
	else{
		return fa[x]=find(fa[x]);	
	}
}
bool cmp(edge2 p,edge2 q){
	return p.val<q.val;
}
long long ans;
void kruskal(){
	sort(e+1,e+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(find(e[i].co)==find(e[i].to)){
			continue;
		}
		ans+=e[i].val;
		ch[i]=1;
		fa[find(e[i].co)]=fa[find(e[i].to)];
	}
}
int c[15];
int a[15][10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		e[i].co=u;
		e[i].to=v;
		e[i].val=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	int id=m+1;
	for(int i=1;i<=k;i++){
		if(c[i]=0){
			for(int j=1;j<=n;j++){
				e[id].co=;
				e[id].to=;
				e[id].val=;
			}
		}
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	kruskal();
	cout<<ans;
	return 0;
}
