#include<bits/stdc++.h>
using namespace std;
long long n, m, k;
struct node
{
	long long x, y, v;
	bool friend operator  < (node a, node b)
	{
		return a.v > b.v;
	}
};
priority_queue<node>e;
long long fa[10005];
long long dis[11][10005];
long long c[11];
bool cmp(node x, node y)
{
	return x.v < y.v;
}
long long get(long long x)
{
	if(fa[x] == x) return fa[x];
	else return fa[x] = get(fa[x]);
}
void merge(long long x, long long y)
{
	fa[get(x)] = get(y);
}
long long u, v ,w;
void work1()
{
	long long cnt = 0;
	long long len = e.size();
	long long ans = 0;
	while(e.size())
	{
		node tmp = e.top();
		long long x = tmp.x;
		long long y = tmp.y;
		long long v = tmp.v;
		if(get(x) != get(y))
		{ 
			cnt++;
			merge(x, y);
			ans += v;
		}
		e.pop();
	}	
	if(cnt == n - 1)
	{
		cout << ans << endl;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(long long i = 1; i <= n; i++)
	{
		fa[i] = i;
	}
	while(m--)
	{
		cin >> u >> v >> w;
		e.push({u, v, w});
	}
	if(k == 0)
	{
		work1();
		return 0;
	}
	long long flag = 1;
	for(long long i = 1; i <= k; i++)
	{
		cin >> c[i];
		for(long long j = 1; j <= n; j++)
		{
			cin >> dis[i][j];
		} 
	}
		for(long long i = 1; i <= k; i++)
		{
			for(long long j = 1; j <= n; j++)
			{
				for(long long k = 1; k <= n; k++)
				{
					if(k != j)
					{
						e.push({j, k, dis[i][j] + dis[i][k] + c[i]});
					}
				}
			}
		}
		work1();

	
	return 0;
}
