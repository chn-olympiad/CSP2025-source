#include <cstdio>
#include <algorithm>
#include <cstring>
namespace xingzhiA {
	const int N=10007,K=17,M=1000007;
	int n,m;
	int fa[N];
	int fr(int x) {
		if (fa[x]!=-1) {
			// printf("%d ",x);
			fa[x]=fr(fa[x]);
			return fa[x];
		} else {
			// puts("1");
			// printf("%d\n",x);
			return x;
		}
	}
	int k=0;
	int c[K];
	void comb(int x,int y) {
		int fx=fr(x),fy=fr(y);
		fa[fx]=fy;
	}
	struct Edge {
		int x,y,v;
	}e[M+N*K];
	bool operator < (Edge a,Edge b) {
		return a.v<b.v;
	}
	int kruskal() {
		int ans=0;
		// puts("1");
		// std::sort(e+1,e+1+m);
		// puts("1");
		// printf("%d\n",m);
		for (int i=1;i<=m;i++) {
			// puts("1");
			// printf("%d\n",f)
			// printf("%d %d %d\n",e[i].x,e[i].y,e[i].v);
			if (fr(e[i].x)!=fr(e[i].y)) {
				// puts("1");
				comb(e[i].x,e[i].y);
				ans+=e[i].v;
			}
		}
		return ans;
	}
	int a[N][K];
	void solve() {
		memset(fa,-1,sizeof fa);
		scanf("%d%d%d",&n,&m,&k);
		// printf("%d\n",m);
		// m=1000000;
		for (int j=1;j<=m;j++) {
			scanf("%d%d%d",&e[j].x,&e[j].y,&e[j].v);
		}
		for (int i=1;i<=k;i++) {
			scanf("%d",&c[i]);
			for (int j=1;j<=n;j++) scanf("%d",&a[i][j]);
		}
		int sum=0;
		for (int i=1;i<=k;i++) {
			for (int j=1;j<=n;j++) if (a[i][j]==0) {
				e[++m]={i,j,a[i][j]};
				sum+=c[i];
			}
		}
		// printf("%d\n",m);
		std::sort(e+1,e+1+m);
		printf("%d\n",kruskal()+sum);
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	xingzhiA::solve();
	return 0;
}
