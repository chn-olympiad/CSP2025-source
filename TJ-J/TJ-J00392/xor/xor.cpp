#include <bits/stdc++.h>
using namespace std;
long long int a[100000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	long long int ans = 0;
	if (k == 0)
	{
		ans = n;
		for (int i = 1; i <= n; i ++)
		{
			ans -= a[i];
		}
	}
	else if (k == 1)
	{
		for (int i = 1; i <= n; i ++)
		{
			ans += a[i];
		}
	}
	else ans = n;
	cout << ans;
	return 0;
}
