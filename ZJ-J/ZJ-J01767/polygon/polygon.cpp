#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005],q[5005];
	cin >> n;
	long long ans = 0;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	q[0] = 0;
	for (int i = 1;i <= n;i++)
	{
		q[i] = q[i-1]+a[i];
	}
	int di,di2,pos,pos1;
	bool flag = true;
	for (int i = n;i >= 3;i--)
	{
		di = q[i]-2*a[i];
		if (di <= 0)
		{
			continue;
		}
		for (int j = 1;j < i;j++)
		{
			if (a[j] > di)
			{
				break;
			}
			if (j == 1)
			{
				ans++;
			}
			else
			{
				ans++;
				if (!flag)
				{
					break;
				}
				if (q[j] < di)
				{
					ans += (((int)pow(2,j))/2-1);
				}
				else
				{
					flag = false;
					pos = j;
					ans += (((int)pow(2,j))/2-2);
				}
			}
		}
	}
	cout << ans;
	return 0;
}
