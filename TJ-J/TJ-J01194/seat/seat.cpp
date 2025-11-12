#include <bits/stdc++.h>

using namespace std;

int n, m, a[105], cnt, num, r = 0, c = 1, f;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++) cin >> a[i];
	num = a[1];
	sort(a + 1, a + n * m + 1);
	for (int i = n * m;i >= 1; i--)
	{
		f++;
		if (a[i] == num)
		{
			num = f;
			break;
		}
	}
	while (num > 0)
	{
		if (r >= n)
		{
			r = 0;
			c++;
		}
		r++;
		num--;
	}
	if (c % 2 == 0) r = n - r + 1;
	cout << c << ' ' << r;
	return 0;
}
