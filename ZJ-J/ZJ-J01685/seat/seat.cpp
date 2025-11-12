#include <bits/stdc++.h>
using namespace std;
long long ansx, ansy, n, m, a[105], sco, w;
bool cmp(long long x, long long y){ return x > y; }
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	sco = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++)
		if (a[i] == sco)
			w = i;
	while (w >= n)
	{
		w -= n;
		ansx++;
	}
	if (w != 0)
	{
		if (ansx % 2 == 0)
			ansy = w;
		else
			ansy = n - w + 1;
		ansx++;
	}
	else
	{
		if (ansx % 2 == 0)
			ansy = 1;
		else
			ansy = n;
	}
	cout << ansx << " " << ansy;
	return 0;
}