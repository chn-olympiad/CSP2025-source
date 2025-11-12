#include <bits/stdc++.h>
using namespace std;

int a[10000], b[10000];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, sum, c = 0;
	bool f;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = 2 * i;
	}
	if (n <= 3) {
		for (int i = 1; i <= n; i++)
			printf("%d ", a[i]);
		return 0;
	} else {
		for (int i = 3; i <= n; i++) {
			for (int j = 1; j <= i - 2; j++) {
				sum = 0;
				sum += a[j] + a[j + 1];
				for (int k = j + 2; k <= i; k++) {
					sum += a[k];
					if (sum > b[i]) {
						c++;
					}
				}
			}
		}
	}
	cout << c;
	return 0;
}