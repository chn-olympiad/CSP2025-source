#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, a[100], s = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 0)
		{
			s++; 
		}
	}
	cout << s;
	return 0;
}
