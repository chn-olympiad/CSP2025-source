#include <bits/stdc++.h>
using namespace std;
int a[1000], n, m, b, s = 1;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m >> b;
	for (int i = 1; i < n * m; i++)
		cin >> a[i];
	for (int i = 1; i <= 1000; i++) {
		if (a[i] == 0)
			break;
		if (a[i] > b)
			s++;
	}
	if (s % n == 0) {
		cout << s / n << " ";
		if ((s / n) % 2 == 0)
			cout << 1;
		else
			cout << n;
	} else {
		if ((s / n + 1) % 2 == 0)
			cout << s / n + 1 << " " << n - s % n + 1;
		else
			cout << s / n + 1 << " " << s % n;
	}
	return 0;
}
