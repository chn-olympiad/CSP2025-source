#include <bits/stdc++.h>
#define lli long long int
using namespace std;



signed main(void) {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int c = 1;
	int a;
	cin >> a;
	for (int i = 2; i <= n * m; i++) {
		int x;
		cin >> x;
		if (x > a) c++;
	}
	if (c / n % 2) {
		if (c % n == 0) cout << c / n << ' ' << n;
		else cout << c / n + 1 << ' ' << n - c % n + 1;
	} else {
		if (c % n == 0) cout << c / n << ' ' << 1;
		else cout << c / n + 1 << ' ' << c % n;
	}
	return 0;
} 
