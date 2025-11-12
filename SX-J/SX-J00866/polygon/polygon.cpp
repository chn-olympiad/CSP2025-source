#include <bits/stdc++.h>
using namespace std;
int a, b[5005], c[5005], d[5005], cnt = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	for (int i = 1; i <= a; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= a; i++) {
		c[i] = b[i] + b[i + 1];
	}
	for (int i = 1; i <= a; i++) {
		if (b[i] < b[i + 1]) {
			d[i] == b[i + 1];
		} else {
			d[i] == b[i];
		}
	}
	for (int i = 1; i <= a; i++) {
		if (m > 3 && c[i] > 2 * d[i]) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}