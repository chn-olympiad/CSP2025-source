#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, sum = 0, a[100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum = a[i] + sum;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
	if (2 * a[0] > sum)
		cout << 1;
	return 0;
}