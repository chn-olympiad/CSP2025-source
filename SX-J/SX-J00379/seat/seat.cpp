#include <bits/stdc++.h>
using namespace std;
int n, m, xr, x, sum;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {

		cin >> x;
		if (i == 1)
			xr = x;

		if (x > xr)
			sum++;


	}


	int sum1 = sum + 1;
	int lie = sum1 / n;
	if (sum1 % n == 0)
		lie--;
	cout << ++lie << ' ';
	//ап
	if (lie % 2 != 0) {
		if (sum1 % n == 0)
			cout << n;
		else
			cout << sum1 % n;
	}

	else {
		if (sum1 % n == 0)
			cout << n;
		else
			cout << n - (sum1 % n) + 1;

	}


	return 0;
}
