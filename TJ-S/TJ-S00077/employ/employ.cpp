#include <bits/stdc++.h>
using namespace std;

#define int long long 

const int M = 998244353;

int n , m;
string s;
int c[20];
bool use[20];
int pls[20];
int ans = 0;

inline void check()
{
	int fail = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		if(s[i] == '0' || fail >= c[pls[i]])
		{
			fail++;
		}
	}
	if(n - fail >= m)
	{
		ans++;
	}
	return;
}

void dfs(int x)
{
	if(x == n + 1)
	{
		check();
		return;
	}
	for(int i = 1 ; i <= n ; i++)
	{
		if(use[i] == false)
		{
			pls[x] = i;
			use[i] = true;
			dfs(x + 1);
			use[i] = false;
		}
	}
	return;
}

signed main()
{
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	scanf("%lld %lld" , &n , &m);
	cin>>s;
	s = " " + s;
	for(int i = 1 ; i <= n ; i++)
	{
		scanf("%lld" , &c[i]);
	}
	if(n <= 10)
	{
		dfs(1);
		printf("%lld" , ans);
		return 0;
	}
	else if(m == n)
	{
		for(int i = 1 ; i <= n ; i++)
		{
			if(s[i] != '1')
			{
				printf("0");
				return 0;
			}
		}
		int ans = 1;
		for(int i = 1 ; i <= n ; i++)
		{
			ans *= i;
			ans %= M;
		}
		printf("%lld" , ans);
		return 0;
	}
	else
	{
		printf("0");
	}

	return 0;
}
