// rp++
// orz cyh sto

#include <bits/stdc++.h>

using namespace std;

const int N = 10000;
int n, m, a[N], cyh;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1;i <= n * m;i++)
		cin >> a[i];
	cyh = a[1];
	sort(a + 1, a + 1 + n * m, greater<int>());
	int x = 1, y = 1, op = 1, now = 1;
	while (now <= n * m)
	{
		// cout << x << " " << y << " " << a[now] << "\n";
		if (a[now] == cyh) break;
		now++, x += op;
		if (x == 0) x = 1, y++, op = -op;
		else if (x == n + 1) x = n, y++, op = -op;
	}
	// 他的座位为第几列第几行
	cout << y << " " << x << "\n";
/*
	cout << "debug" << "\n";
	for (int i = 1;i <= n * m;i++)
		cout << a[i] << " \n"[i == n * m];
*/
	return 0;
}