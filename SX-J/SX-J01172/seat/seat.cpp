#include <bits/stdc++.h>
using namespace std;
int a[105];

bool p(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, c;
	cin >> n >> m;
	int j = n * m;
	for (int i = 0; i < j; i++) {
		cin >> a[i];
	}
	int b = a[0];
	sort(a, a + j, p);
	for (int i = 0; i < j; i++) {
		if (b == a[i]) {
			c = i;
			break;
		}
	}
	cout << c / n + 1 << " ";
	if (c / n % 2 != 0) {
		cout << n - c % n;
	} else {
		cout << c % n + 1;
	}
	return 0;
}
