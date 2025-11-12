#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;


bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	int n, m, z, a1, p, n1;
	cin >> m >> n;
	z = n * m;
	int a[z + 5];
	for (int i = 1; i <= z; i++) {
		cin >> a[i];
	}
	a1 = a[1];
	sort(a + 1, a + z + 1, cmp);
	for (int i = 1; i <= z; i++) {
		if (a[i] == a1) {
			p = i;
		}
	}
	n1 = (p - 1) / n + 1;
	if (n1 % 2 == 1) {
		cout << n1 << " " << p - m*(n1 - 1);
	} else {
		cout << n1 << " " << p % n1 + 1;
	}
	return 0;
}
