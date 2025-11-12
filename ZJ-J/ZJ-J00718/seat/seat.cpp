#include <bits/stdc++.h>
using namespace std;
int n, m, rnk = 1;
int a[101];
int t, tt;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	cin >> a[1];
	for (int i = 2; i <= n * m; ++i)
	{
		cin >> a[i];
		if (a[i] > a[1])
			++rnk;
	}
	t = (rnk + n - 1) / n;
	tt = (rnk - 1) % n + 1;
	if (t % 2 == 1)
		cout << t << ' ' << tt << '\n';
	else
		cout << t << ' ' << n - tt + 1 << '\n';
	return 0;
}
