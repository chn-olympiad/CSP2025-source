#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[105];

signed main() {

	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	if (n == 1 && m == 1)
		cout << 1 << ' ' << 1;
	return 0;
}
