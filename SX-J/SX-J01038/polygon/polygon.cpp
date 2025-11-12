#include <iostream>
using namespace std;
int n, a[99], m;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; i <= n; j++) {
			for (int q = j + 1; q <= n; q++) {
				if (a[i] > a[j]) {
					m = a[i];
				} else {
					m = a[j];
				}
				if (a[q] > m) {
					m = a[q];
				}
			}
		}
	}
	cout << m;
	return 0;
}
