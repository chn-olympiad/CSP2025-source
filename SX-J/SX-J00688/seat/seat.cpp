#include <bits/stdc++.h>
using namespace std;
int t[125];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, x;
	cin >> n >> m;
	cin >> x;
	t[1] = x;
	for (int i = 2; i <= n * m; i++) {
		cin >> t[i];
	}
	sort(t + 1, t + n *m + 1);
	int s, l = 0;
	for (int i = n * m; i >= 1; i--) {
		l++;
		if (t[i] == x) {
			s = l;
			break;
		}

	}
	if (s % n == 0) {
		if (s / n % 2 == 0) {
			cout << s / n << " " << 1;
		} else {
			cout << s / n << " " << n;
		}
	} else {
		if (s / n % 2 == 0) {
			cout << s / n + 1 << " " << s % n;
		} else {
			cout << s / n + 1 << " " << n - (s % n - 1);
		}
	}
	return 0;
}