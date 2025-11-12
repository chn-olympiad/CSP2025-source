#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int x=0,ch=getchar();
	for(;!isdigit(ch);ch=getchar()) ;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch&15);
	return x;
}

using ll=long long;
const int N=1e4+20,M=1e6+5,SK=11,K=1<<10|5;
int n,m,k,fa[N],cnt[K],c[SK];
struct edges {
	int u,v,w;
	inline bool operator <(const edges &tmp) const {return w<tmp.w;}
};
edges edg[M],p[K][N],temp[N<<1],a[SK][N];
ll ans[K],csum[K];

inline void initset() {for(int i=1;i<=n+k;i++) fa[i]=i;}
inline int findfa(int x) {return (x!=fa[x])?(fa[x]=findfa(fa[x])):x;}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) edg[i].u=read(),edg[i].v=read(),edg[i].w=read();
	initset(),sort(edg+1,edg+1+m);
	for(int i=1,k=1;k<n;i++) {
		int u=edg[i].u,v=edg[i].v,w=edg[i].w;
		if(findfa(u)==findfa(v)) continue ;
		if(i>m&&k<n) return printf("incorret\n"),0;
		fa[fa[v]]=fa[u],p[0][k++]=edg[i],ans[0]+=w;
	}
	ll totalans=ans[0];
	for(int i=1;i<=k;i++) {
		c[i]=read();
		for(int j=1;j<=n;j++) a[i][j].u=i+n,a[i][j].v=j,a[i][j].w=read();
		sort(a[i]+1,a[i]+1+n);
	}
	cnt[0]=n;
	for(int stat=1;stat<(1<<k);stat++) {
		int i=1,r=0,k=1,ps=1,pt=1;
		while(!(stat>>(i-1)&1)) ++i;
		r=stat^(1<<(i-1)),csum[stat]=csum[r]+c[i],cnt[stat]=cnt[r]+1;
		for(;ps<=cnt[r]&&pt<=n;k++)
			if(a[i][pt].w<p[r][ps].w) temp[k]=a[i][pt++];
			else temp[k]=p[r][ps++];
		for(;ps<=cnt[r];k++) temp[k]=p[r][ps++];
		for(;pt<=n;k++) temp[k]=a[i][pt++];
		initset();
		for(int i=1,l=1;l<cnt[stat];i++) {
			int u=temp[i].u,v=temp[i].v,w=temp[i].w;
			if(findfa(u)==findfa(v)) continue ;
			fa[fa[v]]=fa[u],p[stat][l++]=temp[i],ans[stat]+=w;
		}
		totalans=min(totalans,ans[stat]+csum[stat]);
	}
	printf("%lld\n",totalans);
	return 0;
}

// 16:05
