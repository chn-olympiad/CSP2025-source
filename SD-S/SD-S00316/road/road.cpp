#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+20,M=1e6+10,K=15;
const int INF=0x3f3f3f3f;
struct edge{int u,v,w;}E[M],T[N];
bool cmp(edge A,edge B){return A.w<B.w;}
int n,m,k,a[K][N];
int f[N];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
ll res;
bool flag[K];
inline void read(int &x)
{
	x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);read(m);read(k);
	for(register int i=1;i<=m;++i)
		read(E[i].u),read(E[i].v),read(E[i].w);
	for(register int i=1;i<=n;++i) f[i]=i;
	int cnt=0,s=0;
	sort(E+1,E+m+1,cmp);
	for(register int i=1;i<=m;++i)
	{
		register int u=E[i].u,v=E[i].v,w=E[i].w;
		if(find(u)==find(v)) continue;
		++s;
		f[find(u)]=find(v);
		T[++cnt]=E[i];
		res+=w;
		if(s==n-1) break;
	}
	for(register int i=0;i^k;++i)
	{
		read(a[i][0]);
		for(register int j=1;j<=n;++j) read(a[i][j]);
	}
	for(register int zt=1;zt^(1<<k);++zt)
	{
		ll ans=0;
		for(register int j=0;j^k;++j)
			if(zt>>j&1) ans+=a[j][0];
		for(register int i=1;i^n;++i) E[i]=T[i];
		for(register int i=1;i<=n+10;++i) f[i]=i;
		int cnt=n-1,node=n;
		for(register int j=0;j^k;++j)
			if(zt>>j&1)
			{
				node++;
				for(int i=1;i<=n;++i)
					E[++cnt]={i,node,a[j][i]};
			}
		sort(E+1,E+cnt+1,cmp);
		int sum=0;cnt++;
		for(register int i=1;i^cnt;++i)
		{
			int u=E[i].u,v=E[i].v,w=E[i].w;
			if(find(u)==find(v)) continue;
			++sum;
			f[find(u)]=find(v);
			ans+=w;
			if(sum==n+node-1) break;
		}
		res=min(res,ans);
	}
	printf("%lld\n",res);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
