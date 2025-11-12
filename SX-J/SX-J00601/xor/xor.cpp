#include <iostream>
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	int a[20000001];
	cin >> n >> k;
	int num = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 0) {
		cout << 0;
	} else if (n == 1) {
		if (a[1] == k) {
			cout << 1;
		} else {
			cout << 0;
		}
	} else if (n == 2) {
		if (a[1] + a[2] == k && (a[1] != k || a[2] != k)) {
			num++;
		} else if (a[1] - a[2] == k && (a[1] != k || a[2] != k)) {
			num++;
		} else if (a[1] == k) {
			num++;
		} else if (a[2] == k) {
			num++;
		}
	}
	cout << num;
	return 0;
}
