#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
struct point{
	int x,y,z;
}a[1000009];
int ty[19] = {0};
int d[19][10009] = {0};
int fa[10009] = {0};
bool cmp(point u,point v)
{
	return u.z<v.z;
}
int f(int x)
{
	int g = x;
	while(x!=fa[x])
	{
		x=fa[x];
	}
	while(g!=fa[g])
	{
		fa[g]=x;
		g=fa[g];
	}
	return x;
}
signed main()
{
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	scanf("%d%d%d", &n, &m, &k);
	int yuy = n;
	for(int i = 1; i<=m; ++i)
	{
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
	}
	for(int i = 1; i<=k; ++i)
	{
		scanf("%d", &ty[i]);
		for(int j = 1; j<=n; ++j)
		{
			scanf("%d", &d[i][j]);
		}
	}
	for(int i = 1; i<=k; ++i)
	{
		for(int j = i+1; j<=k; ++j)
		{
			if(ty[j]<ty[i])
			{
				swap(ty[i],ty[j]);
				for(int oi = 1; oi<=n; ++oi) swap(d[i][oi],d[j][oi]);
			}
		}
	}
	for(int i = 1; i<=n; ++i)
	{
		fa[i]=i;
	}
	sort(a+1,a+m+1,cmp);
	int s = 0;
	for(int i = 1; i<=m; ++i)
	{
		if(f(a[i].x)!=f(a[i].y))
		{
			fa[f(a[i].y)]=f(a[i].x);
			s+=a[i].z;
		}
	}
	int ui = 0;
	for(int io = 1; io<=k; ++io)
	{
		memset(fa,0,sizeof(fa));
		for(int i = 1; i<=n+1; ++i) fa[i]=i;
		for(int i = 1; i<=yuy; ++i)
		{
			int yu = m+1;
			for(int j = 1; j<=m; ++j)
			{
				if(d[io][i]<=a[j].z)
				{
					yu=j;
					break;
				}
			}
			for(int j = m; j>=yu; --j)
			{
				a[j+1].x=a[j].x;
				a[j+1].y=a[j].y;
				a[j+1].z=a[j].z;
			}
			a[yu].x=i;
			a[yu].y=n+1;
			a[yu].z=d[io][i];
			m++;
		}
		/*for(int i = 1; i<=m; ++i)
		{
			printf("%d %d %d\n", a[i].x, a[i].y, a[i].z);
		}
		printf("\n");*/
		n++;
		ui+=ty[io];
		int s1 = ui;
		for(int i = 1; i<=m; ++i)
		{
			if(f(a[i].x)!=f(a[i].y))
			{
				/*printf("%d %d %d\n", a[i].x, a[i].y, a[i].z);*/
				fa[f(a[i].y)]=f(a[i].x);
				s1+=a[i].z;
			}
		}
		s=min(s,s1);
		/*printf("%d\n", s1);*/
	}
	printf("%lld\n", s);
	return 0;
}
/*4 4 2
1 4 6
2 4 5
2 3 7
3 4 4
1 1 8 2 4
100 1 3 2 4*/
