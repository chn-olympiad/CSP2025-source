#include <bits/stdc++.h>

using namespace std;

int n, m, a[101], r, c;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	int p = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	for (int i = 1; i <= n * m; i++)
	{
		if (p == a[i])
		{
			int k = i % m;
			c = i / m;
			if (k) c++;
			if (c % 2 == 1)
			{
				r = k;
				if (k == 0) r = n;
			}
			if (c % 2 == 0)
			{
				r = n - k + 1;
				if (k == 0) r = 1;
			}
		}
	}
	cout << c << " " << r;
	return 0;
}
