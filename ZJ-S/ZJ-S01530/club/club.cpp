#include <bits/stdc++.h>
using namespace std;
struct peo
{
	int v,pos;
}f[3],a[100005],b[100005],c[100005];
int t,n,sum[3],lim,maxn,minn,p,q,m;
long long ans;
bool vis[100005];
bool cmp(peo a,peo b)
{
	if (a.v != b.v)
	{
		return a.v > b.v;
	}
	return a.pos < b.pos;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--)
	{
		memset(vis,false,sizeof(vis));
		for (int i = 0;i < 3;i++)
			sum[i] = 1;
		ans = 0;
		cin >> n;
		lim = n / 2;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i].v >> b[i].v >> c[i].v;
			a[i].pos = i;
			b[i].pos = i;
			c[i].pos = i;
		}
		sort (a + 1,a + n + 1,cmp);
		sort (b + 1,b + n + 1,cmp);
		sort (c + 1,c + n + 1,cmp);
		if (n == 2)
		{
			if (a[1].pos == b[1].pos)
			{
				if (a[1].pos == c[1].pos)
				{
					cout << max(a[1].v + b[2].v,max(a[1].v + c[2].v,max(a[2].v + b[1].v,max(a[2].v + c[1].v,max(b[1].v + c[2].v,c[1].v + b[2].v)))));
					continue;
				}
					
			}
		}
		/*
		for (int i = 1;i <= n;i++)
			cout << a[i].v;
		for (int i = 1;i <= n;i++)
			cout << b[i].v;
		for (int i = 1;i <= n;i++)
			cout << c[i].v;*/
		for (int i = 1;i <= n;i++)
		{
			while (vis[a[sum[0]].pos])
				sum[0]++;
			f[0] = a[sum[0]];
			while (vis[b[sum[1]].pos])
				sum[1]++;
			f[1] = b[sum[1]];
			while (vis[c[sum[2]].pos])
				sum[2]++;
			f[2] = c[sum[2]];
			sort (f,f + 3,cmp);
			if (sum[f[0].pos] > lim)
			{
				ans += f[1].v;
				vis[f[1].pos] = true;
			}
			else
			{
				ans += f[0].v;
				vis[f[0].pos] = true;
			}
			//cout << ans;
			
		}
		cout << ans << "\n";
	}
	return 0;
}