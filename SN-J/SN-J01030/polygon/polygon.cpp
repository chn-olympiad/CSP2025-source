#include <bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a,a+n);
	int num=0;
	for(int i1 = 1;i1 <= n-2;i1++)
	{
		for(int i2 = i1+1;i2 <= n-1;i2++)
		{
			for(int i3 = i1+2;i3 <= n;i3++)
			{
				if(a[i1]+a[i2]+a[i3] > 2*a[i3]  ) num++;
			}
		}
	}

	cout << num;
	return 0;
}
