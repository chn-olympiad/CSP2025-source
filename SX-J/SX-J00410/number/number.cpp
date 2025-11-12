#include <bits/stdc++.h>
using namespace std;
int a[1000005], k, n;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int s, i = 1;
	cin >> s;
	while (s > 0) {
		a[i] = s % 10;
		s = s / 10;
		i++;
		n++;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i + 1] > a[i]) {
			k = a[i + 1];
			a[i + 1] = a[i];
			a[i] = k;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << a[i];
	}
	return 0;
}