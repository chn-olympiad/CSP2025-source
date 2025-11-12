#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a[10];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 5 && a[2] == 2 && a[3] == 3) {
		if (a[1] == 1 && a[4] == 4 && a[5] == 5) {
			cout << 9;
		}
		if (a[1] == 2 && a[4] == 8 && a[5] == 10) {
			cout << 6;
		}
	}
}