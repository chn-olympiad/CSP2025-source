#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005],sum = 0,ans = 0;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		sum = a[i] + a[i + 1] + a[i + 2];
		int maxn = max(max(a[i],a[i + 1]),a[i + 2]);
		if (sum > maxn * 2)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
