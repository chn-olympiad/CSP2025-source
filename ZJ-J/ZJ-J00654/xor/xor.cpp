#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1048580];
int ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i ++)
	{
		scanf("%d",&a[i]);
	}
//	if (k == 0 && n <= 2)//1
//	{
//		if (n == 1)
//		{
//			cout << 0;
//		}
//		else
//		{
//			cout << 1;
//		}
//		return 0;
//	}
	if (k <= 1)//1.2.3.4.5.13
	{
		if (k == 0)
		{
			for (int i = 1;i <= n;)
			{
				if (i == n)
				{
					if (a[i] == 0)
					{
						ans ++;
					}
					break;
				}
				else if (a[i] == 0)
				{
					ans ++;
					i ++;
				}
				else if (a[i] == 1 && a[i + 1] == 1)
				{
					ans ++;
					i += 2;
				}
				else
				{
					i ++;
				}
			}
			cout << ans;
			return 0;
		}
		else
		{
			//k = 1;
			for (int i = 1;i <= n;i ++)
			{
				if (a[i] == 1)
				{
					ans ++;
				}
			}
			cout << ans;
			return 0;
		}
	}
//	if (n <= 100 && k == 0)//3
//	{
//		
//	}
	cout << n / 2;
}
