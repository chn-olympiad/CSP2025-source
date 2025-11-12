#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	char a[1000005];
	int b[1005];
	for (int i = 0; i < 1000005; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 1000005; i++) {
		if (a[i] >= 67) {
			continue;
		} else {
			b[i] = a[i];
		}
	}
	for (int i = 0; i < 1005; i++) {
		for (int j = 0; j < i - 1; j++) {
			if (b[j] > b[j - 1]) {
				swap(b[j], b[j - 1]);
			}
		}
	}
	for (int i = 0; i < 1005; i++) {
		cout << b[i];
	}
	return 0;
}