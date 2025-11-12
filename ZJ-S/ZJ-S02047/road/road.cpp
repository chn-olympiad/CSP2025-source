#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[1000005],p[15],ans,cnt,c,fa[1000005];
bool vis[15];
struct node {
	long long u,v,w,f;
};
node g[10000005];
bool cmp(node x,node y) {
	return x.w<y.w;
}
int find(int x) {
	if(fa[x]!=x) return fa[x]=find(fa[x]);
	return x;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0) {
		for(int i=1; i<=n; ++i) fa[i]=i;
		for(int i=1,x,y,z; i<=m; ++i) {
			cin>>x>>y>>z;
			g[++cnt]= {x,y,z,1};
		}
		sort(g+1,g+cnt+1,cmp);
		for(int i=1; i<=cnt&&c<=n-2; ++i) {
			if(find(g[i].u)!=find(g[i].v)) {
				fa[g[i].v]=fa[g[i].u];
				ans+=g[i].w;
				++c;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1; i<=n; ++i) fa[i]=i;
	for(int i=1,x,y,z; i<=m; ++i) {
		cin>>x>>y>>z;
		g[++cnt]= {x,y,z,1};
	}
	long long maxx=0;
	for(int i=1; i<=k; ++i) {
		cin>>p[i];
		maxx=max(maxx,p[i]);
		for(int i=1; i<=n; ++i) cin>>a[i],maxx=max(maxx,p[i]);
		for(int i=1; i<=n; ++i)
			for(int j=i+1; j<=n; ++j) {
				g[++cnt]= {i,j,p[i]+a[i]+a[j],i+1};
			}
	}
	if(!maxx) {
		cout<<'0';
		return 0;
	}
	sort(g+1,g+cnt+1,cmp);
	for(int i=1; i<=cnt; ++i) {
		if(g[i].f>1) {
			if(!vis[g[i].f]) vis[g[i].f]=1;
			else g[i].w-=p[g[i].f-1];
		}
	}
	for(int i=1; i<=cnt&&c<=n-2; ++i) {
		if(find(g[i].u)!=find(g[i].v)) {
			fa[g[i].v]=fa[g[i].u];
			ans+=g[i].w;
			++c;  
		}
	}
	cout<<ans;
	return 0;
}
