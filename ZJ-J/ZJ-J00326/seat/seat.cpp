#include <bits/stdc++.h>
using namespace std;
int n, m, a[1010], s;
bool cmp (int k1, int k2) {return k1 > k2;}
signed main ()
{
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	//OK100
	
	ios::sync_with_stdio(false);
	cin.tie (0), cout.tie (0);
	
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++)
	{
		cin >> a[i];
		s = a[1];
	}
	sort (a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i ++)
	{
		if (a[i] == s)
		{
			cout << (i - 1) / n + 1 << " ";
			if (((i - 1) / n + 1) % 2 == 1) cout << (i - 1) % n + 1;
			else cout << m + 1 - i % n;
		}
	}
}
