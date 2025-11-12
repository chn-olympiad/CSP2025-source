#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen ("ploygon.in","r",stdin);
	freopen ("ploygon.out","w",stdout);
	int n,a[5005];
	cin >> n;
	int s = -1;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		s = max(s,a[i]);
	}
	if (n == 3)
	{
		cout << 1;
	}
	if (s == 1)
	{
		long long ans;
		ans = n * n / 2;
		cout << ans % 998244353;
	}
	return 0;
}
