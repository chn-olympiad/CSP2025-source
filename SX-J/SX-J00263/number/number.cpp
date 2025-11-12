#include <bits/stdc++.h>
using namespace std;
int b[10];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	char a;
	while (cin >> a) {
		if (a >= '0' && a <= '9') {
			int t = (int)a - (int)'0';
			b[t]++;
		}
	}
	for (int j = 1; j <= 9; j++) {
		for (int i = 1; i <= b[j]; i++) {
			cout << j;
		}
	}
	return 0;
}
