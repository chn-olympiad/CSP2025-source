#include<bits/stdc++.h>
using namespace std;
int a[10001];
const int p = 998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum = 0;
	long long ans = 0;
	cin >> n;
	
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum += a[i];
	}	
	sort(a+1,a+n+1);
	if(n < 3)
	{
		cout << 0;
		return 0;
	}
	if(n == 3)
	{
		if(sum > 2*a[n])
		{
			cout << 1;
			return 0;
		}
		else
		{
			cout << 0;
			return 0;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i+1;j <= n;j++)
		{
			if(a[i] * 2 < a[j])
			{
				ans++;
			}
		}
	}
	cout << ans%p;
	return 0;
}
