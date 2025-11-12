#include <bits/stdc++.h>
using namespace std;

int n, m, cnt = 0, t;

struct node
{
	int x, id;
}a[2010];
bool cmp (node z, node y)
{
	return z.x > y.x;
}

int main ()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[++cnt].x;
			a[cnt].id = cnt;
		}
	}
	
	sort(a + 1, a + 1 + cnt, cmp);
	
	for (int i = 1; i <= cnt; i++)
	{
		if (a[i].id == 1)
		{
			t = i;
			break;
		}
	}
	
	if (t % n == 0)
	{
		int lie = t / n;
		if (lie % 2 == 1)
		{
			cout << lie << ' ' << n;
		}
		else
		{
			cout << lie << ' ' << 1;
		}
	}
	else
	{
		int lie = t / n + 1;
		if (lie % 2 == 1)
		{
			cout << lie << ' ' << t % n;
		}
		else
		{
			cout << lie << ' ' << n - (t % n) + 1; 
		}
	}
	
	return 0;
}
