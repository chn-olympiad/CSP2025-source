#include <bits/stdc++.h>
using namespace std;
int n;
int c[5005];

int changdu(int c[i]) {
	int x, d;
	for (int i = 1; i <= n; i++) {
		if (c[i] < c[i + 1]) {
			c[i] = c[i + 1];
			int d = c[1];
		}
		c[i] = c[i] + c[i + 1];

		x = c[i];
	}
	if (x / d > 2)
		return x;
}

int main () {
	int sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c);

		changdu(c[i]);
		sum++;
	}
	cout << sum;
	return 0;
}