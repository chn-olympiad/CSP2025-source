#include <iostream>
#include <algorithm>
using namespace std;

int a[110];

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	int r = a[1];
	sort(a + 1, a + n * m + 1);
	int k = n * m - (lower_bound(a + 1, a + n * m + 1, r) - a) + 1;
	int p = k / n;
	int q = p;
	p *= n;
	if (k % n != 0)
	{
		q++;
	}
	q *= n;
	//1
	if (p == q)
	{
		int y = p / n;
		if (y % n == 1)
		{
			cout << y << ' ' << n;
		}
		else
		{
			cout << y << ' ' << 1;
		}
	}
	else if (p / n % 2 == 1)
	{
		int x = k - p;
		int y = p / n;
		cout << y + 1 << ' ' << n - x + 1;
	}
	else
	{
		int x = k - p;
		int y = p / n;
		cout << y + 1 << ' ' << x;
	}
	return 0;
}
