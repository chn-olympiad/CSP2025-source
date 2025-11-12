#include <bits/stdc++.h>
using namespace std;
char a[1000001];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string b;
	char e;
	int c, d = 0;
	cin >> b;
	c = b.size();
	for (int i = 0; i <= c - 1; i++) {
		if (b[i] >= '0' && b[i] <= '9') {
			a[d] = b[i];
			d += 1;
		}
	}
	for (int i = 1; i <= d - 1; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i]) {
				e = a[j];
				a[j] = a[i];
				a[i] = e;
				i = 1;
			}
		}
	}
	for (int i = 0; i <= d - 1; i++) {
		cout << a[i];
	}
	return 0;
}
