#include <bits/stdc++.h>
using namespace std;
long long  s, num = 0, b[10000005];
char a[10000005];

main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	int l = strlen(a);
	for (int i = 0; i <= l; i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			b[i] = a[i];
			b[i] %= 48;
			num++;
		}
	}
	sort(b, b + l + 1);
	for (int i = l - 1; i >= l - num ; i--) {
		cout << b[i];
	}
	return 0;
}
