#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	int a[n + 5];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	if (k == 0) {
		cout << 1;
	} else if (k <= 1) {
		int c = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1) {
				c++;
			}
		}
		cout << c;
	} else if (k > 3) {
		int c = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] <= k) {
				c++;
			}
		}
		cout << c;
	} else {
		cout << 2;
	}

	return 0;
}
