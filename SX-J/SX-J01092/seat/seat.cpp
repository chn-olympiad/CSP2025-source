#include <bits/stdc++.h>
using namespace std;
long long a[1000001];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int l, h, b;
	cin >> l >> h;
	long long z = l * h;
	cin >> a[1];
	long long m = a[1];
	for (int i = 2; i <= z; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + z + 1);
	for (int j = 1; j <= z; j++) {
		if (a[j] == m)
			b = j;
	}
	int tl = b / h;
	if (tl % 2 != 0) {
		int th1 = b - h * (tl - 1);
		cout << tl << " " << th1;
	} else {
		int th2 = b - (tl - 1) * h;
		int th3 = b - th2;
		cout << tl << " " << th3;
	}
	return 0;
}
