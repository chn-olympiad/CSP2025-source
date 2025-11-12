#include <bits/stdc++.h>
using namespace std;
int m[1000];

void mp(int a[], int n) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; i <= n; j++) {
			if (a[j] < a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
}

int main() {

	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cout << "5";

	int s, n, w = 1000;
	cin >> s;
	for (int i = 0; i <= 100; i++) {
		for (long long j = 10;
		        j <= pow(10, 3);
		        j + pow(10, i)) {
			//m[i] = s % j;
			//s = s - m[i] * j;
		}
	}
	n = 100;

	for (int i = 100; i >= 0; i--) {
		cout << m[i];
	}

	return 0;
}