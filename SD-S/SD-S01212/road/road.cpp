#include <bits/stdc++.h>
using namespace std;
int f[10005];
struct edge
{
	int u,v;
	long long w;
}e[1000005];
int cmp(edge x,edge y)
{
	return x.w < y.w;
}
int find(int x)
{
	if(x == f[x])
	{
		return x;
	}
	return f[x] = find(f[x]);
}
int ck(int u,int v)
{
	return find(u) == find(v);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= m;i++)
	{
		scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i = 1;i <= n;i++)
	{
		f[i] = i;
	}
	sort(e + 1,e + m + 1,cmp);
	if(k == 0)
	{
		int cnt = 0;
		long long ans = 0;
		for(int i = 1;i <= m;i++)
		{
			int u = e[i].u,v = e[i].v;
			if(ck(u,v) == 0)
			{
				f[find(u)] = find(v);
				cnt++;
				ans += e[i].w;
			}
			if(cnt == n - 1)
			{
				break;
			}
		}
		printf("%lld",ans);
		return 0;
	}
	for(int i = 1;i <= k;i++)
	{
		long long c;
		scanf("%lld",&c);
		queue<int> q;
		for(int j = 1;j <= n;j++)
		{
			scanf("%lld",&c);
			if(c == 0)
			{
				q.push(i);
			}
		}
		if(!q.empty())
		{
			int u = q.front();
			q.pop();
			while(!q.empty())
			{
				int v = q.front();
				q.pop();
				f[find(v)] = find(u);
			}
		}
	}
	long long ans = 0;
	for(int i = 1;i <= m;i++)
	{
		int u = e[i].u,v = e[i].v;
		if(ck(u,v) == 0)
		{
			f[find(u)] = find(v);
			ans += e[i].w;
		}
	}
	printf("%lld",ans);
	return 0;
}
