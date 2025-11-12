#include <bits/stdc++.h>
using namespace std;
int asd = 0;
int a[1000010];

int main () {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int e, f;
	int n, m;
	cin >> n >> m;
	int s = n * m;
	for (int i = 1; i <= s; i++) {
		cin >> a[i];

	}
	e = a[1];
	for (int i = 1; i <= s; i++) {
		for (int j = 1; j <= s; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
	for (int i = 0; i <= asd; i++) {
		if (e != a[i]) {
			asd++;
		}
	}
	if (asd  % n != 0) {
		cout << asd / n + 1 << " ";
	} else {
		cout << asd / n << " ";
	}
	if (asd  % m != 0) {
		f = asd / m + 1 ;
	} else {
		f = asd / m;
	}
	if (f % 2 == 0) {
		cout << 1 + m - asd % m ;
	} else if (f % 2 == 1) {
		if (asd % m != 0) {
			cout << asd % m;
		} else {
			cout << m;
		}

	}
	return 0;
}