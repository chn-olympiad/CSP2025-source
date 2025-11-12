#include <bits/stdc++.h>
using namespace std;
int a[105];

int main() {
	int m, n, b;
	cin >> m >> n;
	for (int i = 1; i <= m * n; i++) {
		cin >> a[i];
	}
	b = a[1];
	for (int i = 1; i <= m * n - 1; i++) {
		for (int j = 2; j <= m * n; j++) {
			if (a[i] < a[j]) {
				int c = a[i];
				a[i] = a[j];
				a[j] = c;
			}
		}
	}
	for (int i = 1; i <= sizeof(a); i++)
		cout << a[i];
	for (int i = 1; i <= m * n; i++) {
		if (b == a[i]) {
			b = i;
		}
	}
	int m1, n1;
	m1 = ceil(1.0 * b / n);
	if (m1 % 2 != 0)
		n1 = b - (m1 - 1 * n);
	else
		n1 =  n - (b - (m1 - 1 * n)) + 1;
	cout << m1 << " " << n1;
	return 0;
}
