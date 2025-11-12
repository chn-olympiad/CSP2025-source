#include <bits/stdc++.h>
using namespace std;
int n, m, a[200];
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int r, se;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	r = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++)
	{
		if (a[i] == r)
		{
			se = i;
			break;
		}
	}
	if (((se - 1) / n + 1) % 2 == 1)
	{
		cout << (se - 1) / n + 1 << " ";
		if (se % n == 0)
		    cout << n;
		else cout << se % n;
	}
	else 
	{
		cout << (se - 1) / n + 1 << " ";
		if (se % n == 0)
			cout << 1;
		else cout << n - se % n + 1;
	}
	return 0;
}

