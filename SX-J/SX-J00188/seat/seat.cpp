#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a[101], b[11][11], p;
	cin >> n >> m;
	p = n * m;
	for (int i = 0; i < p; i++) cin >> a[i];
	int c = a[0], d, e, f;
	sort(a, a+p, cmp);
	b[1][1] = 1;
	for (int j = 2; j <= m; j++)
	{
		if (j % 2) b[1][j] = b[1][j - 1] + 1;
		else b[1][j] = b[1][j - 1] + n + n - 1;
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (j % 2) b[i][j] = b[i - 1][j] + 1;
			else b[i][j] = b[i - 1][j] - 1;
		}
	}
	for (int i = 0; i < p; i++) if (a[i] == c) d = i + 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (b[i][j] == d)
			{
				e = i;
				f = j;
			}
		}
	}
	cout << e << " " << f;
	return 0;
}