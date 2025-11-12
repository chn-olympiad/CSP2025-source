#include <bits/stdc++.h>
using namespace std;
int m,n,a[105],seat;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++)
	{
		cin >> a[i];
	}
	int gra = a[1];
	for (int i = 1;i <= m * n;i++)
	{
		for (int j = i + 1;j <= n * m;j++)
		{
			if (a[i] < a[j])
			{
				int x = a[i];
				a[i] = a[j];
				a[j] = x;
			}
		}
	}
	for (int i = 1;i <= n * m;i++)
	{
		if (a[i] == gra)
		{
			seat = i;
			break;
		}
	}
	if (seat <= n)
	{
		cout << "1" << " " << seat;
	}
	else
	{
		if (seat % 2 == 1)
		{
			cout << seat/n + 1 << " " << seat % n;
		}
		else
		{
			cout << seat/n + 1 << " " << n - seat % n + 1;
		}
	}
	return 0;
}
