#include <bits/stdc++.h>
using namespace std;

int a[105];

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, b;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) scanf("%d", &a[i]);
	b = a[1];
	sort(a + 1, a + 1 + n * m, cmp);
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 1)
		{
			for (int j = 1; j <= m; j++)
			{
				if (a[(i - 1) * m + j] == b)
				{
					cout << i << " " << j << endl;
					return 0;
				}
			}
		}
		else
		{
			for (int j = 1; j <= m; j++)
			{
				if (a[(i - 1) * m + j] == b)
				{
					cout << i << " " << (m - j + 1) << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
