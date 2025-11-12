#include <bits/stdc++.h>
using namespace std;
int n, m, s, x, a[105], h1, h2, sum = 0;
int main()
{
	freopen(seat.in,r,stdin);
	freopen(seat.out,w,stdout);
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++)
	{
		cin >> a[i];
	}
	s = a[1];
	sort(a + 1, a + n*m + 1);
	for (int i = n*m; i >= 1; i--)
	{
		sum += 1;
		if (a[i] == s)
		{
			x = sum;
			break;
		}
	}
	if (x % m == 0)
	{
		h1 = x / m;
		h2 = n;
	}
	else
	{
		h1 = x / m + x % m;
		if (h1 % 2 == 0)
		{
			h2 = x / m + x % m;
		}
		else
		{
			h2 = x / m - x % m;
		}
	}
	cout << h1 << ' ' << h2;
	return 0;
}
