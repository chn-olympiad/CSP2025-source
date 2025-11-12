#include <iostream>
#include <cstdio>
using namespace std;
int a[5005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	for(int i = 0;i < n;i++)
	{
		bool f = true;
		for(int j = 0;j < n;j++)
		{
			if(a[j] > a[j+1])
			{
				int x = a[j];
				a[j+1] = x;
				a[j] = a[j+1];
				f = false;
			}
		}
		if(f)break;
	}
	int cnt = 0;
	for(int i = 1;i <= n-2;i++)
	{
		int m = 0;
		m = a[i] + a[i+1];
		for(int j = i+2;j <= n;j++)
		{
			m+=a[j];
			if(m > a[j]*2)cnt++;
		}
	}
	cout << cnt%998244353;
	return 0;
} 
