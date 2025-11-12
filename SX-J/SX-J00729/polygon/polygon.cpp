#include <bits/stdc++.h>
using namespace std;

int jz(int x, int b[5000]) {
	int jz1 = INT_MIN;
	for (int i = 1; i <= x; i++) {
		if (b[i] >= jz1) {
			jz1 = b[i];
		}
	}
	return jz1;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, sum = 0;
	cin >> n;
	int a[n + 3];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 3; i <= n; i++) {
		long long asdf = 0;
		for (int j = 1; j <= n - 2; j++) {
			for (int k = 1; k <= j; k++) {
				asdf += a[j];
				if (jz(k, a) * 2 <= asdf) {
					sum++;
				}
			}
		}
	}
	cout << sum + a[1];
	return 0;
}