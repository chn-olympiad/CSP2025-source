#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
int n, a[5005], v[5005], c[5005], ans;
int cmp(int a, int b)
{
	return a < b;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	memset(a+1, a+1+n, cmp);
	if (n <= 3)
	{
		if (a[1]+a[2] > a[3]) cout << 1;
		else cout << 0;
		return 0;
	}
	cout << 9999;
	return 0;
}
