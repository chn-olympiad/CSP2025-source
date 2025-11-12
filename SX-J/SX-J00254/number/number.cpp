#include <bits/stdc++.h>
using namespace std;
char a[100010];
long long len = 0;
long long c[20];

int main() {
	memset(c, 0, sizeof(c));
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin.getline(a, 100010);
	for (int i = 0;; i++) {
		if (a[i] != 0) {
			len++;
		} else
			break;
	}
	for (int i = 0; i < len; i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			c[int(a[i]) - 48]++;
		}
	}

	for (int i = 9; i >= 0; i--) {
		if (c[i] != 0) {
			for (int j = 0; j < c[i]; j++) {
				cout << i;
			}
		}

	}

	return 0;
}
