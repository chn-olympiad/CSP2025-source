#include <bits/stdc++.h>
using namespace std;
string s;
char a[1000010], ans, b;

int main() {
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[i] = s[i];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i] > a[j]) {
				b = a[j];
				a[j] = a[i];
				a[i] = b;
			}
		}
	}
	for (int i = 0; i <= n - 1; i++) {
		cout << a[i];
	}
	return 0;
}
