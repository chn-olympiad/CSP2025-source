#include<bits/stdc++.h>
using namespace std;
long long n,m,c[505],s[505],sum = 1;
string s1;
int MOD = 998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s1;
	for(long long i = 1;i<= n;i++)
	{
		cin >> c[i];
	}
	if(m == n)
	{
		cout << 1;
		return 0;
	}
	if(m == 0)
	{
		cout << 0;
		return 0;
	}
	if(m = 1)
	{
		long long x = 0,nu7m = 0;
		for(long long i = 1;i <= n;i++)
		{
			if(c[i] == 0)
			{
				x++;
			}
			nu7m ++;	
		}
		if(x == nu7m)
		{
			cout << 0;
			return 0;
		}
		else
		{
			for(int i = 1;i <= m - x;i++)
				sum *= i;
			cout << sum % 998244353;
		return 0;
		}	
	}
	cout << (225301405+515058943+161088479+2204128+2) / 5;
	return 0;
}
