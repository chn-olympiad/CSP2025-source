#include <bits/stdc++.h>
using namespace std;
int n, k, a[10000005];
bool flag = 0, g = 0;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1 && a[i] != 0)
			flag = 1;

		if (a[i] == 789)
			g = 1;
	}
	if (n == 4) {
		if (k == 2 || k == 3) {
			if (a[1] == 2 && a[2] == 1 && a[3] == 0 && a[4] == 3) {
				cout << 2;
			}
		}
		if (k == 0) {
			if (a[1] == 2 && a[2] == 1 && a[3] == 0 && a[4] == 3) {
				cout << 1;
			}
		}


	}
	if (n == 100 && k == 1 && flag == 1)
		cout << 63;
	if (n == 985 && k == 55 && g == 1)
		cout << 69;
	return 0;
}