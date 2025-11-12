#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], w;
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> a[1];
	w = a[1];
	for (int i = 2; i <= n*m; i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for (int i = 1; i <= n * m; i++)
	{
		if (a[i] == w)
		{
			int x1 = 1, y1 = 1;
			if (i%n==0)
			{
				x1 = i/n;
				y1 = n;
			}
			else
			{
				x1 = i/n+1;
				y1 = i%n;
			}
			if (x1 % 2 == 1)
			{
				cout << x1 << " " << y1;
			}
			else
			{
				cout << x1 << " " << m-y1+1;
			}
		}
	}
	return 0;
}
