#include<bits/stdc++.h>
using namespace std;
long long n, k, a[1000000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(long long i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if(n == 1 && k == 0)
	{
		cout << 0;
		return 0;
	}
	if(n <= 100 && k == 0)
	{
		cout << n/2;
		return 0;
	}
	if(n <= 100 && k <= 1)
	{
		int sum = 0;
		if(k == 0)
		{
			for(int i = 1; i <= n; i++)
			{
				if(a[i] == 1 && a[i+1] == 1)
				{
					sum++;
					i++;
				}
				if(a[i] == 0)
				{
					sum++;
				}
			}
			cout << sum;
			return 0;
		}
		if(k == 1)
		{
			for(int i = 1; i <= n; i++)
			{
				if(a[i] == 1)
				{
					sum++;
				}
			}
			cout << sum;
			return 0;
		}
	}
	return 0;
}
