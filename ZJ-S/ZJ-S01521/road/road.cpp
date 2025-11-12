#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+26,M=1e6+1e5+6;
int n,m,k,idx,fa[N],c[26],cnt[N],sum[N],flag[N],a[26][N];
struct Node {
	int u,v,w;
}e[M],g[M];
int find (int x) {
	return (fa[x]==x?fa[x]:fa[x]=find(fa[x]));
} 
bool mycmp (Node x,Node y) {
	return x.w<y.w;
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for (int i=1;i<=m;++i) {
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		g[++idx]={u,v,w};
	}
	for (int i=1;i<=k;++i)	{
		scanf("%lld",&c[i]);
		for (int j=1;j<=n;++j) {
			int w; scanf("%lld",&a[i][j]);
			g[++idx]={i+n,j,a[i][j]};
		}
	}
	sort(g+1,g+idx+1,mycmp);
	for (int i=1;i<=n+k;++i) fa[i]=i;
	int lst=0;
	for (int i=1;i<=idx;++i) {
		int x=find(g[i].u),y=find(g[i].v);
		if (x!=y) {
			if (g[i].u>n) continue;
			if (g[i].v>n) continue;
			fa[x]=y;
			lst=i;
			e[++lst]=g[i];
		}
	}
	idx=lst;
	for (int i=1;i<=k;++i)	{
		for (int j=1;j<=n;++j) {
			e[++idx]={i+n,j,a[i][j]};
		}
	}
	sort(e+1,e+idx+1,mycmp);
	int res=1e12;
	for (int s=0;s<(1<<k);++s) {
		int st=s,id=n,ans=0;
		for (int i=1;i<=n+k;++i) fa[i]=i;
		for (int i=n+1;i<=n+k;++i) flag[i]=0;
		while (st) {
			flag[++id]=st%2;
			st/=2;
		}
		for (int i=1;i<=idx;++i) {
			int x=find(e[i].u),y=find(e[i].v);
			if (x!=y) {
				if (e[i].u>n && !flag[e[i].u]) continue;
				if (e[i].v>n && !flag[e[i].v]) continue;
				ans+=e[i].w;
				fa[x]=y;
			}
		}
		for (int i=n+1;i<=n+k;++i) {
			if (flag[i]) ans+=c[i-n];
		}
		res=min(res,ans);
	}
	printf("%lld\n",res);
	return 0;
}