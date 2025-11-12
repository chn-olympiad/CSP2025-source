#include<bits/stdc++.h>
using namespace std;
const int MX = 5e2;
const int N = (1 << 18);
const int M = 18;
const long long mod = 998244353ll;
char s[MX + 10];
int a[MX + 10];
int c[MX + 10];
int p[MX + 10];
long long dp[M + 10][N + 10];
int st[MX + 10];
int cntp(int x)
{
	int cnt = 0;
	while(x)
	{
		if(x & 1)
			cnt++;
		x >>= 1;
	}
	return cnt;
}
bool cmp(const int &x,const int &y)
{
	return cntp(x) < cntp(y);
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,cnt,cal,flg = 1;
	long long ans = 0ll;
	scanf("%d%d%s",&n,&m,s);
	for(int i = 0;i <= n - 1;++i)
	{
		if(s[i] == '1')
			a[i + 1] = 1;
		else
			flg = 0;
	}
	for(int i = 1;i <= n;++i)
		scanf("%d",&c[i]);
	if(n <= 10)
	{
		for(int i = 1;i <= n;++i)
			p[i] = i;
		do
		{
			cnt = 0;
			cal = 0;
			for(int i = 1;i <= n;++i)
			{
				if(cnt >= c[p[i]] || !a[i])
					cnt++;
				else
					cal++;
			}
			if(cal >= m)
				ans++;
		}while(next_permutation(p + 1,p + n + 1));
		printf("%lld\n",ans);
	}
	else if(n <= 18)
	{
		dp[0][0] = 1ll;
		for(int k = 0;k < (1 << n);++k)
			st[k] = k;
		sort(st,st + (1 << n),cmp);
		for(int i = 0;i < (1 << n);++i)
		{
			cal = cntp(st[i]);
			for(int j = 0;j <= cal;++j)
			{
				for(int x = 1;x <= n;++x)
				{
					if(st[i] & (1 << (x - 1)))
						continue;
					if((cal - j) >= c[x] || !a[cal + 1])
					{
						dp[j][st[i] | (1 << (x - 1))] += dp[j][st[i]];
						dp[j][st[i] | (1 << (x - 1))] %= mod;
					}
					else
					{
						dp[j + 1][st[i] | (1 << (x - 1))] += dp[j][st[i]];
						dp[j + 1][st[i] | (1 << (x - 1))] %= mod;
					}
				}
			}
		}
		for(int i = m;i <= n;++i)
		{
			ans += dp[i][(1 << n) - 1];
			ans %= mod;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
