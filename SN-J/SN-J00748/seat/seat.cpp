// XGDFZ wsq
#include <bits/stdc++.h>
using namespace std;
#define int long long

namespace wsq {
	int n, m;
	int a[105];
	void main() {
		cin >> n >> m;
		for(int i = 1; i <= n * m; i++)
			cin >> a[i];
		int x = a[1];
		sort(a + 1, a + n*m + 1);
		x = n*m - (lower_bound(a + 1, a + n + 1, x) - a) + 1;
		int c = (x-1) / n+1;
		int r = (c%2 ? (x-1)%n+1 : (n-(x-1)%n));
		cout << c << " " << r << endl;
	}
}

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int T = 1;
	// cin >> T;
	while(T--)
		wsq::main();
	return 0;
}
