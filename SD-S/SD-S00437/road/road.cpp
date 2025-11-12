#include<bits/stdc++.h>
using namespace std;
const int M=1e8+10000,N=1e4+100,K=15;
struct edge {
	int u,v;//两个城市
	int w;//费用
} edges[M];
bool cmp(const edge&x,const edge&y) {
	return x.w<y.w;
}
int n,m,k;
long long ans;

//并查集：
int fa[N];
inline int getfa(int x) {
	if(fa[x]==x)
		return x;
	fa[x]=getfa(fa[x]);
}
void init() {
	for(int i=1; i<=n; i++)
		fa[i]=i;
}
int c,a[N];
int e[N][N];//u,v,是否连边,边权是多少
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	if(k) {
		printf("0\n");
	} else {
		init();
		for(int i=1; i<=m; i++) {
			scanf("%d%d%d",&edges[i].u,&edges[i].v,&edges[i].w);
			e[edges[i].u][edges[i].v]=edges[i].w;
		}
		for(int i=1; i<=k; i++) {
			scanf("%d",&c);
			for(int j=1; j<=n; j++)
				scanf("%d",&a[j]);
			for(int u=1; u<n; u++)
				for(int v=u+1; v<=n; v++) {
					if((!e[u][v])||(a[u]+a[v]+c<e[u][v])) {
						e[u][v]=a[u]+a[v]+c;
						e[v][u]=a[u]+a[v]+c;
						edges[++m].u=u;
						edges[m].v=v;
						edges[m].w=a[u]+a[v]+c;
					}
				}
		}
		sort(edges+1,edges+m+1,cmp);//从小到大排序
		int cnt=0;//已经建好的边
		int i=1;//从前往后取边
		while(cnt<n-1) {
			if(getfa(edges[i].u)!=getfa(edges[i].v)) {
				ans+=edges[i].w;
				cnt++;
				fa[edges[i].v]=fa[edges[i].u];
			}
			i++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
