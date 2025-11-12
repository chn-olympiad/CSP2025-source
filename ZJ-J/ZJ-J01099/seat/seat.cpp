#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;

int n;
int m;

struct Node
{
	int a;
	int d;
} a[MAXN];

bool cmp (Node aa, Node bd)
{
	return aa.a > bd.a;
}

int x = 0;
int y = 0;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i].a;
		a[i].d = i;
	}

	int ti = 0;

	sort (a + 1, a + 1 + n * m, cmp);
	
	for (int i = 1; i <= n * m; i++)
	{
		if (a[i].d == 1)
		{
			ti = i;
		}
	}
	
	if (ti % m == 0)
	{
		y = ti / m;
	}
	else
	{
		y = ti / m + 1;
	}

	if (y % 2 == 1)
	{
		if (ti % n == 0)
		{
			x = n;
		}
		else
		{
			x = ti % n;
		}
	}
	else
	{
		if (ti % n == 0)
		{
			x = 1;
		}
		else
		{
			x = n - (ti % n) + 1;
		}
	}

	cout << y << " " << x << "\n";

	return 0;
}
