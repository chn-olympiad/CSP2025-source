#include <bits/stdc++.h>
using namespace std;
#define int long long
char a[1000006];
int b[1000006];

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int l = 0, j = 0, c = 0;
	for (int i = 0; i <= 1000005; i++) {
		cin >> a[i];
	}
	l = strlen(a);
	for (int i = 0; i < l; i++) {
		if (a[i] <= '0' || a[i] >= '0') {
			b[j] = a[i] - '0';
			j++;
		}
		for (int k = i + 1; k <= j; k++) {
			if (c < b[k]) {
				swap(b[k], c);
			}
		}
		cout << b[i];
	}
	return 0;
}
