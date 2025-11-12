#include <bits/stdc++.h>
using namespace std;

int x, n, m, a[105];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	x = n * m;
	for (int i = 1; i <= x; i++) cin >> a[i];
	a[0] = a[1];
	sort(a + 1, a + x + 1, greater<int>());
	int num;
	for (int i = 1; i <= x; i++)
	{
		if (a[i] == a[0])
		{
			num = i;
			break;
		}
	}
	int p = (num - 1) / n + 1, q = (num - 1) % n + 1;
	if (p % 2 == 0) q = n - q + 1;
	cout << p << " " << q;
}