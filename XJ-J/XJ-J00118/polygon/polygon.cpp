#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, a[5005], maxx = 0, s = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (maxx < a[i])
		{
			maxx = a[i];
		}
	}
	if (n < 3)
	{
		cout << 0;
	}
	if (n == 3)
	{
		if (a[1] + a[2] + a[3] > maxx * 2)
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	if (n == 4)
	{
		if (a[1] + a[2] + a[3] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[3] + a[4] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[4] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[3] + a[4] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[3] + a[4] > maxx * 2)
		{
			s++;
		}
		cout << s;
	}
	if (n == 5)
	{
		if (a[1] + a[2] + a[3] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[3] + a[4] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[4] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[4] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[3] + a[4] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[3] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[4] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[3] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[4] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[3] + a[4] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[3] + a[4] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[3] + a[4] + a[5] > maxx * 2)
		{
			s++;
		}
		cout << s;
	}
	if (n == 6)
	{
		if (a[1] + a[2] + a[3] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[3] + a[4] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[4] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[4] + a[5] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[4] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[3] + a[4] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[3] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[3] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[4] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[4] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[5] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[4] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[4] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[5] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[5] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[3] + a[4] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[3] + a[4] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[4] + a[5] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[3] + a[4] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[4] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[5] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[4] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[3] + a[5] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[3] + a[4] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[3] + a[5] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[3] + a[4] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[3] + a[4] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[3] + a[4] + a[5] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[3] + a[4] + a[5] + a[6] > maxx * 2)
		{
			s++;
		}
		cout << s;
	}
	if (n == 7)
	{
		if (a[1] + a[2] + a[3] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[3] + a[4] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[4] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[4] + a[5] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[5] + a[6] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[4] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[3] + a[4] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[3] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[3] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[3] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[4] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[4] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[4] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[5] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[5] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[6] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[4] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[4] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[4] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[5] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[5] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[5] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[5] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[6] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[4] + a[6] + a[7] > maxx * 2)
		{
			s++;
		}
		cout << s;
	}
	if (n == 8)
	{
		if (a[1] + a[2] + a[3] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[3] + a[4] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[4] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[4] + a[5] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[5] + a[6] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[6] + a[7] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[4] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[3] + a[4] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[3] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[3] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[3] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[3] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[4] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[4] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[4] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[4] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[5] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[5] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[5] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[6] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[6] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[7] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[4] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[4] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[4] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[4] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[5] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[5] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[5] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[5] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[5] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[5] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[6] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[6] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[7] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[4] + a[6] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[4] + a[6] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[4] + a[7] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[5] + a[7] + a[8] > maxx * 2)
		{
			s++;
		}
		cout << s;
	}
	if (n == 9)
	{
		if (a[1] + a[2] + a[3] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[3] + a[4] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[4] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[4] + a[5] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[5] + a[6] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[6] + a[7] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[7] + a[8] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[4] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[3] + a[4] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[3] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[3] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[3] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[3] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[3] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[4] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[4] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[4] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[4] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[4] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[5] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[5] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[5] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[5] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[6] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[6] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[6] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[7] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[7] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[8] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[4] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[4] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[4] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[4] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[4] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[5] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[5] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[5] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[5] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[5] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[5] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[5] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[5] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[6] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[6] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[6] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[7] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[7] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[4] + a[6] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[4] + a[6] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[4] + a[6] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[4] + a[7] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[4] + a[7] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[4] + a[8] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[5] + a[7] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[5] + a[7] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[6] + a[8] + a[9] > maxx * 2)
		{
			s++;
		}
		cout << s;
	}
	if (n == 10)
	{
		if (a[1] + a[2] + a[3] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[3] + a[4] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[4] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[4] + a[5] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[5] + a[6] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[6] + a[7] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[7] + a[8] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[8] + a[9] + a[10] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[4] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[2] + a[10] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[3] + a[4] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[3] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[3] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[3] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[3] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[3] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[4] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[4] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[4] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[4] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[4] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[5] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[5] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[5] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[5] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[6] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[6] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[6] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[7] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[7] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[1] + a[8] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[4] + a[5] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[4] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[4] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[4] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[4] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[5] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[5] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[5] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[2] + a[5] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[5] + a[6] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[5] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[5] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[5] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[6] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[6] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[6] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[7] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[3] + a[7] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[4] + a[6] + a[7] > maxx * 2)
		{
			s++;
		}
		if (a[4] + a[6] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[4] + a[6] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[4] + a[7] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[4] + a[7] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[4] + a[8] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[5] + a[7] + a[8] > maxx * 2)
		{
			s++;
		}
		if (a[5] + a[7] + a[9] > maxx * 2)
		{
			s++;
		}
		if (a[6] + a[8] + a[9] > maxx * 2)
		{
			s++;
		}
		cout << s;
	}
	return 0;
}
