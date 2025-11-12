#include <cstdio>
#include <algorithm>
#include <vector>
typedef long long ll;
const int N=1e4+10;
int n,m,k;
ll ans;
int fa[N];
int edgeCnt; 
struct edge{
	int u,v;
	ll w;
};
std::vector<edge> edges;
void build(){
	for(int i=1;i<=n;i++) fa[i]=i;
}
int find(int i){
	if(fa[i]!=i) fa[i]=find(fa[i]);
	return fa[i];
}
bool unite(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		fa[fx]=fy;
		return true;
	}else return false;
} 
void kruskal(){
	for(int i=0;i<edges.size();i++){
		if(edgeCnt==n-1) break;
		if(unite(edges[i].u,edges[i].v)==true) edgeCnt++,ans+=edges[i].w; 
	} 
} 
int c[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	build();
	for(int i=1,u,v;i<=m;i++){
		ll w;
		scanf("%d%d%lld",&u,&v,&w);
		edges.push_back({u,v,w});
	}
//	for(int i=1;i<=k;i++){
//		int b;
//		scanf("%d",&b);
//		for(int j=1;j<=n;j++){
//			scanf("%d",&c[j]);
//			for(int l=1;l<n;l++){
//				edges.push_back({l,j,c[l]+c[j]+b});
//			}
//		}
//	}
	std::sort(edges.begin(),edges.end(),[](const edge &a,const edge &b){
		return a.w<b.w;
	});
	kruskal();
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
