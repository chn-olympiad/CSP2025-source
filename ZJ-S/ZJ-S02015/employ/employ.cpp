#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

string s;
long long n, m, c[510], ans = 0;
long long mul(int x, int y)
{
	long long t = 1;
	for (int i = x; i >= y; i--)
	{
		t *= i;
		t %= 998244353;
	}
	return t;
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	bool flag = true;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
		if (s[i] == '0')
		{
			flag = false;
		}
		if (c[i] == 0)
		{
			n--;
		}
	}
	if (flag == true)
	{
		ans = mul(n, n - m + 1);
		ans %= 998244353;
	}
	cout << ans << endl;
	return 0;
}
