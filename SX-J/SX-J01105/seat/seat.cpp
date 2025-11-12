#include <bits/stdc++.h>
using namespace std;
int n, m, a[210], x, c, s;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m >> a[1];
	sort(a + 1, a + 1 + n, greater() );
	for (int i = 2; i <= n * m; i++) {
		cin >> a[i];
		if (a[1] < a[i]) {
			c++;
		}
	}
	if ((c / n) % 2 == 1) {
		s = n - c % n;
		cout << c / n + 1 << " " << s;
	} else {
		s = c % n + 1;
		cout << c / n + 1 << " " << s;
	}
	return 0;
}
