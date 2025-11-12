#include <bits/stdc++.h>
using namespace std;
char s[101];
char a[101];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int i = 0, j = 0;
	while (i <= 101) {
		if (s[i] <= '9' && s[i] >= '0') {
			a[j] = s[i];
			j++;
		}
		i++;
	}
	for ( i = 0; i < j; i++) {
		if (a[i] < a[i + 1]) {
			int h = a[i];
			a[i] = a[i + 1];
			a[i + 1] = h;
		}
	}
	for ( i = 0; i < j; i++) {
		cout << a[i];
	}
	return 0;
}
