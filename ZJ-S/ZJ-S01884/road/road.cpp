#include<bits/stdc++.h>
using namespace std;
int read() {
	char z=getchar();
	int x=0;
	while(z<48) z=getchar();
	while(z>47) x=x*10+(z^48), z=getchar();
	return x;
}
int n,m,k,fa[10015];
long long ans=1e18;
int find(int x) {
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
struct node {
	int v,w;
};
vector<node> G[10005];
struct edge {
	int u,v,w;
	bool operator < (const edge &y) const {
		return w<y.w;
	}
} e[1000005],e2[10005],a[15][10005];
int c[15],pos[15];
int tot;
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(), m=read(), k=read();
	for(int i=1; i<=m; i++) {
		int u,v,w;
		u=read(), v=read(), w=read();
		e[i]= {u,v,w};
	}
	sort(e+1,e+1+m);
	for(int i=1; i<=n; i++) fa[i]=i;
	for(int i=1, j=0; i<=m && j<n-1; i++) {
		int p=find(e[i].u), q=find(e[i].v);
		if(p!=q) {
			fa[p]=q;
			G[e[i].u].push_back({e[i].v,e[i].w});
			G[e[i].v].push_back({e[i].u,e[i].w});
			e2[++tot]= {e[i].u,e[i].v,e[i].w};
			j++;
//			printf("(%d,%d,%d)\n",e[i].u,e[i].v,e[i].w);
		}
	}
	for(int i=1; i<=k; i++) {
		c[i]=read();
		for(int j=1; j<=n; j++) {
			int t=read();
			a[i][j]= {n+i,j,t};
		}
		sort(a[i]+1,a[i]+n);
	}
	assert(tot==n-1);
	for(int s=0; s<(1<<k); s++) {
		int n2=n;
		long long ex=0;
		for(int i=1; i<=k; i++)
			if(s&(1<<(i-1)))
				n2++, ex+=c[i];
		for(int i=1; i<=n+k; i++) fa[i]=i;
		long long ws=0;
		for(int i=0; i<=k; i++) pos[i]=1;
		for(int j=0; j<n2-1;) {
			int mi=1e9,u,v,w,src=-1;
			for(int r=1; r<=k; r++) {
				if(s&(1<<(r-1))) {
					if(pos[r]<=n && a[r][pos[r]].w<=mi) {
						mi=a[r][pos[r]].w;
						u=a[r][pos[r]].u, v=a[r][pos[r]].v, w=a[r][pos[r]].w;
						src=r;
					}
				}
			}
			if(pos[0]<n && e2[pos[0]].w<=mi) {
				mi=e2[pos[0]].w;
				u=e2[pos[0]].u, v=e2[pos[0]].v, w=e2[pos[0]].w;
				src=0;
			}
			pos[src]++;
//			printf("(%d,%d,%d) j=%d s=%d\n",u,v,w,j,s);
			assert(src!=-1);

			int p=find(u), q=find(v);
			if(p!=q) fa[p]=q, ws+=w, j++;
		}
		ans=min(ans,ws+ex);
	}
	cout<<ans;
	return 0;
}
