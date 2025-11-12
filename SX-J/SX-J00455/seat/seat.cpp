#include <bits/stdc++.h>
using namespace std;
int a[1000];

int cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long n, m, s, s1;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	s = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == s) {
			s = i;
			break;
		}
	}
	s1 = s / n;
	if (s1 * n == s) {
		if (s1 % 2 == 0) {
			cout << s1 << " " << 1;
		} else {
			cout << s1 << " " << n;
		}
	} else {
		if ((s1 + 1) % 2 == 0) {
			cout << s1 + 1 << " " << n - (s % n) + 1 ;
		} else {
			cout << s1 + 1 << " " << s % n;
		}
	}
	return 0;
}
