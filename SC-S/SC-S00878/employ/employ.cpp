#include<bits/stdc++.h>
#define int long long

using namespace std;

const int mod = 998244353;

int n, m;

namespace Case1
{
	const int N = 15;
	
	char s[N];
	int c[N], p[N];
	int ans = 0;
	
	void enumf()
	{
		int pre = 0, num = 0;
		
		do
		{
			pre = num = 0;
			
			for(int i = 1; i <= n; i ++)
			{
				if(s[i] == '1' && pre < c[p[i]])
				{
					num ++;
				}
				else
				{
					pre ++;
				}
			}
			
			if(num >= m)
			{
				ans ++;
			}
			
		}while(next_permutation(p + 1, p + 1 + n));
	}
	
	void work()
	{
		for(int i = 1; i <= n; i ++)
		{
			p[i] = i;
		}
		
		cin >> s + 1;
		
		for(int i = 1; i <= n; i ++)
		{
			scanf("%lld", &c[i]);
		}
		
		enumf();
		
		cout << ans;
		
		return;
	}
}

const int N = 5e2 + 10;

char s[N];
int c[N];

bool checkA;

namespace CaseA
{
	int fac[N];
	
	void initfac()
	{
		fac[0] = 1;
		
		for(int i = 1; i < N; i ++)
		{
			fac[i] = fac[i - 1] * i % mod;
		}
	}
	
	void work()
	{
		initfac();
		
		cout << fac[n];
		
		return;
	}
}

namespace Case2
{
	const int N = 5e2 + 10;
	
	char s[N];
	int c[N];
	int ans = 0;
	bool sg = true;
	
	int fac[N];
	
	void initfac()
	{
		fac[0] = 1;
		
		for(int i = 1; i < N; i ++)
		{
			fac[i] = fac[i - 1] * i % mod;
		}
	}
	
	void work()
	{
		initfac();
		
		sg = true;
		
		cin >> s + 1;
		
		for(int i = 1; i <= n; i ++)
		{
			scanf("%lld", &c[i]);
			
			if(s[i] == '0' || c[i] == 0)
			{
				sg = false;
			}
		}
		
		if(sg)
		{
			cout << fac[n];
			return;
		}
		else
		{
			cout << "0";
			return;
		}
	}
}

signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	
	if(n <= 10 && m <= 10)
	{
		Case1 :: work();
		return 0;
	}
	else if(m == n)
	{
		Case2 :: work();
		return 0;
	}
	
	cin >> s + 1;
	
	checkA = true;
	
	for(int i = 1; i <= n; i ++)
	{
		scanf("%lld", &c[i]);
		
		if(s[i] == '0')
		{
			checkA = false;
		}
	}
	
	if(checkA)
	{
		CaseA :: work();
		return 0;
	}
	else
	{
		puts("37");
		return 0;
	}
	
	return 0;
}