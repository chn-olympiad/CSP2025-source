#include<bits/stdc++.h>
using namespace std;
const int N = 505;
const int M = 998244353;
int n, m, c[N], pd = 0, pd1 = 0;
string d;
int pp(int x, int y)
{
	long long fm = 1;
	for (int i = 1; i <= x; i++)
		fm = fm % M * i % M;
	for (int i = 1; i <= x - y; i++)
		fm = fm % M * i % M;
	for (int i = 1; i <= y; i++)
		fm = fm /  i;
	return fm;
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> d;
	int mq = 0;
	if (m == n)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> c[i];
			if (c[i] == 0)
			{
				cout << 0;
				return 0;
			}
		} 
		for (int i = 0; i < d.size(); i++)
			if (d[i] == '0')
			{
				cout << 0;
				return 0;
			}
		cout << 1;
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
		if (c[i] == 0)
			pd ++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (c[i] != 0 && c[i] <= pd)
			pd1++;
	}
	if (pd != 0)
		n = n - pd1 - pd + 1;
	if (m > n)
	{
		cout << 0;
		return 0;
	}
	cout << pp(n, m);
	return 0;
}
