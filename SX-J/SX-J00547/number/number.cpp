#include <bits/stdc++.h>
using namespace std;
char a[1005];
int n = 1000000;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i] == '0' || a[i] == '1' || a[i] == '2' || a[i] == '3' || a[i] == '4' || a[i] == '5' || a[i] == '6'
			        || a[i] == '7' || a[i] == '8' || a[i] == '9') {
				a[j] = a[i];
			}
			if (a[j] > a[j - 1]) {
				a[j - 1] = a[j];
			}
			cout << a[j];
		}
	}
	return 0;
}
