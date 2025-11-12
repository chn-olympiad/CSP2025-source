#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int a[5005] = {};
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	
	int cnt = 0;
	int maxn = 0;
	for(int i = 1;i <= n;i++)
	{
		int m = 3;
		for(int j = 1;j <= m;j++)
		{
			if(a[i] > maxn)
			{
				maxn = a[i];
			}
		}
		int tl = 0;
		for(int k = 1;k <= m;k++)
		{
			if(a[k] + a[k+1] > maxn*2)
			{
				cnt++;
				break;
			}
			else
			{
				int tl = a[k] + a[k+1];
				k++;
			}
		}
	}
	cout << cnt;
	return 0;
}
