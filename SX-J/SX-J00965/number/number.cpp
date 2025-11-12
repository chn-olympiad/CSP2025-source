#include <bits/stdc++.h>
using namespace std;
char a[1000005];
int x[1000005];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	int len = strlen(a);
	memset(x, -1, sizeof(x));
	for (int i = 0; i < len; i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			x[i] = a[i] - '0';
		}
	}
	sort(x, x + len + 1);
	for (int i = len; i > 0; i--) {
		if (x[i] > -1) {
			cout << x[i];
		}
	}
	return 0;
}
