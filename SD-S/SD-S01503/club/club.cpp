#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t;
int cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		int n;
		int a[N], b[N], c[N], ans = 0;
		cin >> n;
		int w = n / 2;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i] >> b[i] >> c[i];
		}
		for(int i = 1; i <= n; i++)
		{
			int d = max(a[i], max(b[i], c[i]));
			ans += d;
		}
		cout << ans << "\n";
	}
	return 0;
}

