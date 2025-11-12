/*
注意ll,空间，文件名,删调试语句
T2
最小生成树变形 
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
int n,m,k,fa[N];
ll ans;
struct node{
	int u,v,w;
}E[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		E[i]={u,v,w};
	}
	for(int i=1,c;i<=k;i++){
		cin>>c;
		for(int j=1,w;j<=n;j++) cin>>w;
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(E+1,E+1+m,cmp);
	for(int i=1;i<=m;i++){
		int u=E[i].u,v=E[i].v,w=E[i].w;
		if(find(u)==find(v)) continue;
		fa[find(u)]=find(v);
		ans+=w;
	}
	cout<<ans;
	return 0;
}
