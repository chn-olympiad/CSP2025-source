#include <bits/stdc++.h>
using namespace std;
long long a[6000],d[6000];
int n,num;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		d[i] = a[i] + d[i - 1];
	}
	int pp = 0,maxx;
	for(int j = 3;j <= n;j++)
	{
		for(int i = 1;i <= n;i++)
		{
			if(i + j - 1 > n)
			{
				break;
			}
			else
			{
				pp = d[i + j - 1] - d[i - 1];
				for(int w = i + 1;w <= i + j - 1;w++)
				{
					if(a[w] > a[w - 1])
					{
						maxx = a[w];
					}
				}
				if(pp > maxx * 2)
				{
					num++;
				}
			}
		}
	}
	cout << num % 998244353;
	return 0;
}
