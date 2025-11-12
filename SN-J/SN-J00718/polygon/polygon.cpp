#include <bits/stdc++.h>
using namespace std;
int n,a[10005],sum1;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum1 += a[i];
	}
	sort(a+1,a+n+1);
	if (a[3]*2 < sum1)
	{
		cout << 1;
	}
	else
		cout << 0;
	return 0;
}
