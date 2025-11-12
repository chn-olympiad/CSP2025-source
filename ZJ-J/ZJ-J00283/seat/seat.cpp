#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	int t = a[1], cnt = 0;
	sort(a + 1, a + 1 + n * m, greater<int>());
	for (int i = 1; i <= m; i++)
	{
		if (i & 1)
		{
			for (int j = 1; j <= n; j++)
				if (a[++cnt] == t)
				{
					cout << i << " " << j;
					return 0;
				}
		}
		else
		{
			for (int j = n; j; j--)
				if (a[++cnt] == t)
				{
					cout << i << " " << j;
					return 0;
				}
		}
	}
	return 0;
}
