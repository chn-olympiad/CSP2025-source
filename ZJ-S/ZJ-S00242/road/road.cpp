#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k;
struct edge{
	ll u,v,w;
}e[1000010];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int fa[10010];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
ll sum=0;
void merge(int x,int y,int z){
	int xx=find(x),yy=find(y);
	if(xx!=yy){
		fa[xx]=yy;
		sum+=z;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	if(k==0){
		for(int i=1;i<=m;i++){
			cin>>e[i].u>>e[i].v>>e[i].w;
		}
		sort(e+1,e+1+m,cmp);
		for(int i=1;i<=m;i++){
			merge(e[i].u,e[i].v,e[i].w);
		}
		cout<<sum<<'\n';
	}else{
		int cnt=0;
		for(int i=1;i<=m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			
		}
		sort(e+1,e+1+m,cmp);
		for(int i=1;i<=m;i++){
			merge(e[i].u,e[i].v,e[i].w);
		}
		cout<<sum<<'\n';
	}
	return 0;
}
