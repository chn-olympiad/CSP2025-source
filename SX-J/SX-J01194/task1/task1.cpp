#include <bits/stdc++.h>
using namespace std;
string a;
int c[100000];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	int b = a.size();
	for (int i = 0; i <= b - 1; i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			c[i] = a[i] - '0';
		}

	}
	sort(c, c + b);
	for (int i = b; i >= 0; i--) {
		if (c[i] != 0) {
			cout << c[i];
		}
	}


	return 0;
}
