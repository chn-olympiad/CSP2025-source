#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, b[105] = {0}, sum = 0, s = 0;
	char a[105] = {0};
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		if (b[i] > s) {
			swap(b[i], s);
		}
		if (s > b[i]) {
			n -= 1;
		}
		if (i == 0 || i == n)
			sum += 1;
	}
	cout << sum;
	return 0;
}