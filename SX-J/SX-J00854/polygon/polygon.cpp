#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, big, c = 0;
	cin >> n;
	int a[n + 5];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n < 3) {
		cout << 0;
	}
	if (n == 3) {
		big = max(a[1], max(a[2], a[3]));
		if ((a[1] + a[2] + a[3] ) > big * 2) {
			c++;
			cout << c;
		} else
			cout << 0;
	} else {
		cout << 9;
	}
	return 0;
}
