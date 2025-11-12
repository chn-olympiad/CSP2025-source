#include<bits/stdc++.h>
using namespace std;
int a[101];
int main()
{
//	feropen("seat.in","r",std);
//	feropen("seat.out","w",std);
	int n,m;
	cin >> n >> m;
	for(int i = 0;i <= 101;i++)
	{
		cin >> a[i];
	}
	for(int i = 2;i <= 101;i++)
	{
		sort(a[i],a[i+1]);
		if(m%2 == 1)
		{
			for(int j = m;j <= m;j--)
			{
				for(int k = n;k <= n;k--)
				{
					if(a[1] > a[i])
					{
						cout << j << " " << k;
						return 0;
					}
				}
			}
		}
		if(m%2 == 0)
		{
			for(int j = 1;j <= m;j++)
			{
				for(int k = 1;k <= n;k++)
				{
					if(a[1] < a[i])
					{
						cout << j << " " << k;
						return 0;
					}
				}
			}
		}
	}
	return 0;
}
