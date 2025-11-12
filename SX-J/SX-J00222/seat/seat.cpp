#include <bits/stdc++.h>
using namespace std;
int a[255], n, m, num, cnt;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	num = a[1];
	sort(a + 1, a + n *m + 1);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == num)
			num = n * m - i;
	}
	if (num % n != 0) {
		if ((num + 1) / n / 2 != 0)
			cout << (num + 1) / n << " " << num % n << endl;
		else
			cout << (num + 1) / n << " " << n - num % n << endl;
	} else {
		if ((num + 1) / n / 2 != 0)
			cout << 1 << " " << num % n << endl;
		else
			cout << n << " " << n - num % n << endl;
	}
	return 0;
}