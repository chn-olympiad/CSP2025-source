#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen(" number.in", "r", stdin);
	freopen(" number.out", "w", stdout);
	char s[1000005];
	cin >> s;
	int n = 0;
	int len = strlen(s);
	int a[len + 5];
	for (int i = 0; i < len; i++) {
		if (s[i] < 'a') {
			a[n] = s[i] - 48;
			n++;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] < a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i];
	}
	return 0;
}