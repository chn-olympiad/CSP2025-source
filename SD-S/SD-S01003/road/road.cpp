#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 5,M = 1e6 + 5;
int n,m,k,fa[N];
struct edge
{
	int u,v;
	ll len;
}e[M * 20];
ll c[11],a[11][N],ans,to[1005][1005];
bool cmp(edge xx,edge yy)
{
	return xx.len < yy.len;
}
int fd(int x)
{
	if(x == fa[x])
	{
		return x;
	}
	return fa[x] = fd(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i++)
	{
		scanf("%d %d %lld",&e[i].u,&e[i].v,&e[i].len);
	}
	for(int i = 1;i <= k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j = 1;j <= n;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	for(int i = 1;i <= n;i++)
	{
		fa[i] = i;
	}
	if(k == 0)
	{
		sort(e + 1,e + 1 + m,cmp);
		int cnt = 0;
		for(int i = 1;i <= m;i++)
		{
			int fx = fd(e[i].u),fy = fd(e[i].v);
			if(fx != fy)
			{
				cnt++;
				ans += e[i].len;
				fa[fx] = fy;
			}
			if(cnt == n - 1)
			{
				break;
			}
		}
		cout<<ans;
	}
	else
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				to[i][j] = 1e18;
			}
		}
		for(int i = 1;i <= m;i++)
		{
			if(e[i].u > e[i].v)
			{
				swap(e[i].u,e[i].v);
			}
			to[e[i].u][e[i].v] = min(e[i].len,to[e[i].u][e[i].v]);
		}
		for(int i = 1;i <= k;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				for(int kk = j + 1;kk <= n;kk++)
				{
					to[j][kk] = min(to[j][kk],a[i][j] + a[i][kk] + c[i]);
				}
			}
		}
		m = 0;
		for(int i = 1;i <= n;i++)
		{
			for(int j = i + 1;j <= n;j++)
			{
				if(to[i][j] == 1e18)
				{
					continue;
				}
				e[++m] = {i,j,to[i][j]};
			}
		}
		sort(e + 1,e + 1 + m,cmp);
		int cnt = 0;
		for(int i = 1;i <= m;i++)
		{
			int fx = fd(e[i].u),fy = fd(e[i].v);
			if(fx != fy)
			{
				cnt++;
				ans += e[i].len;
				fa[fx] = fy;
			}
			if(cnt == n - 1)
			{
				break;
			}
		}
		cout<<ans;
	}
	return 0;
}
