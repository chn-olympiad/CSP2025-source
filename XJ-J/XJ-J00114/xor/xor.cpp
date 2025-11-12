#include <bits/stdc++.h>
using namespace std;
int a[500005], n, k, l, r, cnt0;
string s;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] == 0)
		{
			cnt0++;
		}
	}
	if (k <= 1)
	{
		if (k == 0)
		{
			if (cnt0 != 0)
			{
				cout << (n - cnt0) / 2;
				return 0;
			}
			else
			{
				cout << n / 2;
				return 0;
			}
		}
		else
		{
			cout << n - cnt0;
			return 0;
		}
	}
	return 0;
 } 
