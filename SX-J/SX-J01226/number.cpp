#include <bits/stdc++.h>
using namespace std;
int s[10], a[10], n, b[10];


int main() {




	cin >> n;
	for (int i = 0; i <= 10; i++) {
		cin >> s[i];

	}




	for (int i = 0; i <= 10; i++) {
		if (s[i] == 0 || s[i] == 1 || s[i] == 2 || s[i] == 3 || s[i] == 4 || s[i] == 5 || s[i] == 6 || s[i] == 7 || s[i] == 8
		        || s[i] == 9) {
			s[i] = a[i];
		} else {
			s[i] = 0;
		}
	}

	for (int i = 1; i <= 10; i++) {
		if (a[i] > a[i - 1]) {
			a[i] = b[i];
			a[i - 1] = a[i];
			b[i] = a[i - 1];
		}
	}

	for (int i = 0; i <= 10; i++) {
		cout << s[i];
	}
	freopen("number.in", "r", stdin);
	freopen("number.ont", "w", stdout);
	return 0;
}
