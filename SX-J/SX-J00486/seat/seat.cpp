#include <bits/stdc++.h>
using namespace std;
int n, m, c, r, w, p, q;
int ans = 0;
int a[10010];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	cin >> n >> m;
	w = n * m;
	int sum;
	for (int i = 1; i <= w; i++) {
		cin >> a[i];
		//cout << a[i];
	}
	sum = a[1];
	sort(a + 1, a + w + 1);
	for (int i = w; i > 0; i--) {
		cout << "a[i]" << a[i] << endl;
		if (sum == a[i]) {
			ans = w - i + 1;
			cout << "direction" << ans << endl;
			break;
		}

	}
	if (ans < n) {
		c = 1;
		r = ans;
	} else {
		if (ans % n == 0 && (ans % n) % 2 == 0)

		{
			c = ans / n;
			r = 1;
		} else if (ans % n == 0 && (ans % n) % 2 != 0)

		{
			c = ans / n;
			r = n;
		} else if (ans % n != 0) {
			c = ans / n + 1;
			if (c % 2 == 0)
				r = ans % n;
			if (ans % n == 3) {
				r = ans % n - 1;
			}
		}
	}
	cout << c << r + 1  << endl;
	return 0;
}
