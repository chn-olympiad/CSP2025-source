#include <bits/stdc++.h>
using namespace std;
int a[5005];
long long int i(int n)
{
	if (n <= 2)
		return 2;
	return n * i(n);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	if (n == 3)
	{
		if (a[1] + a[2] > a[3] && a[2] + a[3] >= a[1] && a[1] + a[3] >= a[2])
			cout << 1;
		else
			cout << 0;
	}
	else
	{
		cout << i(n);
	}
	return 0;
}
