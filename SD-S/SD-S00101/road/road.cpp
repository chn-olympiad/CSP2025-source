#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
typedef unsigned long long ull;
typedef long long ll;
const ull N=10020,M=1100010,K=20;
ull n,m,k,sm[K],ans;
struct Edge
{
	ull u,v,w,t;
}e[M];
bool operator<(const Edge&a,const Edge&b) { return a.w<b.w; }
ull c[K],a[K][N];
ull tot;
ull fa[N],sz[N];
ull fd(ull x) { return x==fa[x]?x:fa[x]=fd(fa[x]); }
ull nw;
ull calc(ull w)
{
	ull res=0;
	for(ull i(0);i<=k;++i) if((w>>i)&1) res+=c[i];
	for(ull i(1);i<=n+k;++i) fa[i]=i,sz[i]=1;
	for(ull i(1);i<=tot;++i)
	{
		if(!((w>>e[i].t)&1)) continue;
		ull x=fd(e[i].u),y=fd(e[i].v),w=e[i].w;
		if(x==y) continue;
		res+=w;
		if(sz[x]>sz[y]) x^=y^=x^=y;
		fa[x]=y;
		sz[y]+=sz[x];
	}
	return res;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%llu%llu%llu",&n,&m,&k);tot=m;ans=~0ull;
	for(ull i(1);i<=m;++i) scanf("%llu%llu%llu",&e[i].u,&e[i].v,&e[i].w),e[i].t=0;
	bool flg=1;
	for(ull i(1);i<=k;++i)
	{
		scanf("%llu",&c[i]);
		bool flg2=0;
		for(ull j(1);j<=n;++j)
		{
			scanf("%llu",&a[i][j]);
			if(a[i][j]==0) flg2=1;
			ull p=++tot;
			e[p].u=j,e[p].v=i+n,e[p].w=a[i][j];
			e[p].t=i;
			sm[i]+=e[p].w;
		}
		if(c[i]!=0) flg2=0;
		if(!flg2) flg=0;
	}
	std::sort(e+1,e+tot+1);
	if(flg)
	{
		ans=calc((1ull<<(k+1))-1);
	}
	else if(m>100000&&k>5)
	{
		nw=1;
		ans=calc(1);
		for(ull i(1);i<=k;++i)
		{
			ull id=0;
			for(ull j(1);j<=k;++j)
			{
				if((nw>>j)&1) continue;
				ull t=calc(nw|(1ull<<j));
				if(t<ans) ans=t,id=j;
			}
			if(!id) break;
			nw|=1ull<<id;
		}
	}
	else
	{
		for(ull w(1);w<1ull<<(k+1);w+=2)
		{
			ull t=calc(w);
			if(t<ans) ans=t;
		}
	}
	printf("%llu",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
// 64pts
// 2^k m + mlogm
// da gai bi jiao du li?
// fen kai suan ji xing
