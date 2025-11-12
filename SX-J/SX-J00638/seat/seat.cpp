#include <bits/stdc++.h>
using namespace std;
int a[110];

int main() {
	int b, d, n, m, c, r;
	cin >> n >> m;
	b = n * m;
	for (int i = 1; i <= b; i++) {
		cin >> a[110];
	}
	d = a[1];
	c = d % 10;
	r = d / 10;
	cout << c << r;
	return 0;
}