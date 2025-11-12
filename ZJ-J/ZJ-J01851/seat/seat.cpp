#include <bits/stdc++.h>
//#inlcude <bits\stdc++.h>

using namespace std;

const int N = 10, M = 10;

int n, m, t, num = -1, a[N * M];

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
//	freopen("seat.in", "r", stdin);
//	freopen("seat.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++ )	cin >> a[i];
	t = a[1];
	sort(a + 1, a + n * m + 1, [](int x, int y){return x > y;});
	for (int i = 1; i <= n * m; i ++ )
		if (a[i] == t) {
			num = i;
			break;
		}
	cout << (t = (num - 1) / n + 1) << ' ';
	num -= (num - 1) / n * n;
	if (t & 1)	cout << num << '\n';
	else	cout << n - num + 1 << '\n';
	return 0;
}
//ni bei pian le
