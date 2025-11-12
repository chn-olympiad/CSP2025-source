#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;
const int mod = 998244353;
long long n, m, jc[505], p[505], c[505], num1, num, ans;
string s;
bool flag;
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	jc[0] = 1;
	for (int i = 1;i <= n;i++)
	{
		jc[i] = jc[i - 1] * i % mod;
	}
	for (int i = 0;i < n;i++)
	{
		num1 += s[i] == '1';
	}
	if (num1 < m)
	{
		cout << 0;
	}
	else if (m == n)
	{
		for (int i = 1;i <= n;i++)
		{
			cin >> c[i];
			if (!c[i])
			{
				cout << 0;
				return 0;
			}
		}
		cout << jc[n];
	}
	else
	{
		if (n <= 10)
		{
			for (int i = 1;i <= n;i++)
			{
				cin >> c[i];
				p[i] = i;
			}
			do
			{
				num = 0;
				for (int i = 1;i <= n;i++)
				{
					if (s[i - 1] == '0' || num >= c[p[i]])
					{
						num++;
					}
				}
				if (num <= n - m)
				{
					ans += (num <= n - m);
				}
			}
			while (next_permutation(p + 1, p + n + 1));
			cout << ans;
		}
	}
	return 0;
}
