#include <bits/stdc++.h>
using namespace std;
int t, n;
int A = 0, B = 0, C = 0, sum = 0;
int main()
{
//  freopen("club.in","r",stdin)
//  freopen("club.out","w",stdout)
	int a[100005], b[100005], c[100005];
	cin >> t >> n;
	for (int i = 1; i <= t; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[j];
			cin >> b[j];
			cin >> c[j];
		}
		for (int j = 1; j <= n; j++)
		{
			if (a[j] >= b[j] and a[j] >= c[j])
			{
				if (A <= n/ 2)
				{
					sum += a[j];
					A += 1;
				}
				else
				{
					if (b[j] > c[j] and B <= n/2)
					{
						sum += b[j];
						B += 1;
					}
					else
					{
						sum += c[j];
						C += 1;
					}
				}
			}
			if (b[j] >= a[j] and b[j] >= c[j])
			{
				if (B <= n / 2)
				{
					sum += b[j];
					B += 1;
				}
				else
				{
					if (a[j] > c[j] and A <= n/2)
					{
						sum += a[j];
						A += 1;
					}
					else
					{
						sum += c[j];
						C += 1;
					}
				}
			}
			if (c[j] >= b[j] and c[j] >= a[j])
			{
				if (C <= n/2)
				{
					sum += c[j];
					C += 1;
				}
				else
				{
					if (a[i] > b[i] and A <= n/2)
					{
						sum += a[i];
						A += 1;
					}
					else
					{
						sum += b[i];
						B += 1;
					}
				}
			}
		}
		cout << sum << endl;
	}
}
