#include <bits/stdc++.h>
using namespace std;
int n, m, a[1000], sum = 1;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (a[1] < a[i])
			sum++;
	}

	cout << ceil(sum * 1.0 / n) << ' ';
	if (int(ceil(sum * 1.0 / n)) % 2 == 1)
		if (sum % n == 0)
			cout << n;
		else
			cout << sum % n;
	else
		cout << m + 1 - (sum % n);
	return 0;
}
