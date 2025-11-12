#include<bits/stdc++.h>
using namespace std;
int a[500001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans = 0;
	cin >> n >> k;
	int pa = 1;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] != 1)
		{
			pa = 0;
		}
		if(a[i] == k)
		{
			ans++;
		}
	}
	if(k == 0 && pa == 1)
	{
		cout << 0;
		return 0;
	}
	if(k == 1)
	{
		cout << ans;
		return 0;
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i+1;j <= n;j++)
		{
			int sum = 0;
			for(int h = i;h <= j;h++)
			{
				sum |= a[h];
			}
			if(sum == k)
			{
				ans ++;
			}
		}
	}
	cout << ans;
	return 0;
}
