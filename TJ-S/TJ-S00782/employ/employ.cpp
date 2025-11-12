#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n, m, t, a[1000], sum = 1;
	cin >> n >> m >> t;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (a[i] > 0)
		{
			sum *= a[i];
			sum % 998244353;
		}
	}
	cout << sum;
	return 0;
} 
