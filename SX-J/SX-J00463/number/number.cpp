#include <bits/stdc++.h>
using namespace std;
int bb[10000005];

int main() {
	freopen("number.in", "r", "stdin");
	freopen("number.out", "w", "stdout");
	string a;
	cin >> a;
	int i, cc = 0;
	for (i = 0; i <= a.size(); i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			bb[i] = a[i] - 48;
			cc++;
		}
	}
	sort(bb + 0, bb + cc + 0);
	for (i = cc - 1; i >= 0; i--) {
		cout << bb[i];
	}
	return 0;
}
