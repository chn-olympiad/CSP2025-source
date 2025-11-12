#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m;
string s;
long long a[501],b[501];
int c[11];
const long long mod = 998244353;
long long jiec(int k)
{
	long long ans = 1;
	for(int i = 1;i <= k;i++)
	{
		ans = (ans * i) % mod;
	}
	return ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	s = ' ' + s;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		b[a[i]]++;
	}
	for(int i = 1;i <= n;i++)
	{
		b[i] += b[i - 1];
	}
	if(n <= 10)
	{
		for(int i = 1;i <= n;i++)
		{
			c[i] = i;
		}
		long long ans = 0;
		do
		{
			int cnt = 0;
			for(int i = 1;i <= n;i++)
			{
				if(s[i] == '1'&&i - cnt - 1 < a[c[i]]) 
				{
					cnt++;
				}
			}
			if(cnt >= m) 
			{
				ans++;
			}
		}while(next_permutation(c + 1,c + n + 1));
		cout << ans;
		return 0;
	}
	if(m == n)
	{
		for(int i = 1;i <= n;i++)
		{
			if(s[i] == '0'||a[i] == 0)
			{
				cout << 0;
				return 0;
			}
		}
		cout << jiec(n);
		return 0;
	}
	if(m == 1)
	{
		long long ans = 0;
		long long jis = 1;
		int used = 0;
		for(int i = 1;i <= n;i++)
		{
			if(s[i] == '0') continue;
			ans = (ans + (jis * (n - b[i - 1]) % mod * jiec(n - used - 1)) % mod) % mod;
			jis = (jis * (b[i - 1] - used)) % mod;
			used++;
		}
		cout << ans;
	}
}
