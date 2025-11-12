#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
	freopen("polygon.in", "r", stdin);
	feopen("polygon.out", "w". stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	int maxx = 0;
	int cnt = 0;
	int a[n];
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		maxx = max (maxx, a[i]);
		cnt += a[i];
	}
	
	if (n == 3)
	{
		if (maxx * 2 < cnt)
		{
			cout << 1 << "\n";
		}
		else
		{
			cout << 0 << "\n";
		}
	}
	
	return 0;
}

