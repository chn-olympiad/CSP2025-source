#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int n,m,k;
//struct Edge{
//	int to,w;
//};
//vector<Edge> G[10015];
struct Edge{
	int u,v,w;
}e[1000015];
int tot=0;
int c[15],a[15][10015];
int fa[10015];

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

bool cmp(Edge aa,Edge bb){
	return aa.w<bb.w;
}

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[++tot].u=u,e[tot].v=v,e[tot].w=w;
//		e[++tot].u=v,e[tot].v=u,e[tot].w=w;
//		G[u].push_back((Edge){v,w});
//		G[v].push_back((Edge){u,w});
	}
	int sA=1;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0) sA=0;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	if(sA){
//		for(int i=1;i<=k;i++){
//			for(int j=1;j<=n;j++){
//				e[++tot].u=i+n,e[tot].v=j,e[tot].w=a[i][j];
//				e[++tot].u=j,e[tot].v=i+n,e[tot].w=a[i][j];
//				G[n+i].push_back((Edge){j,a[i][j]});
//				G[j].push_back((Edge){n+i,a[i][j]});
//			}
//		}
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				for(int l=i;l<=n;l++){
					e[++tot].u=j,e[tot].v=l,e[tot].w=a[k][i]+a[k][j];
				}
			}
		}
		n+=k,m+=2*n;
		for(int i=1;i<=n;i++) fa[i]=i;
		int ans=0;
		sort(e+1,e+tot+1,cmp);
//		cout<<tot<<"\n";
		for(int i=1;i<=tot;i++){
			int u=min(e[i].u,e[i].v),v=max(e[i].u,e[i].v);
			if(find(u)==find(v)) continue;
			ans+=e[i].w;
//			cout<<u<<" "<<v<<"--"<<find(u)<<" "<<find(v)<<"\n";
			fa[u]=v;
//			cout<<find(e[i].u)<<" "<<find(e[i].v)<<"\n";
		}
		printf("%d\n",ans);
	}
	
	
	return 0;
}
/*
4 4 2
1 4 6
4 3 4
4 2 5
2 3 7
0 1 8 2 4
0 1 3 2 4
*/

//The end.
//The situation now: dying
