#include <bits/stdc++.h>
using namespace std;

#define  int long long
int a[20];

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string  c;
	cin >> c;
	long long  l = c.size();
	for (int i = 0; i < l; i++) {
		if (c[i] <= '9' && c[i] >= '0') {
			a[c[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= a[i]; j++) {
			cout << i;
		}
	}
	return 0;
}
