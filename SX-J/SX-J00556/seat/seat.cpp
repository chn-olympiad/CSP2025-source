#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen(" seat.in", "r", stdin);
	freopen(" seat.out", "w", stdout);
	int n, m, sum = 0;
	cin >> n >> m;
	int a[105];
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int t = a[1];
	for (int i = 1; i <= n * m ; i++) {
		for (int j = 1; j <= n * m - i; j++) {
			if (a[j] < a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
	for (int i = 1; i <= n * m; i++) {
		sum++;
		if (a[i] == t) {
			break;
		}
	}
	int hang, lie;
	if (sum % n != 0) {
		lie = sum / n + 1;
	} else
		lie = sum / n;
	if (lie % 2 == 0) {
		hang =  n + 1 - sum % n;
	} else {
		if (sum % n == 0)
			hang = n;
		else
			hang = sum % n;
	}
	cout << lie << " " << hang;
	return 0;
}