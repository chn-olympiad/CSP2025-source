#include <bits/stdc++.h>
using namespace std;
int n,a[5005],cnt;
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-2;i++)
	{
		for(int j=2;j<=n-1;j++)
		{
			for(int h=3;h<=n;h++)
			{
				if((a[i]+a[j]+a[h])>a[h]*2)
				{
					cnt++;
				}
			}
		}
	}
	cout << cnt;
	return 0;
}
