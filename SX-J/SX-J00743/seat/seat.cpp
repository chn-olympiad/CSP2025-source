#include <bits/stdc++.h>
using  namespace std;
int a[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, r, k = 0;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	r = a[1];
	sort(a + 1, a + n *m + 1);
	for (int i = n * m; i >= 1; i--) {
		k++;
		if (a[i] == r) {
			break;
		}
	}
	if (k % n == 0) {
		cout << k / n << " ";
		if (k / n % 2 == 0)
			cout << 1;
		else
			cout << n;
		return 0;
	} else {
		cout << k / n + 1 << " ";
	}
	if ((k / n + 1) % 2 == 0)
		cout << (n - k % n + 1);
	else
		cout << k % n;
	return 0;
}
