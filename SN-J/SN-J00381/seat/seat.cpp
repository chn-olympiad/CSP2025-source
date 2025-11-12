#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[105];
	int c[11][11];
	int n,m,r=0;
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
	}
	r += a[1];
	for (int i = 1; i<= n*m;i++)
	{
		
		if (a[i+1] > a[i])
		{
			int b = a[i];
			a[i] = a[i+1];
			a[i+1] = b;
		}
		for (int j = 1; j <= n*m;j++)
		{
			c[i][n-j+1] = a[i];
		}
		if (a[i] == i && m % 2 == 1)
		{
			cout << m << " " << n;
			return 0;
		}
		else if (a[i] == i && m %2 == 0)
		{
			cout << m << " " << n-i+1;
			return 0;
		}
		else if (a[i] == n*m-i+1)
		{
			cout << 1 << " " << 1;
			return 0;
		}
	}
	for (int i = 1; i <= n*m; i++)
	{
		for (int j = 1; j <= n*m; i++)
		{
			if (r == c[i][n-j+1])
			{
				cout << i << " " << n-j+1;
			}
		}
	}
	return 0;
}
