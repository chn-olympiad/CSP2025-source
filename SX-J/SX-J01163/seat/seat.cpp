#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, c = 1, r = 1;
	cin >> n >> m;
	int a[n * m] ;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		int b = a[1];
		if (b <= a[i + 1])
			r++;
	}
	cout << c << " " << r;
	return 0;
}
