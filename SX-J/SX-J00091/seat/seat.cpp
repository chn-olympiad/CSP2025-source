#include <bits/stdc++.h>
using namespace std;
int n, m, temp, sum;
int a[110];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int ha = a[1];
	sort(a + 1, a + n *m + 1);
	for (int i = 1; i <= n * m / 2; i++) {
		temp = a[i];
		a[i] = a[n * m - i + 1];
		a[n * m - i + 1] = temp;
		if (a[i] == ha) {
			sum = i;
		} else {
			if (a[n * m - i + 1] == ha) {
				sum = n * m - i + 1;
			}
		}
	}
	if (sum == 0) {
		sum = n * m / 2 + 1;
	}
	int lie = (sum - 1) / n;
	if (lie % 2 == 1) {
		cout << lie + 1 << " ";
		cout << n - (sum - (lie *n)) + 1;
		return 0;
	} else {
		cout << lie + 1 << " ";
		cout << sum - (lie *n) ;

	}

	return 0;
}
