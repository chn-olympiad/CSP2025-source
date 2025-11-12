#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long u,v,w;
}a[2000001];
long long n,m,k,c[11],kk[11][10001];
bool cmp(node a,node b)
{
	return a.w < b.w;
}
int fa[200001];
int find(int x)
{
	if(fa[x] == x)
	{
		return x;
	}
	return fa[x] = find(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
	{
		cin >> a[i].u >> a[i].v >> a[i].w;
	}

	bool flag = true;
	for(int i = 1;i <= k;i++)
	{
		cin >> c[i];
		if(c[i])
		{
			flag = false;
		}
		for(int j = 1;j <= n;j++)
		{
			cin >> kk[i][j];
		}
	}
	if(k == 0)
	{
		for(int i = 1;i <= n;i++)
		{
			fa[i] = i;
		}
		sort(a+1,a+m+1,cmp);
		long long ans = 0;
		for(int i = 1;i <= m;i++)
		{
			int tx = find(a[i].u);
			int ty = find(a[i].v);
			if(tx != ty)
			{
				ans += a[i].w;
				fa[tx] = ty;
			}
		}
		cout << ans;
	}
	else if(flag)
	{
		int oppo = m,vivo = n;
		for(int i = 1;i <= n;i++)
		{
			fa[i] = i;
		}
		for(int i = 1;i <= k;i++)
		{
			fa[++vivo] = vivo;
			for(int j = 1;j <= n;j++)
			{
				a[++oppo].u = vivo;
				a[oppo].v = j;
				a[oppo].w = kk[i][j];
			}
		}
		m = oppo;
		n = vivo;
		sort(a+1,a+m+1,cmp);
		long long ans = 0;
		for(int i = 1;i <= m;i++)
		{
			int tx = find(a[i].u);
			int ty = find(a[i].v);
			if(tx != ty)
			{
				ans += a[i].w;
				fa[tx] = ty;
			}
		}
		cout << ans;
	}
	return 0;
 } 