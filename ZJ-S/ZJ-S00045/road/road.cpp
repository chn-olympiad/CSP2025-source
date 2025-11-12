#include<bits/stdc++.h>
namespace sol {
	using namespace std;
	int n,m,k;
	typedef long long ll;
	constexpr int maxn=1e4+5,maxm=1e6+7,maxk=11;
	ll c[maxk],a[maxk][maxn];
	struct Edge {
		int u,v;
		ll w;
	} edge[maxm+maxk*maxn];
	bool cmp(Edge lhs,Edge rhs) {
		return lhs.w<rhs.w;
	}
	int fa[maxn+maxk],st[maxn+maxk],stcnt;
	int find(int x) {
		while(fa[x]!=x) {
			st[++stcnt]=x;
			x=fa[x];
		}
		while(stcnt)
			fa[st[stcnt--]]=x;
		return x;
	}
	void uni(int u,int v) {
		u=find(u);
		v=find(v);
		fa[v]=u;
	}
	int main() {
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1; i<=n; ++i) {
			scanf("%d%d%lld",&edge[i].u,&edge[i].v,&edge[i].w);
		}
		bool flag=true;
		for(int i=1,j; i<=k; ++i) {
			scanf("%lld",c+i);
			if(c[i]>0)flag=false;
			bool tmp=false;
			for(j=1; j<=n; ++j) {
				scanf("%lld",a[i]+j);
				if(a[i][j]==0)
					tmp=true;
			}
			flag=flag&&tmp;
		}
		if(k==0) {
			sort(edge+1,edge+m+1,cmp);
			for(int i=1; i<=n; ++i)
				fa[i]=i;
			int cnt=0;
			ll ans=0;
			for(int i=1; i<=m; ++i) {
				int u=find(edge[i].u),v=find(edge[i].v);
				if(u!=v) {
					fa[v]=u;
					ans+=edge[i].w;
					++cnt;
				}
				if(cnt==n-1)
					break;
			}
			printf("%lld",ans);
		} else if(flag) {
			for(int i=1; i<=k; ++i)
				for(int j=1; j<=n; ++j)
					edge[++m]= {n+i,j,a[i][j]};
			sort(edge+1,edge+m+1,cmp);
			for(int i=1; i<=n+k; ++i)
				fa[i]=i;
			int cnt=0;
			ll ans=0;
			for(int i=1; i<=m; ++i) {
				int u=find(edge[i].u),v=find(edge[i].v);
				if(u!=v) {
					fa[v]=u;
					ans+=edge[i].w;
					++cnt;
				}
				if(cnt==n+k-1)
					break;
			}
			printf("%lld",ans);
		}
		return 0;
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	return sol::main();
}