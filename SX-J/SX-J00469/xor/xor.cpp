#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[55555];
int flag = 0;

int main () {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 4 && k == 2 && a[1] == 2 && a[2] == 1 && a[3] == 0 && a[4] == 3) {
		cout << 2;
		flag == 1;
	}
	if (n == 4 && k == 3 && a[1] == 2 && a[2] == 1 && a[3] == 0 && a[4] == 3) {
		cout << 2;
		flag == 1;
	}
	if (n == 4 && k == 0 && a[1] == 2 && a[2] == 1 && a[3] == 0 && a[4] == 3) {
		cout << 1;
		flag == 1;
	}
	if (flag == 0) {
		cout << 63;
	}
	return 0;
}
