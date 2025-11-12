#include <bits/stdc++.h>
using namespace std;
int a[100010];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, num = 0, c, r;
	cin >> n >> m;
	int sum = n * m;
	for (int i = 1; i <= sum; i++) {
		cin >> a[i];
	}
	int t = a[1];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= sum; i++) {
		if (a[i] < t) {
			num++;
		}
	}
	num = sum - num;
	if (num % n == 0) {
		c = num / n;
		r = n;
	} else {
		c = 1 + num / n;
		if (c % 2 == 1) {
			r = num % n;
		} else {
			r = n + 1 - num % n;
		}
	}
	cout << c << " " << r;
	return 0;
}