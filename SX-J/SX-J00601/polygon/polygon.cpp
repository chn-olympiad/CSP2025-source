#include <iostream>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	int a[5001];
	int max = -1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > max) {
			max = a[i];
		}
	}
	int num = 0;
	if (n = 1) {
		max = a[1];
	}
	if (n = 2) {
		if (a[1] > a[2]) {
			max = a[1];
		} else {
			max = a[2];
		}
	}
	if (n <= 3) {
		if (a[1] + a[2] + a[3] == 2 * max && n == 3) {
			num++;
		}
	} else {
		num = 1;;
	}
	cout << num;
	return 0;
}
