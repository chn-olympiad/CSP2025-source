#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e4+5,M=2e6+5;
int n,m,k,c[N],fa[N];
ll ans;
struct Edge {
	int u,v,w;
}e[M];
bool cmp(Edge x,Edge y) {
	return x.w<y.w;
}
int found(int x) {
	if (fa[x]!=x) fa[x]=found(fa[x]);
	return fa[x];
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++) {
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	if (k==0) {
		for (int i=1;i<=n;i++)
			fa[i]=i;
		sort(e+1,e+m+1,cmp);
		for (int i=1;i<=m;i++) {
			int r1=found(e[i].u),r2=found(e[i].v);
			if (r1!=r2) {
				ans+=1LL*e[i].w;
				fa[r1]=r2;
			}
		}
		printf("%lld\n",ans);
	} else {
		int n1=n;
		for (int i=1;i<=k;i++) {
			scanf("%d",&c[i]);
			n++;
			for (int j=1;j<=n1;j++) {
				int w;
				scanf("%d",&w);
				e[++m]={j,n,w};
			}
		}
		for (int i=1;i<=n;i++)
			fa[i]=i;
		sort(e+1,e+m+1,cmp);
		for (int i=1;i<=m;i++) {
			int r1=found(e[i].u),r2=found(e[i].v);
			if (r1!=r2) {
				ans+=1LL*e[i].w;
				fa[r1]=r2;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
