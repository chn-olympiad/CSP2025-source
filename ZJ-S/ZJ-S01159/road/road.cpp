#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e4 + 100,M = 1e7 + 10,K = 12;
LL c[N],a[K][N];
struct node
{
	int x,y;
	LL z;
	bool operator < (const node &w) const
	{
		return z < w.z;
	}
}ed[M];
set<node> e,es;
int p[N],sz[N];
int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	bool suba = 0,subs;
	LL res = 0,ans = 1e18;
	cin>>n>>m>>k;
	for(int i = 1; i <= n + k; i ++) p[i] = i,sz[i] = 1;
	for(int i = 1; i <= m; i ++)
	{
		int x,y;
		LL z;
		scanf("%d%d%lld",&x,&y,&z);
		e.insert({x,y,z});
	}
	for(int i = 1; i <= k; i ++)
	{
		scanf("%lld",&c[i]);
		suba |= c[i];
		subs = 1;
		for(int j = 1; j <= n; j ++)
		{
			scanf("%lld",&a[i][j]);
			if(!a[i][j])subs = 0;
		}
		suba |= subs;
	}
	if(!suba)
	{
		res = 0;
		for(int i = 1; i <= k; i ++)
		{
			int pp = 0;
			for(int j = 1; j <= n; j ++)
				if(!a[i][j])
				{
					pp = j;
					break;
				}
			for(int j = 1; j <= n; j ++)
				if(j != pp) e.insert({pp,j,a[i][j]});
		}
	}
	for(auto i : e)
	{
		int x = find(i.x),y = find(i.y);
		if(x != y)
		{
			if(sz[x] > sz[y]) swap(x,y);
			p[x] = y;
			sz[y] += sz[x];
			res += i.z;
		}
	}
	ans = res;
	if(!suba || !k)
	{
		cout<<res<<endl;
		return 0;
	}
	for(int t = 1; t < (1 << k); t ++)
	{
		es = e;
		res = 0;
		for(int i = 1; i <= k; i ++)
			if((t >> (i - 1)) & 1)
			{
				res += c[i];
				for(int j = 1; j <= n; j ++)
					for(int x = j + 1; x <= n; x ++)
						if(a[i][x] + a[i][j] + c[i] < ans) es.insert({j,x,a[i][x] + a[i][j]});
			}
		for(int i = 1; i <= n + k; i ++) p[i] = i,sz[i] = 1;
		for(auto i : es)
		{
			int x = find(i.x),y = find(i.y);
			if(x != y)
			{
				if(sz[x] > sz[y]) swap(x,y);
				p[x] = y;
				sz[y] += sz[x];
				res += i.z;
			}
		}
		ans = min(ans,res);
	}
	cout<<min(ans,res)<<endl;
	return 0;
}
//16+32+8=56
