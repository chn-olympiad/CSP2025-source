#include <bits/stdc++.h>
using namespace std;
#define N 200010
#define M 4000010
#define ll long long
int n,m,k,cnt;
int fa[N];
ll ans,sum,a[N];
struct Edge
{
	int x,y;
	ll z;
}e[M],f[M];

int cmp(Edge t1,Edge t2)
{
	return t1.z<t2.z;
}
void init(int x)
{
	for (int i=0;i<=x;i++) fa[i]=i; 
}
int Find(int x)
{
	if (fa[x]==x) return x;
	return fa[x]=Find(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int x,y;
	ll z,c;
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%lld",&x,&y,&z);
		e[i].x=x;
		e[i].y=y;
		e[i].z=z;cnt++;
	}
	for (int i=1;i<=k;i++)
	{
		sum=0;
		scanf("%lld",&c);
		if (c==0)
		{
			for (int j=1;j<=n;j++)
			{
				scanf("%lld",&z);
				a[j]=z;
				if (z==0) x=j;
			}
			for (int j=1;j<=n;j++)
			{
				if (x==j) continue;
				e[++cnt].x=x;
				e[cnt].y=j;
				e[cnt].z=a[j];
			}
		}
	}
	init(n+10);
	sort(e+1,e+cnt+1,cmp);
	for (int i=1;i<=cnt;i++)
	{
		int rx=Find(e[i].x);
		int ry=Find(e[i].y);
		if (rx==ry) continue;
		fa[rx]=ry;
		ans+=e[i].z;
	}
	printf("%lld\n",ans);
	return 0;
}

