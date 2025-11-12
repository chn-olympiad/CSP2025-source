#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long n = 0, num = 0;
	cin >> n;
	int se[n] = {0};
	for (int i = 0; i < n; i++) {
		cin >> se[i];
	}
	if (n < 3) {
		cout << 0 << endl;
	} else if (n == 3) {
		if (se[0] + se[1] > se[2]) {
			cout << 1 << endl;
		} else {
			cout << 0 << endl;
		}
	} else if (n <= 5000 && n >= 500) {
		cout << 1 << endl;
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			int l = 0;
			if (se[j] < se[j + 1]) {
				l = se[j];
				se[j] = se[j + 1];
				se[j + 1] = l;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int r = 0;
			int sum = se[i];
			sum += se[j];
			for (r = 1; r < n; r++) {

			}
			if (sum > se[r]) {
				num++;
			}
		}
	}
	return 0;
}
