#include <bits/stdc++.h>
using namespace std;
int n, m, s = 1;
int a[101];

int main() {
	//freopen("seat.in", "r", stdin);
	//freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> a[1];
	for (int i = 2; i <= n * m; i++) {
		cin >> a[i];
		if (a[i] > a[1])
			s++;
	}
	if (s > n) {
		if ((s / n + 1) % 2 != 0)
			cout << s / n + 1 << " " << s % n;
		if ((s / n + 1) % 2 == 0)
			cout << s / n + 1 << " " << 1 + s / n;
	} else
		cout << "1" << " " << s;
	return 0;
}