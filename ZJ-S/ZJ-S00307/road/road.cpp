#include <bits/stdc++.h>
using namespace std;
int n,m,k,c[15],a[15][10005],fa[10005],ans;
struct Edge{
	long long u,v,w;
};
int u,v,w;
vector<Edge> e;
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		e.push_back({u,v,w});
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			for(int k=1;k<j;k++){
				e.push_back({i,j,a[i][j]+a[i][k]});
			}
		}
		ans+=c[i];
	}
	sort(e.begin(),e.end(),cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=0;i<e.size();i++){
		u=e[i].u;v=e[i].v;w=e[i].w;
		u=find(u);v=find(v);
		if(u!=v){
			fa[v]=u;
			ans+=w;
		}
	}
	cout<<ans;
	return 0;
}