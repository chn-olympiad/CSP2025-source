#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int n, k, a[maxn], maxx, minn, num;
int main ()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		maxx = max(maxx, a[i]);
		minn = min(minn, a[i]);
		if (a[i] == 1)
		{
			num++;
		}
	}
	if (maxx == 1 && minn == 1)
	{
		if (k == 1)
		{
			cout << n;
		}
		else
		{
			cout << n / 2;
		}
	}
	if (maxx == 1 && minn == 0)
	{
		if (k == 1)
		{
			cout << num;
			return 0;
		}
		else
		{
			cout << num / 2;
		}
	}
	return 0;
}

