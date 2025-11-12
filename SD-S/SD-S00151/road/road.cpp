#include<bits/stdc++.h>
using namespace std;
const int N=1e4+15,M=2e6+5;
int n,m,k,F[N],ct[N];
long long ans;
struct Edge{
	int a,b,c;
}ed[M];
bool cmp(Edge x,Edge y) { return x.c<y.c; }
int Find(int x)
{
	if (F[x]==x) return x;
	return F[x]=Find(F[x]);
}
void Link(int x,int y) { F[Find(y)]=Find(x); }
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j,a,b,c;
	scanf("%d%d%d",&n,&m,&k);
	for (i=1;i<=n;i++) F[i]=i;
	for (i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		ed[i]={a,b,c};
	}
	for (c=1;c<=k;c++)
	{
		scanf("%d",&a);
		for (i=1;i<=n;i++)
		{
			scanf("%d",&ct[i]);
			if (ct[i]==0) a=i;
		}
		for (i=1;i<=n;i++)
		{
			if (a==i) continue;
			ed[++m]={a,i,ct[i]};
		}
	}
	sort(ed+1,ed+m+1,cmp);
	for (i=1;i<=m;i++)
	{
		a=ed[i].a;b=ed[i].b;c=ed[i].c;
		if (Find(a)==Find(b)) continue;
		Link(a,b);
		ans+=c;
	}
	printf("%lld\n",ans);
	return 0;
}

