#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[110];
	cin >> n >> m;
	int s[n][m],sum = 1,k;
	for (int i = 1; i <= n*m;i++)
	{
		cin >> a[i];
	}
	k= a[1];
	for (int i = 1; i <= m;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			s[j][i] = sum;
			sum++;
		}
	}
	sort(a+1,a+n*m+1);
	sum = 0;
	for (int i = 1; i <= n*m;i++)
	{
		if ( a[i] == k)
		{
			sum = n*m+1-i;
		}
	}
	for (int i = 1; i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			
			if (s[i][j] == sum)
			{
				cout << j << " " << i;
				break;
		    }
		}
	}
	return 0;
}
