#include<bits/stdc++.h>
//using namespace std;
struct edge{
	int u,v;
	long long w;
	int id;
};
long long c[10010][10];
std::vector<edge> e;
bool cmp1(edge x,edge y){
	return x.w<y.w;
}
int fa[10010],fe[20],fy[10010][20];
int gef(int x){
	if(fa[x]==x)return x;
	return fa[x]=gef(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,cnt=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v;i<=m;i++){
	long long w;
		scanf("%d%d%lld",&u,&v,&w);
		e.push_back({u,v,w,0});
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%lld",&c[j][i]);
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int l=j+1;l<=n;l++){
				e.push_back({j,l,c[0][i]+c[j][i]+c[l][i],i});
			}
		}
	}
	long long ans=0;
	std::sort(e.begin(),e.end(),cmp1);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=0;i<e.size()&&cnt<n-1;i++){
		int u=e[i].u,v=e[i].v;
		u=gef(u),v=gef(v);
		if(fa[u]!=v){
			if(e[i].id&&!fy[u][e[i].id])fy[u][e[i].id]=1;
			else if(e[i].id&&!fy[v][e[i].id])fy[v][e[i].id]=1;
			else if(e[i].id&&!fe[e[i].id])fe[e[i].id]=1;
			else if(e[i].id){
				ans+=e[i].w-c[0][e[i].id]*fe[e[i].id]-c[u][e[i].id]*fy[u][e[i].id]-c[v][e[i].id]*fy[v][e[i].id];
				fa[u]=v;
				cnt++;
				continue;
			}
			ans+=e[i].w;
			fa[u]=v;
			cnt++;
		}
	}
	printf("%lld",ans);
	return 0;
}

