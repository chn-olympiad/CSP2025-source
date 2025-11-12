#include <bits/stdc++.h>
using namespace std;

int t[1005];

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> t[i];
	int y = t[1];
	sort(t + 1, t + n * m + 1);
	for (int i = 1; i <= n * m; i++)
		if (t[i] == y) {y = i; break;}
	y = n * m - y + 1;
	int h, l, g = y % n;
	if (g == 0) g = n;
	l = (y - g) / n + 1;
	if (l % 2 == 0) h = n - g + 1;
	else h = g;
	cout << l << " " << h << endl;
	return 0;
}
