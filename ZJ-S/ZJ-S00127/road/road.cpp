#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int fa[100005];
struct edge{
	int u,v,w;
}ed[1000005];
int sum=0;
int find(int x){
	if(x==fa[x])return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void mer(int x,int y){
	fa[find(x)]=find(y);
}
bool cmp(edge a,edge b){
	return a.w<b.w;
}
void bfs(){
	int num=0;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(ed+1,ed+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(find(ed[i].u)!=find(ed[i].v)){
			num+=ed[i].w;
			mer(ed[i].u,ed[i].v);
		}
	}
	cout<<num;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			ed[i]={u,v,w};
			sum+=w;
		}
		bfs();
	}
	
	return 0;
}
