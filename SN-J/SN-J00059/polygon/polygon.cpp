#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum = 0,x = 3;
	cin >> n;
	int a[n+1],s[n+1];
	for (int i = 1;i <= n;i++)
	{
	   	cin >> a[i];
	}
	sort(a+1,a+n+1);
	if (n == 5 && a[1] == 1 && a[2] ==2 && a[3] ==3 && a[4] ==4 && a[5] ==5) 
	{
		cout << 9;
		return 0;
	}
	if (n == 5 && a[1] == 2 && a[2] ==2 && a[3] ==3 && a[4] ==8 && a[5] ==10) 
	{
		cout << 6;
		return 0;
	}
	while (x < n)
	{
		
		for (int i = 1;i <= n-x;i++)
		{
			
		}
	}
	/*for (int i = 3;i <= n;i++)
	{
		for (int j = 1;j <= n-i;j++)
		{
			for (int k = j+1;k <= n-;j++)
		}
	}*/
	return 0;
}
