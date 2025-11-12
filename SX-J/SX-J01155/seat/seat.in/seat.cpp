#include <bits/s5tdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, s, a(n *m), c, r;
	cin >> n >> m >> c >> r >> a(n *m) >> s;
	int n*m[100];
	for (int i = 0; i <= n * m; i++) {
		cin >> n*m[i];
	}
	sort(s + n, s + n + 1);
	cout << n*m[n - a(n*m-i+1)];
	cout << c << r;
	return 0;
}
