#include <bits/stdc++.h>
using namespace std;

int main() {
	//feropen ("number.in", "r", stdin);
	//feropen ("number.out", "w", stdout);
	char a[10000000], n[10000000], ans = 0;
	for (int i = 1; i <= 100; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= 10000000; i++) {
		if (i >= 'a' || i <= 'z') {

		} else if (i >= 'A' || i <= 'z') {

		} else {
			n[i] = a[i];
		}
	}
	for (int i = 1; i <= 1000000; i++) {
		for (int j = 1; j <= 100000000; j++) {
			if (n[j] > ans) {
				ans = n[j];
			}
		}
		cout << ans;
	}
}
