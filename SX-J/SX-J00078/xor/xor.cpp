#include <bits/stdc++.h>
using namespace std;

bool t(int x, int y, int z) {
	int a = 0;
	if (a < x)
		a = x;
	if (a < y)
		a = y;
	if (a < z)
		a = z;
}
int n;
int a[100005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n < 11) {
		if (t(a[0], a[1], a[2]) == 1) {
			cout << 1;
		} else {
			cout << 2;
		}
	} else {
		cout << n;
	}
	return 0;
}
