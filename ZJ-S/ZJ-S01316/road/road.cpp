#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
ll ans=0;
int n, m, k;
int c[15], cw[15][10500];
int fa[10500];

struct node
{
	int u, v, w;
}G[1500010], H[1500010];

bool cmp(node x, node y)
{
	return x.w<y.w;
}

int find(int x)
{
	if (x==fa[x]) return x;
	return x=find(fa[x]);
}

ll func(int num)
{
	ll sum=0;
	int t=0;
	for (int i=1;i<=m;i++)
	{
		G[i].u=H[i].u;
		G[i].v=H[i].v;
		G[i].w=H[i].w;
	}
	int len=m;
	while (num)
	{
		t++;
		if (num&1)
		{
			sum+=c[t];
			for (int i=1;i<=n;i++)
			{
				len++;
				G[len].u=i;
				G[len].v=n+t;
				G[len].w=cw[t][i];
			}
		}
		num<<=1;
	}
	sort(G+1, G+len+1, cmp);
	for (int i=1;i<=len;i++)
		fa[i]=i;
	for (int i=1;i<=len;i++)
	{
		node p=G[i];
		int fx=find(p.u), fy=find(p.v);
		if (fx!=fy)
		{
			fa[fx]=fy;
			sum+=p.w;
		}
	}
	return sum;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d", &H[i].u, &H[i].v, &H[i].w);
	}
	for (int i=1;i<=k;i++)
	{
		scanf("%d", &c[i]);
		for (int j=1,w;j<=n;j++)
		{
			scanf("%d", &w);
			cw[i][j]=w;
		}
	}
	ans=func(0);
	
	for (int i=1;i<=(1<<k)-1;i++)
		ans=min(ans, func(i));
	printf("%lld\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
