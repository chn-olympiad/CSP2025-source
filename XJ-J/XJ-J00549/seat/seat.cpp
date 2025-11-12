#include <bits/stdc++.h>
using namespace std;

int s[15][15], n, m, a[400], r;

bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n*m; i++)
	{
		cin>>a[i];
	}
	r = a[1];
	sort(a+1, a+n*m+1, cmp);
	int flag_x = 1;
	for (int j=1; j<=m; j++)
	{
	    if (j % 2 == 1)
	    {
	    	for (int i=1; i<=n; i++)
	    	{
	    		s[i][j] = a[flag_x];
	    		flag_x++;
			}
		}
		else
		{
			for (int i=n; i>=1; i--)
			{
				s[i][j] = a[flag_x];
				flag_x++;
			}
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (s[i][j] == r)
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
