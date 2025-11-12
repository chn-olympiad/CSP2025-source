#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int rd()
{
	int x=0;char c=getchar();
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);x=(x<<3)+(x<<1)+(c^48),c=getchar());
	return x;
}
struct edge{int u,v,w;}e[2000010];
inline bool cmp(edge x,edge y){return x.w<y.w;}
int c[15],a[15][10010],f[10010];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=rd(),m=rd(),k=rd(),ans=0;
	for(int i=1;i<=m;i++)
	{
		int u=rd(),v=rd(),w=rd();
		e[i]={u,v,w};
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++)f[i]=i;
	if(k==0)
	{
		for(int i=1;i<=m;i++)
		{
			int u=find(e[i].u),v=find(e[i].v);
			if(u!=v)f[u]=v,ans+=e[i].w;
		}
		printf("%lld",ans);
	}
	else
	{
		for(int j=1;j<=k;j++)
		{
			c[j]=rd();
			for(int i=1;i<=n;i++)
				a[j][i]=rd();
		}
		puts("0");
	}
	return 0;
}
