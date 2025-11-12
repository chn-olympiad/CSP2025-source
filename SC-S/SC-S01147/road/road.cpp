#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define int long long

using namespace std;
const int N = 2e4+10 ,M = 1e6+10 ,E = 1e6+1e5+20 ,K = 20;

struct Node{
	int u,v,w;
}e[E];

int n,f[N],m,k,c[K],idx,ans;
int minest[K],q[K];//minest[i]表示连接i乡镇中，最短的边；q[i]表示与i乡镇相连的边数 

int find(int x)
{
	if(x == f[x])	return x;
	return f[x] = find(f[x]);
}

bool cmp(Node x,Node y)
{
	return x.w < y.w;
}

struct Z{
	int u,v,w;
};

queue<Z> r[K];

void kustral()
{
	int t = 1,p = 0;
	while(p < (n-1) and t <= idx)
	{
		int u = find(e[t].u), v = find(e[t].v);
		if(u > n)
		{
			r[u-n].push({u,v,e[t].w});
			t++;
			continue ;
		}//将与乡镇相连的边先放一会儿 
		for(int i = 1; i <= k; i++)
		{
			if(!r[i].empty() and (r[i].front().w + c[r[i].front().u - n]) < e[t].w)
			{
				f[r[i].front().u]=find(r[i].front().v);
				ans = ans + r[i].front().w + c[r[i].front().u - n];
				r[i].pop();
				q[i] ++;
				while(!r[i].empty())
				{
					if(find(r[i].front().u)==find(r[i].front().v))
					{
						r[i].pop();
						continue ;
					}
					p ++;
					q[i] ++;
					f[find(r[i].front().u)] = find(r[i].front().v);
					ans = ans + r[i].front().w;
					r[i].pop();
				}
			}
			if(p >= (n-1))	return ;
		}
		if(u == v)	t++;
		else
		{
			if(e[t].u > n)	q[e[t].u - n] ++;
			f[u] = v;
			ans = ans + e[t].w;
			p++,t++;
		}
	}
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i = 1; i <= (n+k); i++)	f[i] = i;
	for(int i = 1; i <= m; i++)
	{
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
		++idx;
	}
	for(int i = 1; i <= k; i++)
	{
		minest[i] = 2e9+10;
		scanf("%lld",&c[i]);
		for(int j = 1; j <= n; j++)
		{
			e[++idx].u = (n + i) ,e[idx].v = j;
			scanf("%lld",&e[idx].w);
			minest[i]=min( minest[i] , e[idx].w );
		}
	}
	sort(e + 1 ,e + idx + 1 ,cmp);
	kustral();
	for(int i = 1; i <= k; i++)
	{
		if(q[i] == 1)	ans = ans - minest[i] - c[i];
	}
	cout<<ans<<"\n";
	return 0;
}