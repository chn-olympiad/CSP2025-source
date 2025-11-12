#include <bits/stdc++.h>
using namespace std;
int y[10000000];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	cin >> a;
	int lj = 0, b = a.size();
	for (int m = 0; m < b; m++) {
		if (a[m] >= '0' && a[m] <= '9') {
			y[lj] = int(a[m]) - int('0');
			lj++;
		}
	}
	sort(y, y + lj);
	for (int m = lj - 1; m >= 0; m--) {
		cout << y[m];
	}
	cout << endl;
	return 0;
}