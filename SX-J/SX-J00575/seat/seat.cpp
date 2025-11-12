#include <bits/stdc++.h>
#define ll long long
#define db double
#define i128 __int128
#define AKIOI ios::sync_with_stdio(false);cin.tie(0),cout.tie(0)
using namespace std;
ll n, m, a[105], mor, k;

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	AKIOI;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (i == 1)
			continue;
		if (a[i] > a[1])
			mor++;
	}
	k = mor / n;
	mor %= n;
	//k:1,mor:0
	if (k % 2 == 0)
		cout << k + 1 << ' ' << mor + 1;
	else
		cout << k + 1 << ' ' << n - mor;
	return 0;
}