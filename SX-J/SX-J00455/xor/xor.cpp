#include <bits/stdc++.h>
using namespace std;
int a[1000];


int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k, f = 1, s = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > 1) {
			f = 0;
		}
	}
	if (f == 1) {
		if (k == 0) {
			for (int i = 1; i <= n; i++) {
				if (a[i] == 0) {
					s++;
				} else if (a[i + 1] == 1) {
					s++;
					i++;
				}
			}
			cout << s;
		} else {
			for (int i = 1; i <= n; i++) {
				if (a[i] == 1) {
					s++;
				}
			}
			cout << s;
		}
	}
	return 0;
}
