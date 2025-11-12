#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n;
	int m;
	cin >> n >> m;
	int a[100000];
	int j = 1;
	for (int i = 1; i <= m * n; i++) {
		cin >> a[i];
	}
	int a1 = a[1];
	for (int i = 2; i <= m * n; i++) {
		if (a1 < a[i]) {
			j++;
		}
	}
	int n1 = j / n;
	if (j % n != 0) {
		n1 += 1;
	}
	int m1;
	if (n1 % 2 == 0) {
		m1 = n - (j % n) + 1;
	} else {
		m1 = j % n;
		if (j % n == 0) {
			m1 = n;
		}
	}
	cout << n1 << " " << m1;
	return 0;
	fclose(stdin);
	fclose(stdout);
}