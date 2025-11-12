#include <bits/stdc++.h>
using namespace std;
int a[5005];
int n, sum = 0, b = 0, ma = INT_MIN;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 2; i <= n + 1; i++) {
		for (int j = 1; j <= n; j++) {
			for (int y = j; y <= i; y++) {
				ma = max(ma, a[y]);
				b += a[y];
			}
			if (b > ma * 2) {
				sum++;
			}
			b = 0;
			ma = INT_MIN;

		}
	}
	cout << sum;
	return 0;
}
