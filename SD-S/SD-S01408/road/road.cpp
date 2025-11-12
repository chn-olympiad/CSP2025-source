#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k,c[11],a[11][10010],fa[10010],b[10010][10010];
ll ans;
struct Info {
	int u,v,w;
	bool operator < (Info A) {
		return w<A.w;
	}
}edge[1000010];
int findset (int x) {
	if (fa[x]==x) return x;
	fa[x]=findset(fa[x]);
	return fa[x];
}
void scs () {
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++) {
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		int x=findset(u),y=findset(v);
		if (x!=y) {
			fa[x]=y;
			ans+=w;
		}
	}
}
int main () {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++) 
	for (int j=1;j<=n;j++) b[i][j]=1e9;
	for (int i=1;i<=m;i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		b[u][v]=min(b[u][v],w);
		edge[i].u=u;
		edge[i].v=v;
		edge[i].w=w;
	}
	if (k==0) {
		scs();
		sort(edge+1,edge+m+1);
		printf("%lld",ans);
		return 0;
	}
	else {
		ll ans=1e18;
		for (int i=1;i<=k;i++) {
			scanf("%d",&c[i]);
			ll sum=0;
			for (int A=1;A<=n;A++) {
				scanf("%d",&a[i][A]);
			}
			ans=min(ans,sum);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
