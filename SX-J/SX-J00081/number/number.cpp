#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	char a[1000050];
	int s = 0, c = 0;
	cin >> a;
	for (int i = 1; i <= strlen(a); i++) {
		if (a[i] != '0' || a[i] != '1' || a[i] != '2' || a[i] != '3' || a[i] != '4' || a[i] != '5' || a[i] != '6'
		        || a[i] != '7' || a[i] != '8' || a[i] != '9') {
			for (int i = 1; i <= strlen(a) - 1; i++) {
				a[i] = a[i + 1];
			}
			c++;
		}
	}
	sort(a - '0', a - '0' + strlen(a) - c);
	for (int i = 1; i <= strlen(a) - c; i++) {
		a[i] = a[i] - '0';
	}
	for (int i = 1; i <= strlen(a) - c; i++) {
		cout << a[i] - '0';
	}
	return 0;
}