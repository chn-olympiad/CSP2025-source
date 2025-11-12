#include <bits/stdc++.h>
using namespace std;
int m, n, b, h, l;
int a[105];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m * n; i++) {
		cin >> a[i];
		b = a[1];
	}
	for (int j = 1; j < m * n; j++) {
		for (int i = m * n; i >= 1; i--) {
			if (a[i] > a[i - 1])
				swap(a[i], a[i - 1]);
		}
	}
	for (int i = 1; i <= m * n; i++) {
		if (a[i] == b) {
			l = i / n + 1;
			if (i / n % 2 == 0) {
				h = i % n + 1;
			} else
				h = n - i % n;
			break;
		}
	}
	cout << l << " " << h;
	return 0;
}