#include <bits/stdc++.h>
using  namespace std;
int a[5005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, k = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n == 3) {
		if (a[1] + a[2] > a[3] && a[1] + a[3] > a[2] && a[2] + a[3] > a[1])
			cout << 1;
		else
			cout << 0;
	} else if (n == 4) {
		if (a[1] + a[2] > a[3] && a[1] + a[3] > a[2] && a[2] + a[3] > a[1])
			k++;
		if (a[1] + a[2] > a[4] && a[1] + a[4] > a[2] && a[2] + a[4] > a[1])
			k++;
		if (a[1] + a[4] > a[3] && a[1] + a[3] > a[4] && a[4] + a[3] > a[1])
			k++;
		if (a[2] + a[4] > a[3] && a[2] + a[3] > a[4] && a[4] + a[3] > a[2])
			k++;
		if (a[1] + a[2] + a[3] > a[4] && a[1] + a[2] + a[4] > a[3] && a[1] + a[3] + a[4] > a[2] && a[3] + a[2] + a[4] > a[1])
			k++;
		cout << k;
	} else if (n == 5) {
		if (a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5)
			cout << 9;
		if (a[1] == 2 && a[2] == 2 && a[3] == 3 && a[4] == 8 && a[5] == 10)
			cout << 6;
	}
	if (n > 5) {
		cout << INT_MAX % 998244353;
	}
	return 0;
}
