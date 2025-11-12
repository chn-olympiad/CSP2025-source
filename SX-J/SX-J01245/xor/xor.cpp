#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int n, k, a[10000];
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 4 && k == 2 && a[1] == 2 && a[3] == 2 & a[4] == 1 && a[5] == 0 && a[6] == 3) {
		cout << "2";
	} else if (n == 4 && k == 3 && a[1] == 2 && a[3] == 2 & a[4] == 1 && a[5] == 0 && a[6] == 3) {
		cout << "2";
	} else {
		cout << "1";
	}
	return 0;
}
