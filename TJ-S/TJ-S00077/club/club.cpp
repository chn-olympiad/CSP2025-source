#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 10;

struct Node
{
	int id;
	int v;
	int to;
};

int sa[N];
int sb[N];
int sc[N];
int num[5];
bool flag[N];
Node v[N << 1];
int tot;
int ans;

int dp[2][110][110][110];

inline void init()
{
	tot = 0;
	memset(num , 0 , sizeof(num));
	memset(flag , false , sizeof(flag));
	ans = 0;
	return;
}

bool cmp(Node a , Node b)
{
	return a.v > b.v;
}

void dfs(int x , int a , int b , int c , int n , int t)
{
	if(x == n + 1)
	{
		ans = max(ans , t);
		return;
	}
	if(a < (n >> 1))
	{
		dfs(x + 1 , a + 1 , b , c , n , t + sa[x]);
	}
	if(b < (n >> 1))
	{
		dfs(x + 1 , a , b + 1 , c , n , t + sb[x]);
	}
	if(c < (n >> 1))
	{
		dfs(x + 1 , a , b , c + 1 , n , t + sc[x]);
	}
}

int opt[5];

void dfs(int x , int use , int p , int n)
{
	if(x == 4)
	{
		if(opt[1] < (n >> 1))
		{
			dp[p & 1][opt[1] + 1][opt[2]][opt[3]] = min(dp[p & 1][opt[1] + 1][opt[2]][opt[3]] , dp[(p & 1) ^ 1][opt[1]][opt[2]][opt[3]] - sa[p]);
			ans = min(ans , dp[p & 1][opt[1] + 1][opt[2]][opt[3]]);
		}
		if(opt[2] < (n >> 1))
		{
			dp[p & 1][opt[1]][opt[2] + 1][opt[3]] = min(dp[p & 1][opt[1]][opt[2] + 1][opt[3]] , dp[(p & 1) ^ 1][opt[1]][opt[2]][opt[3]] - sb[p]);
			ans = min(ans ,  dp[p & 1][opt[1]][opt[2] + 1][opt[3]]);
		}
		if(opt[3] < (n >> 1))
		{
			dp[p & 1][opt[1]][opt[2]][opt[3] + 1] = min(dp[p & 1][opt[1]][opt[2]][opt[3] + 1] , dp[(p & 1) ^ 1][opt[1]][opt[2]][opt[3]] - sc[p]);
			ans = min(ans , dp[p & 1][opt[1]][opt[2]][opt[3] + 1]);
		}
		return;
	}
	if(x == 3)
	{
		if(use > (n >> 1))
		{
			return;
		}
		opt[3] = use;
		dfs(x + 1 , 0 , p , n);
		return;
	}
	for(int i = 0 ; i <= min((n >> 1) , use) ; i++)
	{
		opt[x] = i;
		dfs(x + 1 , use - i , p , n);
	}
	return;
}

signed main()
{
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	
	int T;
	int cnt;
	scanf("%lld" , &T);
	int n;
	while(T--)
	{
		init();
		cnt = 0;
		scanf("%lld" , &n);
		for(int i = 1 ; i <= n ; i++)
		{
			scanf("%lld %lld %lld" , &sa[i] , &sb[i] , &sc[i]);
			cnt += sc[i];
			ans += sa[i];
		}
		if(n <= 10)
		{
			ans = 0;
			dfs(1 , 0 , 0 , 0 , n , 0);
			printf("%lld\n" , ans);
			continue;
		}
		if(cnt == 0)
		{
			num[1] = n;
			for(int i = 1 ; i <= n ; i++)
			{
				v[++tot].id = i;
				v[tot].v = sb[i] - sa[i];
				v[tot].to = 2;
				v[++tot].id = i;
				v[tot].v = sc[i] - sa[i];
				v[tot].to = 3;
			}
			sort(v + 1 , v + tot + 1 , cmp);
			for(int i = 1 ; i <= tot ; i++)
			{
				if(v[i].v <= 0 && num[1] <= (n >> 1))
				{
					break;
				}
				if(flag[v[i].id] || num[v[i].to] >= (n >> 1))
				{
					continue;
				}
				flag[v[i].id] = true;
				num[v[i].to]++;
				num[1]--;
				ans += v[i].v;
			}
			printf("%lld\n" , ans);
			continue;
		}
		else if(n <= 200)
		{
			ans = 1e18 + 10;
			dp[0][0][0][0] = 0;
			for(int i = 1 ; i <= n ; i++)
			{
				memset(dp[i & 1] , 0 , sizeof(dp[i & 1]));
				dfs(1 , i - 1 , i , n);
			}
			printf("%lld\n" , -ans);
		}
	}

	return 0;
}

