#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e4 + 10;
const int M = 1e6 + 10;

int n , m , k;
int ans = 1e18;

struct Node
{
	int from;
	int to;
	int var;
};

Node edge[M << 1];
int tot;

Node use[M << 1];
int tuse;

inline void add(int x , int y , int w)
{
	edge[++tot].from = x;
	edge[tot].to = y;
	edge[tot].var = w;
	return;
}

inline void adduse(int x , int y , int w)
{
	use[++tuse].from = x;
	use[tuse].to = y;
	use[tuse].var = w;
	return;
}

int fa[N];

int checkfa(int x)
{
	return (fa[x] == x ? x : fa[x] = checkfa(fa[x]));
}

inline void init(int n)
{
	for(int i = 1 ; i <= n ; i++)
	{
		fa[i] = i;
	}
	return;
}

bool cmp(Node a , Node b)
{
	return a.var < b.var;
}

int c[20];
int ka[15][N];

int opt[20];

int check()
{
	int x , y , z;
	init(n + k);
	tuse = tot;
	for(int i = 1 ; i <= tot ; i++)
	{
		use[i] = edge[i];
	}
	int re = 0;
	for(int i = 1 ; i <= k ; i++)
	{
		if(opt[i] == 1)
		{
			re += ka[i][0];
			for(int j = 1 ; j <= n ; j++)
			{
				adduse(j , n + i , ka[i][j]);
			}
		}
	}
	sort(use + 1 , use + tuse + 1 , cmp);
	for(int i = 1 ; i <= tuse ; i++)
	{
		x = checkfa(use[i].from);
		y = checkfa(use[i].to);
		z = use[i].var;
		if(x != y)
		{
			fa[x] = y;
			re += z;
		}
	}
	return re;
}

void dfs(int x)
{
	if(x == k + 1)
	{
		ans = min(ans , check());
		return;
	}
	opt[x] = 0;
	dfs(x + 1);
	opt[x] = 1;
	dfs(x + 1);
	return;
}

signed main()
{
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	scanf("%lld %lld %lld" , &n , &m , &k);
	int x , y , z;
	for(int i = 1 ; i <= m ; i++)
	{
		scanf("%lld %lld %lld" , &x , &y , &z);
		add(x , y , z);
	}
	init(n);
	if(k == 0)//1-4
	{
		sort(edge + 1 , edge + tot + 1 , cmp);
		int ans = 0;
		for(int i = 1 ; i <= tot ; i++)
		{
			x = checkfa(edge[i].from);
			y = checkfa(edge[i].to);
			z = edge[i].var;
			if(x != y)
			{
				fa[x] = y;
				ans += z;
			}
		}
		printf("%lld" , ans);
		return 0;
	}
	int cnt = 0;
	for(int i = 1 ; i <= k ; i++)
	{
		for(int j = 0 ; j <= n ; j++)
		{
			scanf("%lld" , &ka[i][j]);
			if(ka[i][j] == 0)
			{
				c[i] = j;
			}
		}
		cnt += ka[i][0];
	}
	if(cnt == 0)//A
	{
		for(int i = 1 ; i <= k ; i++)
		{
			for(int j = 1 ; j <= n ; j++)
			{
				if(j != c[i])
				{
					add(j , c[i] , ka[i][j]);
				}
			}
		}
		sort(edge + 1 , edge + tot + 1 , cmp);
		int ans = 0;
		for(int i = 1 ; i <= tot ; i++)
		{
			x = checkfa(edge[i].from);
			y = checkfa(edge[i].to);
			z = edge[i].var;
			if(x != y)
			{
				fa[x] = y;
				ans += z;
			}
		}
		printf("%lld" , ans);
		return 0;
	}
	else
	{
		dfs(1);
		printf("%lld" , ans);
	}

	return 0;
}
