#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e6+5;
struct edge{
	int u,w,v;
}e[N];
int p[N];
int find(int x){
	if(p[x]==x) {
		return x;
	}
	p[x]=find(p[x]);
	return p[x];
}
void merge(int x,int y){
	int a=find(x),b=find(y);
	p[a]=b;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;cin>>n>>m>>k;
	for(int i=1; i<=m; i++){
		int u,w,v;cin>>u>>v>>w;
		e[i]={u,w,v};
	}
	sort(e+1,e+m+1,[](edge a,edge b){return a.w<b.w;});
	for(int i=1; i<=n; i++){ p[i]=i; }
	int sum=0,all;
	for(int i=1; i<=m; i++){
		int u=e[i].u,v=e[i].v;
		if(all=n-1) break;
		int x=find(u),y=find(v);
		if(x==y) continue;
		merge(u,v);
		sum+=e[i].w;	
	}
	cout<<sum;
	return 0;
}