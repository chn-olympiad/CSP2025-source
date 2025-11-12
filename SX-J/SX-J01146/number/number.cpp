#include <bits/stdc++.h>
using namespace std;
int n;
char a[1000000];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	n = 1000000;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != '0' && a[i] != '1' && a[i] != '2' && a[i] != '3' && a[i] != '4' && a[i] != '5' && a[i] != '6' && a[i] != '7'
		        && a[i] != '8' && a[i] != '9')
			a[i] = 0;
	}
	sort(a + 1, a + n + 1);
	for (int i = n; i >= 1; i--) {
		cout << a[i];
	}
	return 0;
}
